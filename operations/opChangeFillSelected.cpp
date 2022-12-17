
#include"opChangeFillSelected.h"
#include "opAddirrPol.h"
#include "..//Shapes/IrregularPolygon.h"
#include "..//Shapes/Shape.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "..//Shapes/Graph.h"
#include "operation.h"

#include "..\Shapes\Graph.h"
opChangeFillSelected::opChangeFillSelected(controller* pCont) :operation(pCont)
{}


void opChangeFillSelected::ReadActionParameters() {
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGUI->PrintMessage("Selected shape is being filled");
}

//Execute the action
void opChangeFillSelected::Execute()
{
	ReadActionParameters();
	Graph* pGr = pControl->getGraph();
	int X, Y;
	GUI* pUI = pControl->GetUI();
	pUI->CreateColourToolBar();
	pUI->GetPointClicked(X, Y);
	pUI->back();
	pGr->changeFillSelection(pUI->FillselectedColour(X, Y));
}

