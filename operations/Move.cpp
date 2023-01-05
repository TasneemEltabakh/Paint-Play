#include"Move.h"


Move::Move(controller* pCont) :operation(pCont)
{}

void Move::Execute() {
	int x, y;
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	window* pwind = pUI->pointertowind();
	pwind->WaitMouseClick(x, y);

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