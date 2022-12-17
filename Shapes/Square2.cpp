#include "../Shapes/Square2.h"
#include <fstream>
#include <iostream>
#include<string>
using namespace std;

Square2::Square2(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	int side;
	Corner1 = P1;
	Corner2 = P2;

	int distance = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
}
Square2::~Square2()
{}

void Square2::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a r on the screen	
	pUI->DrawSquare(Corner1,Corner2, ShpGfxInfo);
}















// raghda part 
void Square2::Save(ofstream& outfile) {  //Rghda added
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

string Square2::PrintOnTool()
{
	string values = "I should put here the data of square";
	return values;
}


bool Square2::IsShapeExisting(int x, int y)  //Rghda added
{
	return false;
}

