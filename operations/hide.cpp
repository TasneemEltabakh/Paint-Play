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
	
	GUI* pUI = pControl->GetUI();
	
	Graph* pGraph = pControl->getGraph();
	
	pGraph->Hide();
	pControl->UpdateInterface();

}