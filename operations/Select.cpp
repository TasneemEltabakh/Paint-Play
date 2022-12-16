
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
	shape*selectedshape = pGraph->Getshape(P1.x, P1.y);
	

	pGUI->PrintMessage(selectedshape->PrintOnTool());  //print data on toolbar

	//selectedshape->SetSelected(true);  //set selected shape by true
	pControl->UpdateInterface();
	

	//if (TerminateSelection(P)) {
	//	if (SelectedSoFar.size() > 1)
	//		pOut->ClearStatusBar();
	//	return true;
	//}

	//if (selectedshape == NULL) {
	//	//Unselect();
	//	pGUI->ClearStatusBar();
	//}
	
	

}