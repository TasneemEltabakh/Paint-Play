#include "opChangeFill.h"
#include "..\Shapes\Shape.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"



opChangeFill::opChangeFill(controller* pCont) :operation(pCont)
{}
opChangeFill::~opChangeFill()
{}

////Execute the operation
void opChangeFill::Execute()
{
	Point B1, B2;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("You are in fill color mode ::  ");
	// get the click of the user in color pallette 
	


	pUI->ClearStatusBar();
}