#include "Line.h"
//#include <iostream>
#include <fstream>


Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	
Line :: ~Line ()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine  to draw a Line on the screen	
	pUI->DrawLine(Corner1, Corner2, ShpGfxInfo);
}

void Line::Save(ofstream& outfile) {   //Rghda added
	//I tried to put the coordinate in a single line
	//and the colors in another one, but it will make it hard for load function
	  ////////////////////////////////////////////////////
	 //name,id,corners x , y,drawclr,borderwdth,fillclr//
	////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = ID;

	outfile << "Line" << " " << id << " "    //the name and id
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


string Line::PrintOnTool()
{
	string values = "you selected a Line,ID: " + to_string(ID) + "\n . First Point: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "). Second Point: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ").";
	return values;
}


bool Line::IsShapeExisting(int x, int y)  //Rghda added
{
	
	int slope = (Corner1.y- Corner2.y) / (Corner1.x- Corner2.x);
	int conctant = Corner1.y -(slope* Corner1.x);

	if (y == slope * x + conctant) {
		return true;
	}
	else {
		return false;
	}
	
}