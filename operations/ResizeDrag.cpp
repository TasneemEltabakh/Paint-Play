#include "ResizeDrag.h"
#include "..//controller.h"


ResizeDrag::ResizeDrag(controller* pCont) :operation(pCont)
{}
ResizeDrag :: ~ResizeDrag()
{}

void ResizeDrag::Execute()
{
	GUI* pUI = pControl->GetUI();
	window* wind = pUI->pointertowind();
	Graph* pGraph = pControl->getGraph();
	wind->WaitMouseClick(c.x, c.y);
	while (wind->GetButtonState(LEFT_BUTTON, c.x, c.y) != BUTTON_DOWN) {


		pGraph->resizebydrag(c, c.x, c.y);
		pUI->ClearStatusBar();
		pControl->UpdateInterface();
		Sleep(20);
		if (wind->GetButtonState(LEFT_BUTTON, c.x, c.y) == BUTTON_DOWN) {

			break;
		}
	}
	


	

}