#include "Line.h"
#include <iostream>
#include <fstream>
#include "Shape.h"


#include "Line.h"
//#include <iostream>
#include <fstream>


Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	dist = sqrt(pow(Corner1.x - Corner2.x, 2) + pow(Corner1.y - Corner2.y, 2));	
	midPoint.x = (Corner1.x + Corner2.x) / 2;
	midPoint.y= (Corner1.y + Corner2.y) / 2;
}

Line :: ~Line()
{}
void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine  to draw a Line on the screen	
	pUI->DrawLine(Corner1, Corner2, ShpGfxInfo);
}
void Line::Resize(double n)
{
	dist = n * dist;
	Corner2.x = Corner1.x + dist;
	Corner2.y = Corner1.y + dist;
}
void Line::zoomin(GUI* pUI)
{


}
void Line::Rotate()
{
	int sparx1 = Corner1.x;
	int spary1 = Corner1.y;
	int sparx2 = Corner2.x;
	int spary2 = Corner2.y;

	Corner1.x = -spary1 + midPoint.y + midPoint.x;
	Corner1.y = sparx1 - midPoint.x + midPoint.y;
	Corner2.x = -spary2 + midPoint.y + midPoint.x;
	Corner2.y = sparx2 - midPoint.x + midPoint.y;
}

//RAGHDA'S PARTT 
void Line::Save(ofstream& outfile) {   //Rghda added
	//I tried to put the coordinate in a single line
	//and the colors in another one, but it will make it hard for load function
	  ////////////////////////////////////////////////////
	 //name,id,corners x , y,drawclr,borderwdth,fillclr//
	////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = 8;

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
	int id = 8;
	string values = "you selected a Line,ID: " + to_string(id) + "\n . First Point: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "). Second Point: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ").";
	return values;
}


bool Line::IsShapeExisting(int x, int y)  //Rghda added  //It didn't work from first tims< so I have to put many if condition to test where is the error
{
	double slope = (Corner2.y - Corner1.y) / (Corner2.x - Corner1.x);
	/*if ((Corner1.y> Corner2.y  && Corner2.x> Corner1.x )|| (Corner2.y > Corner1.y) && Corner1.x > Corner2.x){
		slope = abs((Corner1.y - Corner2.y) / (Corner1.x - Corner2.x));
	}
	else if(((Corner1.y > Corner2.y && Corner1.x > Corner2.x) ) ||( Corner2.y > Corner1.y && Corner2.x > Corner1.x)) {
		slope = -1*abs((Corner2.y - Corner1.y) / (Corner2.x - Corner1.x));
	}*/

	double conctant = Corner1.y - (slope * Corner1.x);

	cout << x <<"  " << y << endl;

	cout << Corner1.x <<"  "<< Corner1.y;

	if (y == (slope * x) + conctant) {
		return true;
	}
	else {
		return false;
	}


	return false;
}

void Line::Load(ifstream& inputfile) {

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
		cout << bf << rf << gf << "green??" << endl;
	}

	cout << "l" << Corner1.x << Corner1.y << Corner2.x << Corner2.y << "line loaded" <<endl;
}