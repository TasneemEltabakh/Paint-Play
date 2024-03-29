#include "Triangle.h"
#include <fstream>
#include <iostream>
#include<string>
using namespace std;

Triangle :: Triangle (Point P1, Point P2, Point P3 , GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	srand(time(0));
	ID = rand() % 100;
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y= (Corner1.y + Corner2.y + Corner3.y) / 3 ;
	id = nullptr;
	ishidden = false;
}

Triangle :: ~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{	
	
	pUI->DrawTriangle(Corner1, Corner2, Corner3, ShpGfxInfo);
	
}

void Triangle::Resize(double n)
{

	Corner1.x = Corner1.x * n - (n * Center.x) + Center.x;
	Corner1.y = Corner1.y * n - (n * Center.y) + Center.y;
	Corner2.x = Corner2.x * n - (n * Center.x) + Center.x;
	Corner2.y = Corner2.y * n - (n * Center.y) + Center.y;
	Corner3.x = Corner3.x * n - (n * Center.x) + Center.x;
	Corner3.y = Corner3.y * n - (n * Center.y) + Center.y;
	

}
void Triangle::ResizeThisbydrag(Point corner, int  xto, int yto)
{
	double d1 = sqrt(pow(Corner1.x - Center.x, 2) + pow(Corner1.y - Center.y, 2));
	double d2 = sqrt(pow(xto- Center.x, 2) + pow(yto - Center.y, 2));
	double s = d2 / d1;
	Resize(s);

}
void Triangle::Rotate()
{
	

	int sparx1 = Corner1.x;
	int spary1 = Corner1.y;
	int sparx2 = Corner2.x;
	int spary2 = Corner2.y;
	int sparx3 = Corner3.x;
	int spary3 = Corner3.y;
	

	Corner1.x =  -spary1 + Center.y + Center.x;
	Corner1.y = sparx1 - Center.x + Center.y;
	Corner2.x =  -spary2 + Center.y + Center.x;
	Corner2.y = sparx2 - Center.x + Center.y;
	Corner3.x =  -spary3 + Center.y + Center.x;
	Corner3.y = sparx3 - Center.x + Center.y;

}
void Triangle::zoom(double s, int x, int y)
{
	
	
	Corner1.x = (Corner1.x * s) - (s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s) - (s * x) + x;
	Corner2.y = (Corner2.y * s) - (s *y)  + y;
	Corner3.x = (Corner3.x * s) - (s * x) + x;
	Corner3.y = (Corner3.y * s) - (s * y) + y;

}
shape* Triangle::GDuplicateShape() {

	shape* creatnewshape = new Triangle(Corner1, Corner2, Corner3, ShpGfxInfo);
	creatnewshape->setId(ID);
	return creatnewshape;
}
void Triangle::scramble(Point p)
{
	
	/*Center.x = rand() % 800;
	Center.y =  rand() % 500;
	Corner1.x = Corner1.x + Center.x;
	Corner1.y = Corner1.y + Center.y ;
	Corner2.x = Corner2.x + Center.x;
	Corner2.y = Corner2.y + Center.y;
	Corner3.x = Corner3.x +Center.x;
	Corner3.y = Corner3.y + Center.y;*/

	int difX = Corner1.x - p.x;
	int difY = Corner1.y - p.y;
	Corner1 = p;
	Corner2.x -= difX; 
	Corner2.y -= difY;
	Corner3.x -= difX; 
	Corner3.y -= difY;

}
void Triangle::SetgroupCenter(Point p)

{
	Center.x = p.x;
	Center.y = p.y;

}
void Triangle::hide()
{
	ishidden = true;
	
}
void Triangle::unhide()
{
	ishidden = false;

}
bool  Triangle::isHidden()
{
	return ishidden;
}

Point Triangle:: getCenter()
{
	return Center;
}
void Triangle:: setID(int* id)
{
	this->id = id;
}
int* Triangle::GetID()
{
	return this->id;
}
float Triangle::trianglearea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
int Triangle::returnId()
{
	return ID;
}
void Triangle::setId(int newid)
{
	ID = newid;
}

bool Triangle::IsShapeExisting(int x, int y)
{
	float temp = trianglearea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float try1 = trianglearea(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	//float try2 = trianglearea(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	//float try3 = trianglearea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	float try2 = trianglearea(x, y, Corner1.x, Corner1.y, Corner3.x, Corner3.y);
	float try3 = trianglearea(x,y , Corner2.x, Corner2.y, Corner1.x, Corner1.y);
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
	int id = 3;
	string values;;
	float getarea = trianglearea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	values = "you selected a TRIANGLE. ID: " + to_string(id) + 
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
	int id = 3;

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

void Triangle::Move(int x, int y) {   //Rghda Salah
	/*Point crepn = {Corner2.x,Corner1.y};
	int l = sqrt(pow(crepn.x - Corner2.x, 2) + pow(crepn.y - Corner2.y, 2));
	int w = sqrt(pow(crepn.x - Corner1.x, 2) + pow(crepn.y - Corner1.y, 2));
	Point ctepn2 = { Corner3.x,Corner1.y };
	int l2 = sqrt(pow(ctepn2.x - Corner3.x, 2) + pow(ctepn2.y - Corner3.y, 2));
	int w2 = sqrt(pow(ctepn2.x - Corner1.x, 2) + pow(ctepn2.y - Corner1.y, 2));
	Corner1.x = (x);
	Corner1.y = (y);
	Corner2.x = (x + w);
	Corner2.y = (y + l);
	Corner3.x = (x - w2);
	Corner3.y = (y + l2);*/
	Point p2, p3;
	p2.x = -(Corner1.x - Corner2.x) + x;
	p2.y = -(Corner1.y - Corner2.y) + y;
	p3.x = -(Corner1.x - Corner3.x) + x;
	p3.y = -(Corner1.y - Corner3.y) + y;
	Corner1.x = x;
	Corner1.y = y;
	Corner2.x = p2.x;
	Corner2.y = p2.y;
	Corner3.x = p3.x;
	Corner3.y = p3.y;

	
	
}
Point Triangle::firstxofshape() {
	return Corner1;
}
void Triangle::Load(ifstream& inputfile) {

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int rf, gf, bf;

	inputfile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >>
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

	};

};

shape* Triangle::Copy() {
	shape* copiedshape = new Triangle(Corner1, Corner2, Corner3, ShpGfxInfo);
	return copiedshape;
}