#include "opAddirrPol.h"
#include "..//Shapes/IrregularPolygon.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "operation.h"
#include <string>
#include <iostream>


opAddirrPol::opAddirrPol(controller* pCont) :operation(pCont)
{}
opAddirrPol:: ~opAddirrPol()
{}

//Execute the operation

void opAddirrPol::Execute()
{
	vector<Point> arrayofpoints;
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Irregular polygon: enter the number of sides you want: ");
	string theNmber = pUI->GetSrting();
	int NUM = stoi(theNmber);
	for (int i = 0; i < NUM; i++)
	{
		Point P;
		string msg = " Click at a corner" + to_string(i+1) + " )";;
		pUI->PrintMessage(msg);
	
		pUI->GetPointClicked(P.x, P.y);
		arrayofpoints.push_back(P);
	}

	pUI->ClearStatusBar();


	GfxInfo polyGfxInfo;

	//get drawing, filling colors and pen width from the interface
	polyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	polyGfxInfo.FillClr = pUI->getCrntFillColor();
	if (pUI->checkborder() == true)

		polyGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	else
		polyGfxInfo.BorderWdth = 3;

	polyGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Triangle with the above parameters
	IrregularPolygon*  pol= new IrregularPolygon(arrayofpoints, polyGfxInfo);

	//Get a pointer to the graph
	Graph* POL = pControl->getGraph();

	
	POL->Addshape(pol);

}