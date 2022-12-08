#include "regularPolygon.h"
#include <cmath>

regularPolygon ::regularPolygon(Point P1, Point P2, int Sides,  GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	
	const double pi = 3.14159;
	Center.x = P1.x;
	Center.y = P1.y;
	start.x = P2.x;
	start.y = P2.y;
	
	r = sqrt(pow((P1.x - P2.x),2) + pow((P1.y - P2.y),2));
    int NumberOfsides = Sides;
	


	for (int i = 0; i < NumberOfsides; i++)
	{
		angle = i* (2 * pi) / NumberOfsides;
		double xOfvertix =  r * cos(angle)  + Center.x;
		arrayX.push_back(xOfvertix);
		double yOfvertix =  r * sin(angle) + Center.y ;
		arrayY.push_back(yOfvertix);
		
		
	}
	//arrayY.push_back(arrayY.front());
	//arrayX.push_back(arrayX.front());
	a = &arrayX[0];
	b = &arrayY[0];
}
regularPolygon:: ~regularPolygon()
{}
void  regularPolygon::Draw(GUI* pUI) const
{
	int numberofv = arrayY.size();
	pUI->DrawPol(a, b, numberofv, ShpGfxInfo);
}

void regularPolygon::Save(ofstream& GUIFile) {} //Rghda added