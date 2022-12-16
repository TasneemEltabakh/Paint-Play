#include "opChangeWidth.h"
#include "..\Shapes\Shape.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"



opChangeWidth ::opChangeWidth (controller* pCont) :operation(pCont)
{}
opChangeWidth ::~opChangeWidth ()
{}

////Execute the operation
void opChangeWidth ::Execute()
{
	Point B1, B2;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	//create the color tool bar 

	//pUI->CreateColorBar();
	//getting the point clicked 
	//pUI->GetPointClicked(B1.x, B2.y);
	pUI->PrintMessage("Enter The New Width [from 1 to 6] : ");
	int wchoice =stoi( pUI->GetSrting());
	pUI->GetIsChanged();
	pUI->setPenWidth(wchoice);
	// clear the status bar
	pUI->ClearStatusBar();
}