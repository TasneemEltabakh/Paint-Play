#include "opSwitchTodraw2.h"
#include "opChooseColour.h"
#include"operation.h"
#include "..//controller.h"
#include "..//CMUgraphicsLib/windowinput.h"
#include"..//Shapes/Shape.h"
#include <string>
#include "opsSwitch.h"

opSwitchTodraw2::opSwitchTodraw2(controller* pCont) :operation(pCont)
{}
opSwitchTodraw2::~opSwitchTodraw2()
{}

void opSwitchTodraw2::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->CreateDrawToolBar2()

}