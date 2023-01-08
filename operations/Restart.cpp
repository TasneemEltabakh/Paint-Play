#include "Restart.h"
#include "..//controller.h"
#include "operation.h"
#include "Scramble.h"
#include "Play.h"
#include <string>
#include "Select.h"
#include "..//Shapes/Groupshape.h"
#include <vector>

Restart::Restart(controller* pCont) :operation(pCont)
{}
Restart :: ~Restart()
{}

void Restart::Execute()
{
	Scramble s(pControl);
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->returnallshapesforplay();
	pControl->UpdateInterface();
	s.Execute();
}