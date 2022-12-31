#include "ResizeDrag.h"
#include "..//controller.h"


ResizeDrag::ResizeDrag(controller* pCont) :operation(pCont)
{}
ResizeDrag :: ~ResizeDrag()
{}

void ResizeDrag::Execute()
{
	int  X, Y;
	GUI* pUI = pControl->GetUI();
	window* wind = pUI->pointertowind();
	pUI->GetPointClicked(X, Y);
	Graph* pGraph = pControl->getGraph();

	while (wind->GetButtonState(LEFT_BUTTON, X, Y) != BUTTON_DOWN)
	{
		pUI->ClearDrawArea();
		pUI->ClearStatusBar();
		pGraph->resizebydrag(X, Y);
		pControl->UpdateInterface();
		
		Sleep(100);

	}
	

}