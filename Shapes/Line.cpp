#include "Line.h"
#include <iostream>
#include <fstream>
#include "Shape.h"


#include "Line.h"
//#include <iostream>
#include <fstream>


Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	srand(time(0));
	ID = rand() % 100;
	Corner1 = P1;
	Corner2 = P2;
	dist = sqrt(pow(Corner1.x - Corner2.x, 2) + pow(Corner1.y - Corner2.y, 2));	
	midPoint.x = (Corner1.x + Corner2.x) / 2;
	midPoint.y= (Corner1.y + Corner2.y) / 2;
	this->id = nullptr;
	ishidden = false;

}
void Line::hide()
{
	ishidden = true;

}
int Line::returnId()
{
	return ID;
}
void Line::setId(int newid)
{
	ID = newid;
}
void Line::unhide()
{
	ishidden = false;

}
bool  Line::isHidden()
{
	return ishidden;
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
void  Line::zoom(double s, int x, int y)
{
	Corner1.x = (Corner1.x * s) - (s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s) - (s * x) + x;
	Corner2.y = (Corner2.y * s) - (s * y) + y;
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
void Line::ResizeThisbydrag(Point corner, int  xto, int yto)
{

	Corner1.x = xto;
	Corner1.y = yto;
	this->id = nullptr;
}
int* Line::GetID()
{
	return this->id;
}
void Line::SetgroupCenter(Point p)

{

}
shape* Line::GDuplicateShape() {
	shape* creatnewshape = new Line(Corner1, Corner2, ShpGfxInfo);
	creatnewshape->setId(ID);
	return creatnewshape;
}
void Line::scramble(Point p)
{
	int difX = Corner1.x - p.x;
	int difY = Corner1.y - p.y;
	Corner1 = p;
	Corner2.x -= difX; 
	Corner2.y -= difY;
}

Point Line::getCenter()
{
	return midPoint;
}
void  Line::setID(int* id)
{
	this->id = id;
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
void Line::Move(int x, int y) {   //Rghda Salah
	/*Point corner3 = {Corner1.x,Corner2.y};
	int l = sqrt(pow(corner3.x - Corner2.x, 2) + pow(corner3.y - Corner2.y, 2));
	int w = sqrt(pow(corner3.x - Corner1.x, 2) + pow(corner3.y - Corner1.y, 2));
	Corner1.x = (x);
	Corner1.y = (y);
	Corner2.x = (x + l);
	Corner2.y = (y + w);*/
	Point p2;
	p2.x = -(Corner1.x - Corner2.x) + x;
	p2.y = -(Corner1.y - Corner2.y) + y;
	Corner1.x = (x);
	Corner1.y = (y);
	Corner2.x = p2.x;
	Corner2.y = p2.y;
}
Point Line::firstxofshape() {
	return Corner1;
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

	cout << "l" << Corner1.x << Corner1.y << Corner2.x << Corner2.y << "line loaded" << endl;
};

shape* Line::Copy() {
	shape* copiedshape = new Line(Corner1, Corner2, ShpGfxInfo);
	return copiedshape;
}