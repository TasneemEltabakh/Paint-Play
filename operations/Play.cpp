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

bool Play::ReadActionParameters()
{
	return false;
}
void Play::dublicate() {
	
	pGraph->GDuplicate();
}

void Play::Scramble()  //Here the scrample function will put
{
	pGraph->Scramble();
}

void Play::hide() {

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
	shape1->SetSelected(true);  //I put this instead of unhide function
	//shape1->unhide(); 
	
	do {  //this handle if user click on free space
		pGUI->PrintMessage("Click at second shape");
		pGUI->GetPointClicked(P2.x, P2.y);
	} while (!pGraph->Getshape(P2.x, P2.y));
	shape2 = pGraph->Getshape(P2.x, P2.y);
	shape2->SetSelected(true);  //I put this instead of unhide function
	//shape1->unhide(); 


	pGUI->PrintMessage("get shapes should be ended here");  //Rghda put for test  I works
	this_thread::sleep_for(chrono::milliseconds(2500));  //this way finally work :D

	if (pGraph->matchgraph(shape1, shape2)) {
		rightAnswers = rightAnswers + 1;
		pGUI->PrintMessage("Successful, you get:"+ to_string(rightAnswers)+ " right and "+ to_string(wrongAnswers)+"wrong");
		this_thread::sleep_for(chrono::milliseconds(2500));  //this way finally work :D

		int size = pGraph->getvectorsize();
		//if (rightAnswers == (size / 2)) {
		if (size==0) {
			pGUI->PrintMessage("Finish, you get:" + to_string(rightAnswers) + " right and " + to_string(wrongAnswers) + "wrong");
			this_thread::sleep_for(chrono::milliseconds(2500));  //this way finally work :D
			pGraph->returnallshapesforplay();
			//return;
			//exit;
		}
		else {
			//pGUI->PrintMessage("I test if it comes here");  //Rghda put for test  I undestand what happened
			match();
		}
	}
	else {
		wrongAnswers = wrongAnswers + 1;
		pGUI->PrintMessage("Wrong one, try again, you get:" + to_string(rightAnswers) + " right and " + to_string(wrongAnswers) + "wrong");
		//delay(5000);
		//cout.flush();  //these ways didn't work
		//sleep(10);
		this_thread::sleep_for(chrono::milliseconds(2500));  //this way finally work :D
		match();
	}
}
void Play::StartGame() {
	
}
bool Play::restart(Point p) {
	//int x = p.x;  
	//int y = p.y;
	///*if (x >= 13 * 50 && x <= 15 * 50 && y >= 0 && y <= 50)   //Ishould here put the coorednates of restart
	//	if (x < 14 * 50)
	//		return true;*/
	//return false;
	pGraph->returnallshapesforplay(); 
	return false;

}
void Play::Execute() {
	//pGUI->PrintMessage("did it enter the execute for play?");  //this works
	//dublicate();
	//pGUI->PrintMessage("after dublicate");  //this works now

	//Scramble();
	//pGUI->PrintMessage("after scramble");  //this works now

	//match();
	//hide();
	//StartGame();
}
