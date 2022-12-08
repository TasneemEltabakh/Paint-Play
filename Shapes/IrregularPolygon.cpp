#include "IrregularPolygon.h"

IrregularPolygon::IrregularPolygon(vector<Point> arrayv, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	for (int i = 0; i < arrayv.size(); i++)
	{
		arrayX.push_back(arrayv[i].x);
		arrayY.push_back(arrayv[i].y);
	}
	
	arrayY.push_back(arrayY.front());
    arrayX.push_back(arrayX.front());
	a = &arrayX[0];
	b = &arrayY[0];
	
  
}
IrregularPolygon :: ~IrregularPolygon()
{
}
void IrregularPolygon::Draw(GUI* pUI) const
{
	int size = arrayX.size();
	pUI->DrawPol(a, b, size, ShpGfxInfo);
}

void IrregularPolygon::Save(ofstream& GUIFile) {} //Rghda added