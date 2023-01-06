#include "Rect.h"
#include <fstream>
#include <iostream>
#include<string>
#include "..//controller.h"
using namespace std;

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	
	Corner1 = P1;
	Corner2 = P2;
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
	this->id = nullptr;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	pUI->DrawRect(Corner1,Corner2, ShpGfxInfo);
}

void Rect::Resize(double n)
{ 
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
	
	Corner1.x = (Corner1.x * n) - ( n * center.x) + center.x;
	Corner1.y = (Corner1.y * n) - (n * center.y) + center.y;
	Corner2.x = (Corner2.x * n) - (n * center.x) + center.x;
	Corner2.y = (Corner2.y * n) - (n * center.y) + center.y;




}
void Rect::ResizeThisbydrag(Point corner, int  xto, int yto)
{

	Corner1.x = xto;
	Corner1.y = yto;

}

void Rect::Rotate()
{

	int sparx1 = Corner1.x;
	int spary1 = Corner1.y;
	int sparx2 = Corner2.x;
	int spary2 = Corner2.y;

	Corner1.x = -spary1 + center.y + center.x;
	Corner1.y = sparx1 - center.x + center.y;
	Corner2.x = -spary2 + center.y + center.x;
	Corner2.y = sparx2 - center.x + center.y;

}
void  Rect::zoom(double s, int x, int y)
{
	Corner1.x = (Corner1.x * s) - (s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s) - (s * x) + x;
	Corner2.y = (Corner2.y * s) - (s * y) + y;
}


void Rect::Save(ofstream& outfile){   //Rghda added
	//I tried to put the coordinate in a single line
	//and the colors in another one, but it will make it hard for load function
	  ////////////////////////////////////////////////////
	 //name,id,corners x , y,drawclr,borderwdth,fillclr//
	////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = 1;

	outfile << "RECT" << " " << id << " "    //the name and id
	<< Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " ; //the corners

	outfile << redcolorlevel << " " << greencolorlevel << " " << bluecolorlevel << " ";

	outfile << ShpGfxInfo.BorderWdth <<" ";

	if (ShpGfxInfo.isFilled != true)
		outfile << "0 0 0" << " " ;
	else
		outfile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " "
		<< (int)ShpGfxInfo.FillClr.ucBlue << " " ;

	outfile << endl;
}
void Rect::SetgroupCenter(Point p)
{

}
void  Rect::scramble()
{

}
void  Rect::hide()
{

}
Point Rect::getCenter()
{
	return Corner1;
}
void  Rect::setID(int* id)
{
	this->id = id;
}
int* Rect::GetID()
{
	return this->id;
}
string Rect::PrintOnTool()
{
	int id = 1;

	string values = "you selected a rectangle,ID: " + to_string(id) + "\n . First Point: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "). Second Point: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ").";
	return values;
}


bool Rect::IsShapeExisting(int x, int y)  //Rghda added
{
	if (Corner2.x > Corner1.x && Corner2.y > Corner1.y) {
		if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(Corner2.x > Corner1.x && Corner1.y > Corner2.y) {
		if ((x > Corner1.x && x < Corner2.x && y > Corner2.y && y < Corner1.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (Corner1.x > Corner2.x && Corner2.y > Corner1.y) {
		if ((x > Corner2.x && x < Corner1.x && y > Corner1.y && y < Corner2.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (Corner1.x > Corner2.x && Corner1.y > Corner2.y) {
		if ((x > Corner2.x && x < Corner1.x && y > Corner2.y && y < Corner1.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void Rect::Move(int x, int y) {

	/*Point corner3 = {Corner1.x,Corner2.y};  //it works too
	int l = sqrt(pow(corner3.x - Corner2.x, 2) + pow(corner3.y - Corner2.y, 2));
	int w = sqrt(pow(corner3.x - Corner1.x, 2) + pow(corner3.y - Corner1.y, 2));
	Corner1.x =  (x );
	Corner1.y =  (y );
	Corner2.x =  (x +l);
	Corner2.y =  (y +w);*/

	Point p2;
	p2.x = -(Corner1.x - Corner2.x) + x;
	p2.y = -(Corner1.y - Corner2.y) + y;
	Corner1.x = (x);
	Corner1.y = (y);
	Corner2.x = p2.x;
	Corner2.y = p2.y;
	
}
Point Rect::firstxofshape() {
	return Corner1;
}

void Rect::Load(ifstream& inputfile) {

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int rf, gf, bf;

	inputfile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y  >>
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
}