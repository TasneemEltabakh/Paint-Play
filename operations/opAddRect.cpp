#include "opAddRect.h"
#include "..\shapes\Rect.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opAddRect::opAddRect(controller * pCont):operation(pCont)
{}
opAddRect::~opAddRect()
{} 

//Execute the operation
void opAddRect::Execute() 
{
	Point P1, P2;


	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Rectangle: Click at first corner");
	
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	
	GfxInfo RectGfxInfo;
	
	
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	RectGfxInfo.isSelected = false;	

	if (pUI->checkfill() == true)
	{
		if (RectGfxInfo.isSelected == true)

			RectGfxInfo.FillClr = pUI->getCrntFillColor();
		else
			RectGfxInfo.FillClr = pUI->getoldFillColor();
	}
	else
		RectGfxInfo.isFilled = false;

	if (pUI->checkborder() == true)
	{
		if (RectGfxInfo.isSelected == true)
			RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	}
	else
		RectGfxInfo.BorderWdth = pUI->getoldPenWidth();

	if (pUI->checkcol() == true)
	{
		if (RectGfxInfo.isSelected == true)
			RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	}
	else
		RectGfxInfo.DrawClr = pUI->getoldDrawColor();

	Graph* pGr = pControl->getGraph();

	Rect* R = new Rect(P1, P2, RectGfxInfo);
	pGr->Addshape(R);

	

}
