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
	vector <shape*> mygroup;

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	string nameOfgroup;
	pUI->PrintMessage("Enter The name of this group ");
	nameOfgroup = pUI->GetSrting();
	pUI->PrintMessage("start selection of your group ");
	int num =3;
	for (int i = 0; i < 3; i++)
	{
		mygroup.push_back(pGraph->getselectedShape());
	}
	GfxInfo groupShape;
	groupShape.isFilled = false;	//default is not filled

	groupshape* groupi = new groupshape(mygroup, groupShape, num);

	//Get a pointer to the graph
	Graph* groupgraph = pControl->getGraph();

	//Add the Triangle to the list of shapes
	groupgraph->Addshape(groupi);

}