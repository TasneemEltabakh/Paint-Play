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
	GfxInfo g;
	
	GUI* pUI = pControl->GetUI();
	pUI->GetPointClicked(X, Y);
	pUI->GetColourPallete(X,Y);

	
}
