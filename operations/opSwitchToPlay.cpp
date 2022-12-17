#include "opSwitchToPlay.h"
#include"operation.h"
#include "..//controller.h"
#include "..//CMUgraphicsLib/windowinput.h"
#include <string>
#include "opsSwitch.h"

opSwitchToPlay::opSwitchToPlay(controller* pCont) :operation(pCont)
{}
opSwitchToPlay::~opSwitchToPlay()
{}

void opSwitchToPlay::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->switchtoplay();
	
}
