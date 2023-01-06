#include "opAddImg.h"
#include "..//controller.h"
#include "..//GUI/GUI.h"

opAddImg::opAddImg(controller* pCont) :operation(pCont)
{}

opAddImg::~opAddImg()
{}

void opAddImg::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	Point p= pGraph->getselectedShape()->getCenter();
	pUI->AddImg(p);

	
}