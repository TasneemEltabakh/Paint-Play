#include "Rect.h"
#include <fstream>
#include <iostream>
#include<string>
#include "..//controller.h"
using namespace std;

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	check = 0;
	Corner1 = P1;
	v.push_back(Corner1);
	Corner2 = P2;
	v.push_back(Corner2);
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	pUI->DrawRect(v[0], v[1], ShpGfxInfo);
}

void Rect::Resize(double n)
{ 
	v.clear();

	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;

	P.x = (Corner1.x * n) - ( n * center.x) + center.x;
	P.y = (Corner1.y * n) - (n * center.y) + center.y;
	R.x = (Corner2.x * n) - (n * center.x) + center.x;
	R.y = (Corner2.y * n) - (n * center.y) + center.y;

	v.push_back(P);
	v.push_back(R);



}
void Rect::Rotate()
{

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