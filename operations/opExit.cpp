#include "opExit.h"
#include "opChooseColour.h"
#include "..//controller.h"
#include "operation.h"
#include "..//CMUgraphicsLib/windowinput.h"
#include"..//Shapes/Shape.h"
#include <string>
#include "Save.h"

opExit::opExit(controller* pCont) :operation(pCont)
{}
opExit :: ~opExit()
{}

void opExit::Execute()
{
	char keyp;
	GUI* pUI = pControl->GetUI();
	window w;
	w.ChangeTitle("EXIT WINDOW");
	w.SetPen(RED);
	w.SetBrush(RED);
	w.DrawString(30, 50, "do you");
	w.WaitKeyPress(keyp);
	if (keyp == 's')
	{

	}
	else
		return;


}
