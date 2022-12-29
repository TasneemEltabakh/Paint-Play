
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
	int sizeint;
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	string sizestring = pGraph->numberofselectedshapes();
	sizeint = stoi(sizestring);

	if (sizeint == 0) {
		pGraph->DeleteGraph();
		pGUI->PrintMessage("Selected shape is removed");
	}
	else {
		pGraph->DeleteMultiShapesGraph();
		pGUI->PrintMessage("Selected Multi shapes are removed");

	}
}

//Execute the action
void Delete::Execute()
{
	ReadActionParameters();
}

