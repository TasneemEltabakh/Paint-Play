#include "opCahangeSelectedWidth.h"
#include"..//operations/operation.h"
#include "..//Shapes/Shape.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "..//Shapes/Graph.h"
#include "operation.h"
#include "..\Shapes\Graph.h"
#include "..//operations/opChangeWidth.h"

opChangeSelectedWidth:: opChangeSelectedWidth(controller* pCont) :operation(pCont)
{}


void opChangeSelectedWidth ::ReadActionParameters() {
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGUI->PrintMessage("Selected is being chaned in width ");
}

//Execute the action
void opChangeSelectedWidth ::Execute()
{
	
	ReadActionParameters();
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Enter The New Width [from 1 to 6] : ");
	int wchoice = stoi( pUI->GetSrting());

	pGr->opChangeSelectedWidth(pUI->setPenWidth(wchoice));
	
}

