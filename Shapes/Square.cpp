#include "Square.h"
#include <fstream>
#include <iostream>

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	numberofSide = 4;
	Corner1 = P1;
	Corner2 = P2;

	int distance = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
	//for angle 
	double x = (2 * 3.14) / 8;
	for (int i = 0; i < numberofSide; i++)
	{
		double angle = i * (2 * 3.14) / numberofSide;
		double xOfvertix = +Corner1.x+ distance * cos(angle+x) ;
		arrayX[i] = xOfvertix;
		double yOfvertix = distance * sin(angle+x) + Corner1.y;
		arrayY[i] = yOfvertix;


	}
	

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
	int id = 4;

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
	int id = 4;
	string values = "you selected a square,ID: " + to_string(id) + "\n . First Point: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "). Second Point: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ").";
	return values;
}


bool Square::IsShapeExisting(int x, int y)  //Rghda added
{
	return false;
}

void Square::Load(ifstream& inputfile) {
	//GUI* pUI = ;
	int Draw[3], Fill[3];

	inputfile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >>
		Draw[0] >> Draw[1] >> Draw[2] >> ShpGfxInfo.BorderWdth >> Fill[0] >> Fill[1] >> Fill[2];

	ShpGfxInfo.DrawClr = color(Draw[0], Draw[1], Draw[2]);

	if (Fill[0] == Fill[1] == Fill[2] == 0)
	{
		ShpGfxInfo.FillClr = WHITE;
		ShpGfxInfo.isFilled = false;
	}
	else {
		ShpGfxInfo.FillClr = color(Fill[0], Fill[1], Fill[2]);
		ShpGfxInfo.isFilled = true;
	}

	cout << "s" << Corner1.x << Corner1.y << Corner2.x << Corner2.y << endl;
	cout << "square loaded";
}