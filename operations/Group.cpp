#include "Group.h"
#include "..//controller.h"
#include "operation.h"
#include <string>
#include "Select.h"


Group::Group(controller* pCont) :operation(pCont)
{}
Group :: ~Group()
{}

void Group::Execute()
{

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	string nameOfgroup;
	pUI->PrintMessage("Enter The name of this group ");
	nameOfgroup = pUI->GetSrting();
	pUI->PrintMessage("start selection of your group ");
	for (int i = 0; i < stoi(pGraph->numberofselectedshapes()); i++)
	{
		group.push_back(pGraph->getselectedShape());
	}

}