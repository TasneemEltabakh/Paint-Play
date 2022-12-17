#include "opAddSquare2.h"
#include  "..//Shapes/Shape.h"
#include "..//Shapes/Square2.h"
#include "..//controller.h"	
#include "..//GUI/GUI.h"


opAddSquare2::opAddSquare2(controller* pCont) :operation(pCont)
{}
opAddSquare2::~opAddSquare2()
{}



//Execute the operation
void opAddSquare2::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Square parameters
	GfxInfo SquareGfxInfo;

	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SquareGfxInfo.FillClr = pUI->getCrntFillColor();
	if (pUI->checkborder() == true)

		SquareGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	else
		SquareGfxInfo.BorderWdth = 3; //default is not filled
	SquareGfxInfo.isSelected = false;	//defualt is not selected
	if (pUI->checkfill() == true)

		SquareGfxInfo.isFilled = true;

	else
		SquareGfxInfo.isFilled = false;



	//Create a Square with the above parameters
	Square2* S = new Square2(P1, P2, SquareGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Square to the list of shapes
	pGr->Addshape(S);

}
