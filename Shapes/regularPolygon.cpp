#include "regularPolygon.h"
#include <cmath>

regularPolygon ::regularPolygon(Point P1, Point P2, int Sides,  GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	//x[n] = distanceFromCenter * cos(2*pi* n/N + theta) + x_centre
	//y[n] = r * sin(2 * pi * n / N + theta) + y_centre
	//cos(n* 2* pi/s), sin(n*360/s)
	const double pi = 3.14159;
	Center.x = P1.x;
	Center.y = P1.y;
	start.x = P2.x;
	start.y = P2.y;
	/*end.x = P3.x;
	end.y = P3.y;*/
	r = sqrt(((P1.x - P2.x)*(P1.x - P2.x)) + ((P1.y - P2.y)*(P1.y - P2.y)));
	SideLength = 30;
    int  NumberOfsides = Sides;
	angle = 0;


	for (int i = 0; i < NumberOfsides; i++)
	{
		angle = i* (2 * pi) / NumberOfsides;
		double xOfvertix =  r * cos(angle)  + Center.x;
		arrayX[i] = xOfvertix;
		double yOfvertix =  r * sin(angle) + Center.y ;
		arrayY[i] = yOfvertix;
		
	}
}
regularPolygon:: ~regularPolygon()
{}
void  regularPolygon::Draw(GUI* pUI) const
{
	pUI->DrawPol(arrayX, arrayY, NumberOfsides, ShpGfxInfo);
}

void regularPolygon::Save(ofstream& GUIFile) {} //Rghda added