#include "opGroup.h"
#include "..//controller.h"
#include "operation.h"
#include <string>
#include "Select.h"
#include "..//Shapes/Groupshape.h"
#include <vector>

opGroup::opGroup(controller* pCont) :operation(pCont)
{}
opGroup :: ~opGroup()
{}

void opGroup::Execute()
{

	GUI* pUI = pControl->GetUI();

	Graph* pGraph = pControl->getGraph();

	int IDOfgroup;

	pUI->PrintMessage("Enter an Id for this group ");

	IDOfgroup = stoi(pUI->GetSrting());
	int* p = &IDOfgroup;

	pGraph->groupthisShapes(p);

	pUI->PrintMessage("You created a group with Id number "+ IDOfgroup);

	pUI->ClearStatusBar();


}