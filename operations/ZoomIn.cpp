#include "ZoomIn.h"
#include "..//controller.h"
#include "operation.h"
#include <string>
#include <zmouse.h>



ZoomIn::ZoomIn(controller* pCont) :operation(pCont)
{}
ZoomIn:: ~ZoomIn()
{}

void ZoomIn::Execute()
{

	GUI* pUI = pControl->GetUI();
	int X, Y;
	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();
	pUI->GetPointClicked(X, Y);
	pUI->ClearStatusBar();
	Graph* pGraph = pControl->getGraph();
	window* wind = pUI->pointertowind();
	pGraph->ZOOM(1.5, X, Y);
	
	
	
}