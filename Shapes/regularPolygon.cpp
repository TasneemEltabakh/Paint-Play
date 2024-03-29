#include "regularPolygon.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include<string>


regularPolygon ::regularPolygon(Point P1, Point P2, int Sides,  GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	
	srand(time(0));
	ID = rand() % 100;
	Center.x = P1.x;
	Center.y = P1.y;
	start.x = P2.x;
	start.y = P2.y;
	this->id = nullptr;
	r = sqrt(pow((P1.x - P2.x),2) + pow((P1.y - P2.y),2));
    NumberOfsides = Sides;
	generatingPoints();
	a = &arrayX[0];
	b = &arrayY[0];
	ishidden = false;

}
regularPolygon:: ~regularPolygon()
{}
shape* regularPolygon::GDuplicateShape() {
	shape* creatnewshape = new regularPolygon(Center, start,r, ShpGfxInfo);
	creatnewshape->setId(ID);
	return creatnewshape;
}
void regularPolygon :: scramble(Point p)
{
	/*Center.x = rand() % 800;
	Center.y = rand() % 300;

	for (int i = 0; i < NumberOfsides; i++)
	{
		arrayX.at(i) = arrayX[i] + Center.x;
		arrayY.at(i) = arrayY[i]  + Center.y;
	}*/

}
void regularPolygon::unhide()
{
	ishidden = false;

}
void regularPolygon::generatingPoints()
{
	
	for (int i = 0; i < NumberOfsides; i++)
	{
		angle = i * (2 * pi) / NumberOfsides;
		double xOfvertix = r * cos(angle) + Center.x;
		arrayX.push_back(xOfvertix);
		double yOfvertix = r * sin(angle) + Center.y;
		arrayY.push_back(yOfvertix);

	}
}
int regularPolygon::returnId()
{
	return ID;
}
void regularPolygon::setId(int newid)
{
	ID = newid;
}
void  regularPolygon::zoom(double s, int x, int y)
{

	for(int i = 0; i < NumberOfsides; i++)
	{
		double TempX = arrayX[i];
		double TempY = arrayY[i];
		
		double xOfvertix = (TempX * s) - (s * x) + x;
		arrayX.at(i) = xOfvertix;
		double yOfvertix = (TempY * s) - (s * y) + y;
		arrayY.at(i) = yOfvertix;


	}
	
}

int* regularPolygon::GetID()
{
	return this->id;
}
void regularPolygon::Resize(double n)
{

	for (int i = 0; i < NumberOfsides; i++)
	{
		arrayX.at(i) = (arrayX[i] * n) - (n * Center.x) + Center.x;
		arrayY.at(i) = (arrayY[i] * n) - (n * Center.y) + Center.y;
	}
	
;
}
void regularPolygon::Rotate()
{
	for (int i = 0; i < NumberOfsides; i++)
	{
		double TempX = arrayX[i];
		double TempY = arrayY[i];
		
		double xOfvertix =  - TempY + Center.y + Center.x;
		arrayX.at(i) = xOfvertix;
		double yOfvertix = TempX - Center.x + Center.y;
		arrayY.at(i) = yOfvertix;

	}
}
void regularPolygon::ResizeThisbydrag(Point corner, int  xto, int yto)
{

	double d1 = sqrt(pow(arrayX[0] - Center.x, 2) + pow(arrayY[0] - Center.y, 2));
	double d2 = sqrt(pow(xto - Center.x, 2) + pow(yto - Center.y, 2));
	double s = d2 / d1;
	Resize(s);

}
void regularPolygon::SetgroupCenter(Point p)
{
	
}
Point regularPolygon::getCenter()
{
	return Center;
}
void  regularPolygon::setID(int* id)
{
	this->id = id;
}

void  regularPolygon::Draw(GUI* pUI) const
{
	int numberofv = arrayY.size();
	pUI->DrawPol(a, b, numberofv, ShpGfxInfo);
}
void regularPolygon::hide()
{
	ishidden = true;

}
bool  regularPolygon::isHidden()
{
	return ishidden;
}

void regularPolygon::Save(ofstream& outfile) {  //Rghda added
	
	////////////////////////////////////////////////////
	//name,id,corners x , y,drawclr,borderwdth,fillclr//
   ////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id= 6;

	outfile << "Reg" << " " << NumberOfsides << " " << id << " ";
	//<< Center.x << " " << Center.y << " "
	//<< start.x << " " << start.y << " ";
	for (int i = 0; i < arrayX.size(); i++)
	{
		outfile << arrayX[i] <<" " << arrayY[i]<<" ";
	}

	outfile << redcolorlevel << " " << greencolorlevel << " " << bluecolorlevel << " ";

	outfile << ShpGfxInfo.BorderWdth << " ";

	if (ShpGfxInfo.isFilled != true)
		outfile << "0 0 0" << " " ;
	else
		outfile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " "
		<< (int)ShpGfxInfo.FillClr.ucBlue << " " ;

	outfile << endl;
} 

string regularPolygon::PrintOnTool() {  //Rghda added
	int id = 6;
	string values = "you selected a RegularPolygon,ID: " + to_string(id)+", " + to_string(NumberOfsides) + "sides";
	string onepoint;

	for (int i = 0; i < arrayX.size(); i++)
	{
		onepoint = " Point" + to_string(i + 1) + ": (" + to_string(arrayX[i]) + ", " + to_string(arrayY[i]) + ") ";
		values = values + onepoint;
	}
	return values;
}

float regularPolygon::trianglearea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool regularPolygon::IsShapeExisting(int x, int y) {  //Rghda added  //I should put the function here

	float discenterclickedpoint = sqrt(pow((Center.x - x), 2) + pow((Center.y - y), 2));
	float radious = sqrt(pow((Center.x - start.x), 2) + pow((Center.y - start.y), 2));
	if (discenterclickedpoint <= radious) {
		return true;
	}
	else {
		return false;
	}

	return false;
} 

void regularPolygon::Move(int x, int y) {   //Rghda Salah
	//cout << Center.x <<endl<< Center.y <<endl<< start.x <<endl<< start.y << endl << endl << endl;
	Point corner3 = { start.x,Center.y };
	int l = sqrt(pow(corner3.x - start.x, 2) + pow(corner3.y - start.y, 2));
	int w = sqrt(pow(corner3.x - Center.x, 2) + pow(corner3.y - Center.y, 2));
	Center.x = (x);
	Center.y = (y);
	start.x = (x - l);
	start.y = (y - w);
	//cout << Center.x << endl << Center.y << endl << start.x << endl << start.y << endl << endl << endl;
}
Point regularPolygon::firstxofshape() {
	return Center;
}

void regularPolygon::Load(ifstream& inputfile) {

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int rf, gf, bf;

	inputfile >> ID;

	for (int i = 0; i < NumberOfsides; i++)
	{
		inputfile >> arrayX[i] >> arrayY[i];
	}

	inputfile >> redcolorlevel >> greencolorlevel >> bluecolorlevel >> ShpGfxInfo.BorderWdth >> rf >> gf >> bf;

	a = &arrayX[0];
	b = &arrayY[0];

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

shape* regularPolygon::Copy() {
	shape* copiedshape = new regularPolygon(Center ,start, NumberOfsides, ShpGfxInfo);
	return copiedshape;
}