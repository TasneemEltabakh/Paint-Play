#include "Play.h"
//#include <Windows.h>
//#include <Mmsystem.h>
//#include <unistd.h>

#include <iostream>
#include <chrono>  //These three for sleep line
#include <thread>


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
	//shape1->unhide(); 
	
	do {  //this handle if user click on free space
		pGUI->PrintMessage("Click at second shape");
		pGUI->GetPointClicked(P2.x, P2.y);
	} while (!pGraph->Getshape(P2.x, P2.y));
	shape2 = pGraph->Getshape(P2.x, P2.y);
	shape2->SetSelected(true);  
	//shape1->unhide(); 


	if (pGraph->matchgraph(shape1, shape2)) {
		pGraph->DeleteMatchedShapesGraph(false);
		pControl->UpdateInterface();   //Very very very important
		rightAnswers = rightAnswers + 1;

		pGUI->PrintMessage("Successful, you get:"+ to_string(rightAnswers)+ " right and "+ to_string(wrongAnswers)+"wrong");
		

		Sleep(1500);  //this way finally work :D
		

		int size = pGraph->getvectorsize();

		if (size==0) {
			pGUI->PrintMessage("Finish, you get:" + to_string(rightAnswers) + " right and " + to_string(wrongAnswers) + "wrong");
			Sleep(1500);  //this way finally work :D
			
		}
		else {
			match();
		}
	}
	else {
		wrongAnswers = wrongAnswers + 1;
		pGUI->PrintMessage("Wrong one, try again, you get:" + to_string(rightAnswers) + " right and " + to_string(wrongAnswers) + "wrong");
		Sleep(1500);  //this way finally work :D
		match();
	}
}
void Play::Execute() {

	match();
}

