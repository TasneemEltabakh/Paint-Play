#pragma once
#include "opAddLine.h"
#include "..//Shapes/Line.h"
#include "..//controller.h"
#include "..//GUI/GUI.h"
opAddLine::opAddLine(controller* pCont) :operation(pCont)
{}
opAddLine  ::~opAddLine()
{}

//Execute the operation
void opAddLine::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line  : Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();


	//Preapre all Line  parameters
	GfxInfo lineGfxInfo;


	lineGfxInfo.isFilled = false;	//default is not filled
	lineGfxInfo.isSelected = false;
	//get drawing, filling colors and pen width from the interface
	if (pUI->checkborder() == true)
	{
		if (lineGfxInfo.isSelected == true)
			lineGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	}
	else
		lineGfxInfo.BorderWdth = pUI->getoldPenWidth();

	if (pUI->checkcol() == true)
	{
		if (lineGfxInfo.isSelected == true)
			lineGfxInfo.DrawClr = pUI->getCrntDrawColor();
	}
	else
		lineGfxInfo.DrawClr = pUI->getoldDrawColor();


	//defualt is not selected


	//Create a circle with the above parameters
	Line* O = new Line(P1, P2, lineGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the circle to the list of shapes
	pGr->Addshape(O);

}