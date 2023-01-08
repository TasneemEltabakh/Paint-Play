#include "Duplicate.h"

Duplicate::Duplicate(controller* pCont) :operation(pCont) {
	
};

Duplicate::~Duplicate() {
};

void Duplicate::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGraph->GDuplicate();

};