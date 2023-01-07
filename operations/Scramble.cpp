#include "scramble.h"
#include "..//controller.h"
#include "operation.h"
#include <string>
#include "Select.h"
#include "..//Shapes/Groupshape.h"
#include <vector>

Scramble :: Scramble(controller* pCont) :operation(pCont)
{}
Scramble :: ~Scramble()
{}

void Scramble::Execute()
{
	GUI* pGUI = pControl->GetUI();
	//string choice;
	Graph* pGraph = pControl->getGraph();
	//pGraph->Scramble();

	pGraph->GDuplicate(pGUI);
	pGraph->Scramble();
}
