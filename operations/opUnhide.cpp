#include "opUnhide.h"
#include "..//controller.h"
#include "operation.h"
#include <string>
#include "Select.h"
#include "..//Shapes/Groupshape.h"
#include <vector>
UnHide::UnHide(controller* pCont) :operation(pCont)
{}
UnHide :: ~UnHide()
{}

void UnHide::Execute()
{

	GUI* pUI = pControl->GetUI();
	Graph* pgraph = pControl->getGraph();
	pgraph->Unhide();
	pControl->UpdateInterface();

}