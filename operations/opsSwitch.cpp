#include "opsSwitch.h"
#include "opChooseColour.h"
#include"operation.h"
#include "..//controller.h"
#include "..//CMUgraphicsLib/windowinput.h"
#include"..//Shapes/Shape.h"
#include <string>
#include "opsSwitch.h"

opsSwitch::opsSwitch(controller * pCont):operation(pCont)
{}
opsSwitch::~opsSwitch()
{}

void opsSwitch::Execute()
{
	GUI* pUI = pControl->GetUI();
		pUI->switchtoplay();
	
}
