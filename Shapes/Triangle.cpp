#include "Triangle.h"
#include <fstream>
#include <iostream>
#include<string>
using namespace std;

Triangle :: Triangle (Point P1, Point P2, Point P3 , GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Triangle :: ~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawTriangle to draw a Triangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2, Corner3 ,  ShpGfxInfo);
}



float Triangle::trianglearea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool Triangle::IsShapeExisting(int x, int y)
{
	float temp = trianglearea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float try1 = trianglearea(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float try2 = trianglearea(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	float try3 = trianglearea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if (temp == try1 + try2 + try3)
	{
		return true;
	}
	else
	{
		return false;
	}
}


string Triangle::PrintOnTool()
{
	string values;;
	float getarea = trianglearea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	values = "you selected a TRIANGLE. ID: " + to_string(ID) + 
		". First Point: (" + to_string(Corner1.x) + ", " + 
		to_string(Corner1.y) + "). Second Point: (" + to_string(Corner2.x) +
		", " + to_string(Corner2.y) + "). Third Point: (" + to_string(Corner3.x) + 
		", " + to_string(Corner3.y) + ")" + "The Area of the Triangle is: " + 
		to_string(getarea) + ".";
	return values;
}


void Triangle::Save(ofstream& outfile) {   //Rghda added

	////////////////////////////////////////////////////
	//name,id,corners x , y,drawclr,borderwdth,fillclr//
   ////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = ID;

	outfile << "Triangle" << " " << id << " "
	<< Corner1.x << " " << Corner1.y << " "
	<< Corner2.x << " " << Corner2.y << " "
	<< Corner3.x << " " << Corner3.y << " ";

	outfile << redcolorlevel << " " << greencolorlevel << " " << bluecolorlevel << " ";

	outfile << ShpGfxInfo.BorderWdth << " ";

	if (ShpGfxInfo.isFilled != true)
		outfile << "0 0 0" << " " ;
	else
		outfile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " "
		<< (int)ShpGfxInfo.FillClr.ucBlue << " " ;

	outfile << endl;
}

void Triangle::Load(ifstream& inputfile) {
	//GUI* pUI = ;
	int Draw[3], Fill[3];

	inputfile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner1.y >>
		Draw[0] >> Draw[1] >> Draw[2] >> ShpGfxInfo.BorderWdth >> Fill[0] >> Fill[1] >> Fill[2];

	ShpGfxInfo.DrawClr = color(Draw[0], Draw[1], Draw[2]);

	if (Fill[0] == Fill[1] == Fill[3] == 0)
	{
		ShpGfxInfo.FillClr = WHITE;
		ShpGfxInfo.isFilled = false;
	}
	else {
		ShpGfxInfo.FillClr = color(Fill[0], Fill[1], Fill[3]);
		ShpGfxInfo.isFilled = true;
	}



}