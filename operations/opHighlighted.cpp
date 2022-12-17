#include "..//operations/opHighlighted.h"
#include "..//controller.h"
#include "..//operations/operation.h"
#include "..//CMUgraphicsLib/colors.h"
#include"..//Shapes/Shape.h"


opHighlighted::opHighlighted(controller* pCont) : operation(pCont)
{}

opHighlighted ::~opHighlighted()
{}


void opHighlighted::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->GetIsHighlited();
	pGr->Highlighting(pUI->highlightcol());
}

