#include "ZooomOut.h"
#include "..//controller.h"
#include "operation.h"
#include <string>



ZooomOut::ZooomOut(controller* pCont) :operation(pCont)
{}
ZooomOut :: ~ZooomOut()
{}

void ZooomOut::Execute()
{

	GUI* pUI = pControl->GetUI();

}