#include "regularPolygon.h"

regularPolygon::regularPolygon(PointP1, Point P2, Point P3, string Sides,  GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{

	Center = P1;
	start = P2;
	end = P3;
	distanceFromCenter = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
	SideLength = sqrt(pow(P3.x - P2.x, 2) + pow(P3.y - P2.y, 2));
	NumberOfsides = int(Sides);
	angle = 360 / NumberOfsides;


}
regularPolygon:: ~regularPolygon()
{}
void  regularPolygon::Draw(GUI* pUI) const
{
	pUI->DrawRegularPol(start, end, distanceFromCenter, SideLength, angle , shapeGfxInfo);
}
