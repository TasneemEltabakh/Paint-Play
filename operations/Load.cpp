#include "Load.h"
using namespace std;

opLoad::opLoad(controller* pCont) :operation(pCont) {

}
opLoad::~opLoad() {

}
void opLoad::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph * pGraph= pControl->getGraph();

	pUI->PrintMessage("Write file name");
	name = pUI->GetSrting() + ".txt";
	inputfile.open(name);

	do {
		if (inputfile.good()) {
			break;
		}
		else {
			pUI->PrintMessage("Please enter valid name");
			name = pUI->GetSrting() + ".txt";
			inputfile.open(name);
		}

	} while (!inputfile.good());

	pGraph->Load(inputfile);
	inputfile.close();
	pUI->PrintMessage("File is loaded");
	pUI->ClearStatusBar();

}