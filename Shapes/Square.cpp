#include "Square.h"
#include <fstream>
#include <iostream>

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
void Square:: Save(ofstream& outfile) {  //Rghda added
	//I tried to put the coordinate in a single line
		//and the colors in another one, but it will make it hard for load function
		  ////////////////////////////////////////////////////
		 //name,id,corners x , y,drawclr,borderwdth,fillclr//
		////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = ID;

	outfile << "sQUARE" << " " << id << " "    //the name and id
		<< Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " "; //the corners

	outfile << redcolorlevel << " " << greencolorlevel << " " << bluecolorlevel << " ";

	outfile << ShpGfxInfo.BorderWdth << " ";

	if (ShpGfxInfo.isFilled != true)
		outfile << "0 0 0" << " ";
	else
		outfile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " "
		<< (int)ShpGfxInfo.FillClr.ucBlue << " ";

	outfile << endl;
} 

string Square::PrintOnTool()
{
	string values = "I should put here the data of square";
	return values;
}


bool Square::IsShapeExisting(int x, int y)  //Rghda added
{
	return false;
}