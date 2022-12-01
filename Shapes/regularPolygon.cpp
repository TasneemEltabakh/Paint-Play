#include "regularPolygon.h"
#include <math.h>

regularPolygon ::regularPolygon(Point P1, Point P2, Point P3, int Sides,  GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Center.x = P1.x;
	Center.y = P1.y;
	start.x = P2.x;
	start.y = P2.y;
	end.x = P3.x;
	end.y = P3.y;
	distanceFromCenter = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
	SideLength = sqrt(pow(P3.x - P2.x, 2) + pow(P3.y - P2.y, 2));
	const int  NumberOfsides = Sides;
	angle = 360 / NumberOfsides;
	PointerToarrayX[0] = P2.x;
	PointerToarrayY[0] = P2.y;
	PointerToarrayX[1] = P3.x;
	PointerToarrayY[1] = P3.y;

	for (int i = 2; i < NumberOfsides; i++)
	{
		int xOfvertix = P1.x + distanceFromCenter * sin(i * angle);
		int yOfvertix = P1.y + distanceFromCenter * cos(i * angle);
		PointerToarrayX[i] = xOfvertix;
		PointerToarrayY[i] = yOfvertix;
	}
}
regularPolygon:: ~regularPolygon()
{}
void  regularPolygon::Draw(GUI* pUI) const
{
	pUI->DrawPol(PointerToarrayX, PointerToarrayY, NumberOfsides, ShpGfxInfo);
}
