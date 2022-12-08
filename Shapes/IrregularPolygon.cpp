#include "IrregularPolygon.h"

IrregularPolygon::IrregularPolygon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	
	point1 = p1;
	point2 = p2;
    point3 = p3;
	point4 = p4;
	point5 = p5;
	point6 = p6;
}
IrregularPolygon :: ~IrregularPolygon()
{

}
void IrregularPolygon::Draw(GUI* pUI) const
{
	int arrayX[6] = { point1.x, point2.x, point3.x , point4.x  , point5.x , point6.x };
	int arrayY[6] = { point1.y ,point2.y ,  point3.y  , point4.y  ,point5.y  , point6.y };
	pUI->DrawPol(arrayX, arrayY, 6, ShpGfxInfo);
}
