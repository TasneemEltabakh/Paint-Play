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
	string choice;
	Graph* pGraph = pControl->getGraph();

	int IDOfgroup;

	pUI->PrintMessage("do you want to group or ungroup: to group press g ");
	
	choice = pUI->GetSrting();
	int* p = nullptr;

	pUI->PrintMessage("Enter an Id for this group ");
	IDOfgroup = stoi(pUI->GetSrting());
	p = &IDOfgroup;

	while (pGraph->isInIds(p))
	{
		pUI->PrintMessage("you have already another group with the same Id, enter another one please ");
		IDOfgroup = stoi(pUI->GetSrting());
		p = &IDOfgroup;
		pGraph->isInIds(p);
	}

	if (choice == "g" || choice == "G")
	{
		pGraph->groupthisShapes(p);

		pUI->PrintMessage("You created a group with Id number " + IDOfgroup);

		pUI->ClearStatusBar();
	}
	else
		pGraph->Ungroup(p);

	pUI->ClearStatusBar();

}
	
