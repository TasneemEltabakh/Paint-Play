#include "Oval.h"
#include <fstream>
#include <iostream>

Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

}
Oval :: ~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	
	//Call Output::DrawTriangle to draw a Triangle on the screen	
	pUI->DrawEllipse(Corner1,Corner2, ShpGfxInfo);
}

void Oval::Save(ofstream& outfile) {   //Rghda added
	//I tried to put the coordinate in a single line
	//and the colors in another one, but it will make it hard for load function
	  ////////////////////////////////////////////////////
	 //name,id,corners x , y,drawclr,borderwdth,fillclr//
	////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = ID;

	outfile << "Oval" << " " << id << " "    //the name and id
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


string Oval::PrintOnTool()  //Rghda added
{
	string values = "you selected a Oval ,ID: " + to_string(ID) + "\n . Center: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + ").";
	return values;
}


bool Oval::IsShapeExisting(int x, int y)  //Rghda added
{
	int b = Corner2.y - Corner1.y;
	int a = Corner1.x - Corner2.x;
	if ((pow((x - Corner1.x), 2) / pow((a), 2))+ (pow((y - Corner2.y), 2) / pow((b), 2))<=1){
		return true;
	}
	else {
		return false;
	}
	return false;
}