#include "Play.h"

//#include <Windows.h>
//#include <Mmsystem.h>

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
	Point P1;
	Point P2;
	shape* shape1;
	shape* shape2;


	do{
		pGUI->PrintMessage("Click at first shape");
		pGUI->GetPointClicked(P1.x, P1.y);
		shape1 = pGraph->Getshape(P1.x, P1.y);
		shape1->SetSelected(true);  //I put this instead of unhide function
		//shape1->unhide(); 
	} while (!pGraph->Getshape(P1.x, P1.y));
	
	do {
		pGUI->PrintMessage("Click at second shape");
		pGUI->GetPointClicked(P2.x, P2.y);
		shape2 = pGraph->Getshape(P2.x, P2.y);
		shape2->SetSelected(true);  //I put this instead of unhide function
		//shape1->unhide(); 
	} while (!pGraph->Getshape(P2.x, P2.y));
	
	if (pGraph->matchgraph(shape1, shape2)) {
		rightAnswers = rightAnswers + 1;
		pGUI->PrintMessage("Successful, you get:"+ to_string(rightAnswers)+ " right and "+ to_string(wrongAnswers)+"wrong");
		int size = pGraph->getvectorsize();
		//if (rightAnswers == (size / 2)) {
		if (size==0) {
			pGUI->PrintMessage("Finish, you get:" + to_string(rightAnswers) + " right and " + to_string(wrongAnswers) + "wrong");
			pGraph->returnallshapesforplay();
			return;
		}
		else {
			match();
		}
	}
	else {
		wrongAnswers = wrongAnswers + 1;
		pGUI->PrintMessage("Wrong one, try again, you get:" + to_string(rightAnswers) + " right and " + to_string(wrongAnswers) + "wrong");
		match();
	}
}
void Play::StartGame() {
	
}
bool Play::restart(Point p) {
	int x = p.x;  
	int y = p.y;
	/*if (x >= 13 * 50 && x <= 15 * 50 && y >= 0 && y <= 50)   //Ishould here put the coorednates of restart
		if (x < 14 * 50)
			return true;*/
	return false;
}
void Play::Execute() {
	dublicate();
	Scramble();
	match();
	//hide();
	//StartGame();
}
Play::~Play()
{
}