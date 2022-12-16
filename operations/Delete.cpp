
#include"Delete.h"
#include "opAddirrPol.h"
#include "..//Shapes/IrregularPolygon.h"
#include "..//Shapes/Shape.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "operation.h"

#include "..\Shapes\Graph.h"
Delete::Delete(controller* pCont) :operation(pCont)
{}


void Delete::ReadActionParameters() {
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->DeleteGraph();
	pGUI->PrintMessage("Selected shape is removed");
}

//Execute the action
void Delete::Execute()
{
	ReadActionParameters();
}

