#include "Rect.h"
#include <fstream>
#include <iostream>
#include<string>
using namespace std;

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
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