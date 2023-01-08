#include "Copy.h"
#include<iostream>

Copy::Copy(controller* pCont) :operation(pCont) {

};

Copy:: ~Copy() {

};

void  Copy::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	cout << "copy called" << endl;
	pGraph->GCopy();
	pUI->PrintMessage("Object copied to clipboard click paste to add it to graph");
}