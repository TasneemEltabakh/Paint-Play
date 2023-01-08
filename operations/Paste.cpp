#include "Paste.h"

Paste::Paste(controller* pCont) :operation(pCont) {

};

Paste::~Paste() {

};

void Paste::Execute() {

	GUI* pUI = pControl->GetUI();
	Point P;
	Graph* pGraph = pControl->getGraph();
	cout << "paste called" << endl;

	if (pGraph->getClipboardsize() == 0) {
		pUI->PrintMessage("Clipboard is empty copy or cut some shapes first to paste ");
		cout << "empty" << endl;
	}

	else {

		pUI->PrintMessage("Choose the point where you want to paste ");
		pUI->GetPointClicked(P.x, P.y);

		cout << P.x << " " << P.y << endl;

		pGraph->GPaste(P.x, P.y);

		cout << ("Clipboard pasted succesfully");
	}
};