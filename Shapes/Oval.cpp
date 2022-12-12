#include "Oval.h"


Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

}
Oval :: ~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	
	//Call Output::DrawTriangle to draw a Triangle on the screen	
	pUI->DrawEllipse(Corner1,Corner2, ShpGfxInfo);
}
void Oval::Save(ofstream& GUIFile) {} //Rghda added