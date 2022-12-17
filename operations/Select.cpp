
#include"Select.h"
#include "opAddirrPol.h"
#include "..//Shapes/IrregularPolygon.h"
#include "..//Shapes/Shape.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "operation.h"
#include "..//Shapes/Graph.h"


Select::Select(controller* pCont) :operation(pCont)
{}


void Select::Execute() {

	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	pGUI->PrintMessage("Click at the shape to select.");
	pGUI->GetPointClicked(P1.x, P1.y);

	//I couldn't use the selectedshape from graph file as it is a praivet data


	if (P1.x > 765 && P1.x < 808 && P1.y>11 && P1.y < 49) {
		pGUI->ClearStatusBar();
		pControl->UpdateInterface();
	}
	else {
		shape* selectedshape = pGraph->Getshape(P1.x, P1.y);
		shape* previouslyselected = pGraph->getselectedShape();
		if (selectedshape) {
			if (previouslyselected) {
				previouslyselected->SetSelected(false);
				selectedshape->SetSelected(true);
				pGraph->setselectedShape(selectedshape);
				pGUI->PrintMessage(selectedshape->PrintOnTool());
			}
			else {
				selectedshape->SetSelected(true);
				pGraph->setselectedShape(selectedshape);
				pGUI->PrintMessage(selectedshape->PrintOnTool());
			}
		}
		else {
			if (previouslyselected) {
				previouslyselected->SetSelected(false);
				pGraph->setselectedShape(nullptr);
			}
		}
		//print data on toolbar

	   //selectedshape->SetSelected(true);  //set selected shape by true
		pControl->UpdateInterface();
	}
}