#include "ciecle.h"


Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	radious = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));

}
Circle :: ~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	pUI->DrawCircle(Corner1,radious, ShpGfxInfo);
}
void Circle::Save(ofstream& GUIFile) {} //Rghda added