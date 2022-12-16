#include "Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	numberofSide = 4;
	Corner1 = P1;
	Corner2 = P2;

	int distance = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));

	double x = (2 * 3.14) / 8;
	for (int i = 0; i < numberofSide; i++)
	{
		double angle = i * (2 * 3.14) / numberofSide;
		double xOfvertix = +Corner1.x+ distance * cos(angle+x) ;
		arrayX[i] = xOfvertix;
		double yOfvertix = distance * sin(angle+x) + Corner1.y;
		arrayY[i] = yOfvertix;


	}
	//arrayY.push_back(arrayY.front());
	//arrayX.push_back(arrayX.front());

}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a r on the screen	
	pUI->DrawSquare(arrayX, arrayY, ShpGfxInfo);
}
void Square:: Save(ofstream& GUIFile) {} //Rghda added