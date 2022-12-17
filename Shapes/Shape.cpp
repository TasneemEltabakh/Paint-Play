#include "shape.h"
#include "..//controller.h"
#include <string>
using namespace std;

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}
void shape::setCrntPenWidth(int a)
{
	ShpGfxInfo.BorderWdth = a;
}

// my func to get aim of selection 

void SelectedShapeAim()
{// to ask the user if the what  he want to do with the selected shape (color border / color fill / width 
	if (1)
	{

	}


}