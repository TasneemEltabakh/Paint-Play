#include "opSetPen.h"
#include "..//controller.h"
#include "operation.h"
#include "..//CMUgraphicsLib/colors.h"
#include"..//Shapes/Shape.h"

opSetPen::opSetPen(controller* pCont) : operation(pCont)
{}

opSetPen ::~opSetPen()
{}

void opSetPen::Execute()
{
	GUI* pUI = pControl->GetUI();
	int X, Y;
	pUI->GetPointClicked(X, Y);
	pUI->GetColourPallete(X, Y);
}
