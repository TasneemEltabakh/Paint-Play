#include "../Shapes/Shape.h"
#include "G:\Academic\CIE\C++\PAINTER\Paint-Play\operations\opAddRegPol.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "../Shapes/regularPolygon.h"
# include <iostream>

opAddRegPol::opAddRegPol(controller* pCont) : operation(pCont)
{}
opAddRegPol :: ~opAddRegPol()
{}
void opAddRegPol::Execute()
{
	Point P1, P2, P3;
    int NUM;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();


	pUI->PrintMessage("New polygon: Click at the center ");
	
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "Your center is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg = " ... please click at the start of the first side";
	pUI->PrintMessage(msg);

	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();
     msg = "Your first point is at (" + to_string(P2.x) + ", " + to_string(P2.y) + " )";


	msg += " please click at the end ";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(P3.x, P3.y);
    msg = "Your second point is at (" + to_string(P3.x) + ", " + to_string(P3.y) + " )";
	pUI->ClearStatusBar();


	msg += " what is the number of sides of this polygon";
	pUI->PrintMessage(msg);
	NUM = std::stoi(pUI->GetSrting());
	pUI->ClearStatusBar();

	GfxInfo polyGfxInfo;

	//get drawing, filling colors and pen width from the interface
	polyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	polyGfxInfo.FillClr = pUI->getCrntFillColor();
	polyGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	polyGfxInfo.isFilled = false;	//default is not filled
	polyGfxInfo.isSelected = false;	//defualt is not selected


	
	regularPolygon*  Poly = new regularPolygon (P1, P2, P3, NUM, polyGfxInfo);

	//Get a pointer to the graph
	Graph* Pol = pControl->getGraph();

	//Add the Triangle to the list of shapes
	Pol->Addshape(Poly);
}