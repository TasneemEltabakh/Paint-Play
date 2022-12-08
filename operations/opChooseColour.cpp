#include "opChooseColour.h"
#include "..//controller.h"
#include "operation.h"
#include "..//CMUgraphicsLib/colors.h"
#include"..//Shapes/Shape.h"

opChooseColour::opChooseColour(controller* pCont) : operation(pCont)
{}

opChooseColour ::~opChooseColour()
{}


void opChooseColour::Execute()
{

	int X, Y;
	GUI* pUI = pControl->GetUI();
	pUI->CreateColourToolBar();
	pUI->GetPointClicked(X, Y);
	pUI->GetColourPallete(X,Y);
	pUI->back();
	pUI->ClearStatusBar();
}
