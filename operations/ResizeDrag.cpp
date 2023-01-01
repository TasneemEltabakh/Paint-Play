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
	wind->WaitMouseClick(X , Y);
	c.x = X;
	c.y = Y;
	Graph* pGraph = pControl->getGraph();

	while (wind->GetButtonState(LEFT_BUTTON, x, y) != BUTTON_DOWN)
	{
		pGraph->resizebydrag(c,x, y);
		pUI->ClearStatusBar();
		pUI->CreateDrawToolBar();
		pControl->UpdateInterface();
		
		Sleep(40);

	}
	

}