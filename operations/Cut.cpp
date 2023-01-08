#include "Cut.h"

Cut::Cut(controller* pCont) :operation(pCont) {

};

Cut:: ~Cut() {

};

void  Cut::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->GCut();
	bool success = pGraph->GCut();
	if (success)
		pUI->PrintMessage("Object cut to clipboard click paste to add it to graph");
	else
		pUI->PrintMessage("You have to select some shapes first");
};