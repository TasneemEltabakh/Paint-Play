#include "ResizeDrag.h"
#include "..//controller.h"


ResizeDrag::ResizeDrag(controller* pCont) :operation(pCont)
{}
ResizeDrag :: ~ResizeDrag()
{}

void ResizeDrag::Execute()
{
	int  X, Y,x,y;
	x = 0;
	y = 0;
	GUI* pUI = pControl->GetUI();
	window* wind = pUI->pointertowind();
	Graph* pGraph = pControl->getGraph();

	while (wind->GetButtonState(LEFT_BUTTON, X, Y) != BUTTON_DOWN)
	{
		pGraph->resizebydrag(c, x, y);
		pUI->ClearStatusBar();
		pUI->CreateDrawToolBar();
		pControl->UpdateInterface();
		
		Sleep(20);
		

	}

	

}