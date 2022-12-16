#pragma once
#include "opAddOval.h"
#include "..//Shapes/Oval.h"
#include "..//controller.h"
#include "..//GUI/GUI.h"

opAddOval ::opAddOval (controller* pCont) :operation(pCont)
{}
opAddOval ::~opAddOval ()
{}

//Execute the operation
void opAddOval ::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Oval : Click at The width point");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at the highst point";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();
	/*msg += " ... Click at third  corner";
	pUI->PrintMessage(msg);
	//Read 3rd corner and store in point P3
	pUI->GetPointClicked(P3.x, P3.y);
	pUI->ClearStatusBar();*/



	//Preapre all Oval parameters
	GfxInfo CircleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CircleGfxInfo.FillClr = pUI->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	if (pUI->checkfill() == true)

		CircleGfxInfo.isFilled = true;

	else
		CircleGfxInfo.isFilled = false; //default is not filled
	CircleGfxInfo.isSelected = false;	//defualt is not selected


	//Create a circle with the above parameters
    
	
	Oval * O = new Oval(P1, P2, CircleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the circle to the list of shapes
	pGr->Addshape(O);

}