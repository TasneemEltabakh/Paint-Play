#include "Cut.h"

Cut::Cut(controller* pCont) :operation(pCont) {

};

Cut:: ~Cut() {

};

void  Cut::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->GCut();
	pUI->PrintMessage("Selected object cut to clipboard choose paste to add it to graph");
};