#include "regularPolygon.h"
#include <math.h>

regularPolygon ::regularPolygon(Point P1, Point P2, Point P3, string Sides,  GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{

	Center = P1;
	start = P2;
	end = P3;
	distanceFromCenter = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
	SideLength = sqrt(pow(P3.x - P2.x, 2) + pow(P3.y - P2.y, 2));
	const int  NumberOfsides = std :: stoi(Sides);
	angle = 360 / NumberOfsides;
	PointerToarrayX[0] = start.x;
	PointerToarrayY[0] = start.y;
	PointerToarrayX[1] = end.x;
	PointerToarrayY[1] = end.y;

	for (int i = 2; i < NumberOfsides; i++)
	{
		int xOfvertix = Center.x + distanceFromCenter * sin(i * angle);
		int yOfvertix = Center.y + distanceFromCenter * cos(i * angle);
		PointerToarrayX[i] = xOfvertix;
		PointerToarrayY[i] = yOfvertix;
	}
}
regularPolygon:: ~regularPolygon()
{}
void  regularPolygon::Draw(GUI* pUI) const
{
	pUI->DrawRegularPol(PointerToarrayX, PointerToarrayY, NumberOfsides, ShpGfxInfo);
}
