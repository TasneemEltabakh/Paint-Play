#include "ciecle.h"
#include <fstream>
#include <iostream>

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	radious = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));

}
Circle :: ~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	pUI->DrawCircle(Corner1,radious, ShpGfxInfo);
}
void Circle::Resize(double n)
{
	radious = radious * n;


}
void Circle::Rotate()
{}
void Circle::ResizeThisbydrag(Point corner, int  xto, int yto)
{


}
void  Circle::zoom(double s, int x, int y)
{
	Corner1.x = (Corner1.x * s) - (s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s) - (s * x) + x;
	Corner2.y = (Corner2.y * s) - (s * y) + y;
	radious = s * radious;
}
void Circle::Save(ofstream& outfile) {   //Rghda added
	//I tried to put the coordinate in a single line
	//and the colors in another one, but it will make it hard for load function
	  ////////////////////////////////////////////////////
	 //name,id,corners x , y,drawclr,borderwdth,fillclr//
	////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = 2;

	outfile << "Circle" << " " << id << " "    //the name and id
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


string Circle::PrintOnTool()
{
	int id = 2;
	string values = "Circle, ID:"+to_string( id)+ ", the center : (" + to_string(Corner1.x)+ ", " + to_string(Corner1.y )+ ") the radius : " + to_string(radious )+ " .";
	return values;
}


bool Circle::IsShapeExisting(int x, int y)  //Rghda added
{
	float discenterclickedpoint= sqrt(pow((Corner1.x - x), 2) + pow((Corner1.y - y), 2));
	if (discenterclickedpoint <= radious) {
		return true;
	}
	else {
		return false;
	}
}
void Circle::Move(int x, int y) {   //Rghda Salah

}

void Circle::Load(ifstream& inputfile) {

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;

	int rf, gf, bf;

	inputfile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >>
		redcolorlevel >> greencolorlevel >> bluecolorlevel >> ShpGfxInfo.BorderWdth >> rf >> gf >> bf;

	ShpGfxInfo.DrawClr.ucRed = redcolorlevel;
	ShpGfxInfo.DrawClr.ucGreen = greencolorlevel;
	ShpGfxInfo.DrawClr.ucBlue = bluecolorlevel;

	if (rf == 0 && gf == 0 && bf == 0)
	{
		ShpGfxInfo.FillClr = WHITE;
		ShpGfxInfo.isFilled = false;
	}
	else {
		ShpGfxInfo.FillClr.ucBlue = bf;
		ShpGfxInfo.FillClr.ucRed = rf;
		ShpGfxInfo.FillClr.ucGreen = gf;
		ShpGfxInfo.isFilled = true;
	}

	radious = sqrt(pow(Corner1.x - Corner2.x, 2) + pow(Corner1.y - Corner2.y, 2));

}