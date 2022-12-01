#include "opAddirrPol.h"
#include "..//Shapes/IrregularPolygon.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "operation.h"

opAddirrPol::opAddirrPol(controller* pCont) :operation(pCont)
{}
opAddirrPol:: ~opAddirrPol()
{}

//Execute the operation

void opAddirrPol::Execute()
{
	Point P1, P2, P3, P4, P5, P6;

	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Irregular polygon you have 6 points: Click at first corner");
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

	 msg = "Third corner is at (" + to_string(P3.x) + ", " + to_string(P3.y) + " )";
	msg += " ... Click at fourth corner";
	pUI->PrintMessage(msg);
	
	pUI->GetPointClicked(P4.x, P4.y); 
	 
	 msg = "fourth corner is at (" + to_string(P4.x) + ", " + to_string(P4.y) + " )";
	msg += " ... Click at fifth corner";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(P5.x, P5.y); 

	 msg = "fifth corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at last corner";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(P6.x, P6.y); 


	pUI->ClearStatusBar();


	GfxInfo polyGfxInfo;

	//get drawing, filling colors and pen width from the interface
	polyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	polyGfxInfo.FillClr = pUI->getCrntFillColor();
	polyGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	polyGfxInfo.isFilled = false;	//default is not filled
	polyGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Triangle with the above parameters
	IrregularPolygon*  pol= new IrregularPolygon(P1, P2, P3, P4 , P5, P6, polyGfxInfo);

	//Get a pointer to the graph
	Graph* POL = pControl->getGraph();

	
	POL->Addshape(pol);

}