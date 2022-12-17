#include "opAddTriangle.h"
#include "../Shapes/Triangle.h"
#include "../controller.h"
#include "../GUI/GUI.h"

opAddTriangle ::opAddTriangle(controller* pCont) :operation(pCont)
{}
opAddTriangle:: ~opAddTriangle()
{}

//Execute the operation

void opAddTriangle::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);

	msg += " ... Click at Third corner";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(P3.x, P3.y);

	pUI->ClearStatusBar();

	//Preapre all Triangle parameter
	GfxInfo TriangleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	TriangleGfxInfo.isSelected = false;	//defualt is not selected

	if (pUI->checkfill() == true)
	{
		if (TriangleGfxInfo.isSelected == true)

			TriangleGfxInfo.FillClr = pUI->getCrntFillColor();
		else
			TriangleGfxInfo.FillClr = pUI->getoldFillColor();
	}
	else
		TriangleGfxInfo.isFilled = false;

	if (pUI->checkborder() == true)
	{
		if (TriangleGfxInfo.isSelected == true)
			TriangleGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	}
	else
		TriangleGfxInfo.BorderWdth = pUI->getoldPenWidth();
	
	if (pUI->checkcol() == true)
	{
		if (TriangleGfxInfo.isSelected == true)
			TriangleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	}
		else
			TriangleGfxInfo.DrawClr = pUI->getoldDrawColor();
	

	//Create a Triangle with the above parameters
	Triangle* T = new Triangle(P1, P2, P3,  TriangleGfxInfo);

	//Get a pointer to the graph
	Graph* TR = pControl->getGraph();

	//Add the Triangle to the list of shapes
	TR->Addshape(T);

}