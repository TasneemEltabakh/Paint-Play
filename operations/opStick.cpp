
#include "opChooseColour.h"
#include "..//controller.h"
#include "operation.h"
#include "..//CMUgraphicsLib/windowinput.h"
#include"..//Shapes/Shape.h"
#include <string>
#include "Save.h"
#include "opStick.h"


opStick::opStick(controller* pCont) : operation(pCont)
{}
opStick :: ~opStick()
{}

void opStick::Execute()
{
	int x,y;
	GUI* pUI = pControl->GetUI();

	string msg = "enter the name of the image you want to stick";
	pUI->PrintMessage(msg);

	string theimage = pUI->GetSrting();
	msg = " Click at the  point to stick in";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(x, y);
	pUI->ClearStatusBar();
	



}