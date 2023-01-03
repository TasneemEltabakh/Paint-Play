#include "opSwitchTodraw2.h"
#include"operation.h"
#include "..//controller.h"
#include "..//CMUgraphicsLib/windowinput.h"
#include <string>


opSwitchTodraw2::opSwitchTodraw2(controller* pCont) :operation(pCont)
{}
opSwitchTodraw2::~opSwitchTodraw2()
{}

void opSwitchTodraw2::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->switchtodraw2();

}