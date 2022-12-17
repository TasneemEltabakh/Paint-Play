#include "opAddSquare.h"
#include  "..//Shapes/Shape.h"
#include "..//Shapes/Square.h"
#include "..//controller.h"
#include "..//GUI/GUI.h"

opAddSquare::opAddSquare(controller* pCont) :operation(pCont)
{}
opAddSquare::~opAddSquare()
{}

//Execute the operation
void opAddSquare::Execute()
{
	Point P1, P2;
	int i;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Enter the side ";
	pUI->PrintMessage(msg);
	////Read 2nd corner and store in point P2
	//pUI->GetPointClicked(P2.x, P2.y);
	//pUI->ClearStatusBar();
	////// me to get the side  
	string theside = pUI->GetSrting();
	int NUM = stoi(theside);
	i = NUM;

	//Preapre all Square parameters
	GfxInfo SquareGfxInfo;

	//get drawing, filling colors and pen width from the interface
		//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	SquareGfxInfo.isSelected = false;	//defualt is not selected

	if (pUI->checkfill() == true)
	{
		if (SquareGfxInfo.isSelected == true)

			SquareGfxInfo.FillClr = pUI->getCrntFillColor();
		else
			SquareGfxInfo.FillClr = pUI->getoldFillColor();
	}
	else
		SquareGfxInfo.isFilled = false;

	if (pUI->checkborder() == true)
	{
		if (SquareGfxInfo.isSelected == true)
			SquareGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	}
	else
		SquareGfxInfo.BorderWdth = pUI->getoldPenWidth();

	if (pUI->checkcol() == true)
	{
		if (SquareGfxInfo.isSelected == true)
			SquareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	}
	else
		SquareGfxInfo.DrawClr = pUI->getoldDrawColor();



	//Create a Square with the above parameters
	Square* S = new Square(P1, i, SquareGfxInfo);
	

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Square to the list of shapes
	pGr->Addshape(S);

}
