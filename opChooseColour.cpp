#include "operations/opChooseColour.h"
#include "controller.h"
#include "operations/operation.h"
#include "CMUgraphicsLib/colors.h"
#include "Shapes/Shape.h"

opChooseColour::opChooseColour(controller* pCont) : operation(pCont)
{}

opChooseColour ::~opChooseColour()
{}


void opChooseColour::Execute()
{

	int X, Y;
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Click on the colour U want ");
	pUI->GetPointClicked(X, Y);
	pUI->GetColourPallete(X,Y);
	pUI->ClearStatusBar();
}
