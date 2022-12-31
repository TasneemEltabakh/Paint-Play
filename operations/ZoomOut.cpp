#include "ZoomOut.h"
#include "..//controller.h"
#include "operation.h"
#include <string>



ZoomOut::ZoomOut(controller* pCont) :operation(pCont)
{}
ZoomOut:: ~ZoomOut()
{}

void ZoomOut::Execute()
{

	GUI* pUI = pControl->GetUI();
	int X, Y;
	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();
	pUI->GetPointClicked(X, Y);
	pUI->ClearStatusBar();
	Graph* pGraph = pControl->getGraph();
	pGraph->ZOOM(0.5, X, Y);

}