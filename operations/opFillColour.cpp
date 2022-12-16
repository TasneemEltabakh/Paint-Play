#include "..//operations/opFillColour.h"
#include "..//controller.h"
#include "..//operations/operation.h"
#include "..//CMUgraphicsLib/colors.h"
#include"..//Shapes/Shape.h"


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
	pUI->GetIsFilled();
	pUI->FillColour(X, Y);
	pUI->back();
	

	
}
