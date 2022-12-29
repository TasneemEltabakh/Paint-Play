
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

	int num;
	string cnt;


	pGUI->PrintMessage("press 1 for singl select and any thing for multi select");
	string whichoperationsinglemulti = pGUI->GetSrting();
	num = stoi(whichoperationsinglemulti);

	if (num == 1) {        //the user here choose single shape select
		pGUI->PrintMessage("Click at the shape to select.");
		pGUI->GetPointClicked(P1.x, P1.y);
		//I couldn't use the selectedshape from graph file as it is a praivet data
		if (P1.x > 722 && P1.x < 761 && P1.y>9 && P1.y < 52) {
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
	else {

		pGUI->PrintMessage("start select shapes");
		bool test = true;

		while (test) {

			pGUI->GetPointClicked(P1.x, P1.y);

			shape* selectedmultishape = pGraph->Getshape(P1.x, P1.y);

			if (P1.x > 722 && P1.x < 761 && P1.y>9 && P1.y < 52) {
				pGUI->ClearStatusBar();
				test = false;
			}

			else if (selectedmultishape == nullptr) {
				pGraph->unselectmulti();
				pGUI->ClearStatusBar();
				test = false;
			}

			else if (selectedmultishape->IsSelected()) {
				pGraph->unselectselectedshape(selectedmultishape);
				cnt = pGraph->numberofselectedshapes();
				pGUI->PrintMessage("after disselect, You have selected " + cnt + " shapes till now");


			}
			else {
				pGraph->pushbackselectvector(selectedmultishape);
				selectedmultishape->SetSelected(true);

				cnt = pGraph->numberofselectedshapes();
				pGUI->PrintMessage("You have selected " + cnt + " shapes till now");
			}

		}


	}

}