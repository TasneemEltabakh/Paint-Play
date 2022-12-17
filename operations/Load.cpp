#include "Load.h"
using namespace std;

opLoad::opLoad(controller* pCont) :operation(pCont) {

}
opLoad::~opLoad() {

}
void opLoad::Execute() {
	string choice;
	GUI* pUI = pControl->GetUI();
	Graph * pGraph= pControl->getGraph();
	pUI->PrintMessage("If you upload a saved file,your current graph will be lost to continue type (c) and to abort type any letter");
	choice = pUI->GetSrting();
	if (choice == "c")
	{
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

		pUI->ClearDrawArea();
		pGraph->EmptyGraph();
		pGraph->Load(inputfile);
		inputfile.close();
		pUI->PrintMessage("File is loaded");
		pUI->ClearStatusBar();
	}
	pUI->ClearStatusBar();
}