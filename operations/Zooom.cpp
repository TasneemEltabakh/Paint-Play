#include "Zoom.h"
#include "..//controller.h"
#include "operation.h"
#include <string>



Zoom::Zoom(controller* pCont) :operation(pCont)
{}
Zoom:: ~Zoom()
{}

void Zoom::Execute()
{
	
	GUI* pUI = pControl->GetUI();
	int X, Y;
	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();
	pUI->PrintMessage(" if you want to zoom in click: (+) if you want to zoom out click (-): ");
	
	string choice = pUI->GetSrting();

	

	pUI->ClearStatusBar();

	if (choice == "+")
	{
		pUI->DoZoomin();
		pUI->GetPointClicked(X, Y);
		pUI->Zoom(X, Y);
	}
	else if (choice == "-")
	{
		pUI->DoZoomOut();
		pUI->GetPointClicked(X, Y);
		pUI->Zoom(X, Y);
	}
	else
		return;

}