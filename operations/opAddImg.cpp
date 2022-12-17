#include "opAddImg.h"
#include "..//controller.h"
#include "..//GUI/GUI.h"

opAddImg::opAddImg(controller* pCont) :operation(pCont)
{}

opAddImg::~opAddImg()
{}

void opAddImg::Execute() {

	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Write the image name");
	string name = pUI->GetSrting();

	//pUI->PrintMessage("choose where to put your image.. click the start point ");
	//pUI->GetPointClicked(P1.x, P1.y);

	//pUI->PrintMessage("Click your end point");
	//pUI->GetPointClicked(P2.x, P2.y);
	//pUI->ClearStatusBar();
	pUI->AddImg(name);

	
}