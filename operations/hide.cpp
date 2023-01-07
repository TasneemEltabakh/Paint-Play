#include "hide.h"
#include "..//controller.h"
#include "operation.h"
#include <string>
#include "Select.h"
#include "..//Shapes/Groupshape.h"
#include <vector>
Hide::Hide(controller* pCont) :operation(pCont)
{}
Hide :: ~Hide()
{}

void Hide::Execute()
{
	int numberOfsize, len, width;
	GUI* pUI = pControl->GetUI();
	string choice;
	Graph* pGraph = pControl->getGraph();
	numberOfsize = pGraph->getvectorsize();
	pGraph->Hide();
	pControl->UpdateInterface();

}