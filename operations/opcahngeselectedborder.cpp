
#include "opCahngeSelectedBorder.h"
#include "opAddirrPol.h"
#include "..//Shapes/IrregularPolygon.h"
#include "..//Shapes/Shape.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "..//Shapes/Graph.h"
#include "operation.h"

#include "..\Shapes\Graph.h"
	opChangeBorderSelected::	opChangeBorderSelected(controller* pCont) :operation(pCont)
{}


void 	opChangeBorderSelected::ReadActionParameters() {
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGUI->PrintMessage("Selected shape to change the border color  ");
}

//Execute the action
void 	opChangeBorderSelected::Execute()
{
	ReadActionParameters();
	Graph* pGr = pControl->getGraph();
	int X, Y;
	GUI* pUI = pControl->GetUI();
	pUI->CreateColourToolBar();
	pUI->GetPointClicked(X, Y);
	pUI->GetColour(X, Y);
	pUI->back();
	pGr->opChangeSelectedBorder(pUI->GetColour(X,Y));
	


}

