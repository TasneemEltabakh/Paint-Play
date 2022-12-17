#include "../Paint-Play/opFillColour.h"
#include "../Paint-Play/controller.h"
#include "../Paint-Play/operations/operation.h"
#include "../Paint-Play/CMUgraphicsLib/colors.h"
#include"Shapes/Shape.h"


opFillColour::opFillColour(controller* pCont) : operation(pCont)
{}

opFillColour ::~opFillColour()
{}


void opFillColour::Execute()
{

	int X, Y;
	GUI* pUI = pControl->GetUI();
	pUI->CreateColourToolBar();
	pUI->GetPointClicked(X, Y);
	pUI->FillColour(X,Y);
	pUI->back();
	pUI->ClearStatusBar();
}
