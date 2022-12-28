#include "rotatOp.h"
#include "..//controller.h"
#include "operation.h"
#include <string>



Rotate::Rotate(controller* pCont) :operation(pCont)
{}
Rotate :: ~Rotate()
{}

void Rotate::Execute()
{

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->rotate();

}