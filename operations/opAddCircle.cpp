#include "opAddCircle.h"
#include "../Shapes/ciecle.h"
#include "..//controller.h"
#include "..//GUI/GUI.h"

opAddCircle::opAddCircle(controller* pCont) :operation(pCont)
{}
opAddCircle::~opAddCircle()
{}

//Execute the operation
void opAddCircle::Execute()
{
	Point P1, P2;
	int X, Y;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

/*
	pUI->PrintMessage("enter file name:");
	string s=pUI->GetSrting();
	pUI->PrintMessage("File name is " + s);
	pUI->GetPointClicked(P1.x, P1.y);
*/
	pUI->PrintMessage("New Circle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Circle parameters
	GfxInfo CircleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CircleGfxInfo.FillClr = pUI->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	

	if (pUI->checkfill() == true)
	
		CircleGfxInfo.isFilled = true;
	
	else 
		CircleGfxInfo.isFilled = false;

	CircleGfxInfo.isSelected = false;	//defualt is not selected


	//Create a circle with the above parametersb
	Circle* C = new Circle(P1, P2, CircleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the circle to the list of shapes
	pGr->Addshape(C);

}