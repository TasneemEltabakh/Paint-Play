#include "Oval.h"
#include <fstream>
#include <iostream>

Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	center.x = Corner2.x;
	center.y = Corner1.y;
	

}
Oval :: ~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	
	//Call Output::DrawTriangle to draw a Triangle on the screen	
	pUI->DrawEllipse(Corner1,Corner2, ShpGfxInfo);
}
void Oval::Resize(double n)
{
	
	

	Corner1.x =( Corner1.x * n) - (n * center.x) + center.x;
	Corner1.y = (Corner1.y * n) - (n * center.y) + center.y;
	Corner2.x = (Corner2.x * n) - (n * center.x) + center.x;
	Corner2.x = (Corner2.x * n) - (n * center.y) + center.y;


	center.x = Corner2.x;
	center.y = Corner1.y;
}
void  Oval::zoom(double s, int x, int y)
{
	Corner1.x = (Corner1.x * s) - (s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s) - (s * x) + x;
	Corner2.y = (Corner2.y * s) - (s * y) + y;
}
void Oval ::Rotate()
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
void Oval::Save(ofstream& outfile) {   //Rghda added
	//I tried to put the coordinate in a single line
	//and the colors in another one, but it will make it hard for load function
	  ////////////////////////////////////////////////////
	 //name,id,corners x , y,drawclr,borderwdth,fillclr//
	////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = 5;

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
	int id = 5;
	string values = "you selected a Oval ,ID: " + to_string(id) + "\n . Center: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + ").";
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

void Oval::Load(ifstream& inputfile) {
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

}