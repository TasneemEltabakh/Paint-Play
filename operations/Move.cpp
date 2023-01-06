#include"Move.h"


Move::Move(controller* pCont) :operation(pCont)
{}

void Move::Execute() {
	int num;
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	window* pwind = pUI->pointertowind();

	pUI->PrintMessage("press 1 for singl move and any thing for multi move");
	string whichoperationsinglemulti = pUI->GetSrting();
	num = stoi(whichoperationsinglemulti);

	if (num == 1) {    //the user here choose single shape move
		if (pGraph->getselectedShape()) {

			pUI->PrintMessage("you can move it now");

			while (pwind->GetButtonState(LEFT_BUTTON, pointmove.x, pointmove.y) != BUTTON_DOWN) {
				if (pointmove.y > 100 && pointmove.y < 740) {
					pGraph->MoveGraph(pointmove.x, pointmove.y);
					pUI->ClearStatusBar();
					pUI->CreateDrawToolBar();
					pControl->UpdateInterface();

					Sleep(40);
				}
			}
		}
		else {
			pUI->PrintMessage("You should selected shapes first");
		}
	
	}
	else {
		if (pGraph->getselectedvectorsize()!=0) {

			pUI->PrintMessage("you can move them now");

			while (pwind->GetButtonState(LEFT_BUTTON, pointmove.x, pointmove.y) != BUTTON_DOWN) {
				if (pointmove.y > 100 && pointmove.y < 740) {
					pGraph->MoveMultiGraph(pointmove.x, pointmove.y);
					pUI->ClearStatusBar();
					pUI->CreateDrawToolBar();
					pControl->UpdateInterface();

					Sleep(40);
				}
			}
		}
		else {
			pUI->PrintMessage("You should selected multi shapes first");
		}
	}

	

}