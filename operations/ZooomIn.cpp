#include "ZoomIn.h"
#include "..//controller.h"
#include "operation.h"
#include <string>



ZooomIn::ZooomIn(controller* pCont) :operation(pCont)
{}
ZooomIn :: ~ZooomIn()
{}

void ZooomIn::Execute()
{

	GUI* pUI = pControl->GetUI();
	int X, Y;

	pUI->DoZoomin();
	pUI->GetPointClicked(X, Y);
	pUI->Zoomin(X, Y);

}