#include "Play.h"
//#include <Windows.h>
//#include <Mmsystem.h>
//#include <unistd.h>

#include <iostream>
#include <chrono>  //These three for sleep line
#include <thread>
#include "Scramble.h"
#include "hide.h"

Play::Play(controller* pCont) : operation(pCont)
{
}



void Play::match() {

	Point P1={0,0};
	Point P2={0,0};
	shape* shape1;
	shape* shape2;
	

	do{  //this handle if user click on free space
		pGUI->PrintMessage("Click at first shape");
		pGUI->GetPointClicked(P1.x, P1.y);
	} while (!pGraph->Getshape(P1.x, P1.y));
	shape1 = pGraph->Getshape(P1.x, P1.y);
	shape1->SetSelected(true); 
	pGraph->Unhide();
	pControl->UpdateInterface();
	Sleep(800);

	do {  //this handle if user click on free space
		pGUI->PrintMessage("Click at second shape");
		pGUI->GetPointClicked(P2.x, P2.y);
	} while (!pGraph->Getshape(P2.x, P2.y));
	shape2 = pGraph->Getshape(P2.x, P2.y);
	if (shape1 == shape2) {
		pGUI->PrintMessage("you pressed twoic on same shape, rechoose two  shapes again");
		Sleep(1500);
		pGraph->Hide();
		pControl->UpdateInterface();
		shape1->SetSelected(false);
		match();
	}
	shape2->SetSelected(true);  
	pGraph->Unhide();
	pControl->UpdateInterface();
	Sleep(800);

	if (pGraph->matchgraph(shape1, shape2)) {
		//pGraph->Unhide();
		//pControl->UpdateInterface();
		//Sleep(1000);
		pGraph->DeleteMatchedShapesGraph(false);
		pControl->UpdateInterface();   //Very very very important
		rightAnswers = rightAnswers + 1;

		pGUI->PrintMessage("Successful, you get:"+ to_string(rightAnswers)+ " right and "+ to_string(wrongAnswers)+"wrong");
		

		Sleep(1000);  //this way finally work :D
		

		int size = pGraph->getvectorsize();

		if (size==0) {
			pGUI->PrintMessage("Finish, you get:" + to_string(rightAnswers) + " right and " + to_string(wrongAnswers) + "wrong");
			Sleep(1000);  //this way finally work :D
			
		}
		else {
			match();
		}
	}
	else {
		pGraph->Hide();
		pControl->UpdateInterface();
		Sleep(1000);
		shape1->SetSelected(false);
		shape2->SetSelected(false);
		wrongAnswers = wrongAnswers + 1;
		pGUI->PrintMessage("Wrong one, try again, you get:" + to_string(rightAnswers) + " right and " + to_string(wrongAnswers) + "wrong");
		Sleep(800);
		//pGraph->Scramble();
		//Hide h(pControl);
		//h.Execute();
		match();
	}
}
void Play::Execute() {
	Hide h(pControl);
	Scramble H(pControl);
	H.Execute();
	h.Execute();
	match();
}

