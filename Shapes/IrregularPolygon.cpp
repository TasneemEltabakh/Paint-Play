#include "IrregularPolygon.h"
#include <fstream>
#include <iostream>
#include<string>
using namespace std;


IrregularPolygon::IrregularPolygon(vector<Point> arrayv, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	srand(time(0));
	ID = rand() % 100;
	this->id = nullptr;
	double sumX = 0 , sumY = 0;
	arrayofpoints = arrayv;
	for (int i = 0; i < arrayv.size(); i++)
	{
		arrayX.push_back(arrayv[i].x);
		arrayY.push_back(arrayv[i].y);
		sumX = sumX + arrayv[i].x;
		sumY = sumY + arrayv[i].y;
	}
	
	arrayY.push_back(arrayY.front());
    arrayX.push_back(arrayX.front());

	a = &arrayX[0];
	b = &arrayY[0];

	numberofsides = arrayX.size();
	Center.x = sumX / numberofsides;
	Center.y = sumY / numberofsides;
	ishidden = false;
}
void IrregularPolygon::hide()
{
	ishidden = true;

}
bool  IrregularPolygon::isHidden()
{
	return ishidden;
}
void IrregularPolygon::unhide()
{
	ishidden = false;

}
IrregularPolygon :: ~IrregularPolygon()
{
}
int IrregularPolygon::returnId()
{
	return ID;
}
void IrregularPolygon::setId(int newid)
{
	ID = newid;
}
shape* IrregularPolygon::GDuplicateShape() {
	vector<Point>arrayv;  //I didn't sure from this
	shape* creatnewshape = new IrregularPolygon(arrayv, ShpGfxInfo);
	creatnewshape->setId(ID);
	return creatnewshape;
}
void IrregularPolygon::scramble(Point p)
{
	/*int disx = Center.x - p.x;
	int disy = Center.y - p.y;
	Center = p;
	for (int i = 0; i < numberofsides; i++)
	{
		arrayX[i] -= disx;
		arrayY[i] -= disy;
	}*/
}


void  IrregularPolygon::zoom(double s, int x, int y)
{
	for (int i = 0; i < numberofsides; i++)
	{
		double TempX = arrayX[i];
		double TempY = arrayY[i];

		double xOfvertix = (TempX * s) - (s * x) + x;
		arrayX.at(i) = xOfvertix;
		double yOfvertix = (TempY * s) - (s * y) + y;
		arrayY.at(i) = yOfvertix;


	}
}
void IrregularPolygon::Resize(double n)
{
	for (int i = 0; i < numberofsides; i++)
	{
		arrayX.at(i) = (arrayX[i] * n) - (n * Center.x) + Center.x;
		arrayY.at(i) = (arrayY[i] * n) - (n * Center.y) + Center.y;
	}
	
}
void IrregularPolygon::ResizeThisbydrag(Point corner, int  xto, int yto)
{

	double d1 = sqrt(pow(arrayX[0] - Center.x, 2) + pow(arrayY[0] - Center.y, 2));
	double d2 = sqrt(pow(xto - Center.x, 2) + pow(yto - Center.y, 2));
	double s = d2 / d1;
	Resize(s);
}
void IrregularPolygon::Rotate()
{
	for (int i = 0; i < numberofsides; i++)
	{
		double TempX = arrayX[i];
		double TempY = arrayY[i];
		double xOfvertix = -TempY + Center.y + Center.x;
		arrayX.at(i) = xOfvertix;
		double yOfvertix = TempX - Center.x + Center.y;
		arrayY.at(i) = yOfvertix;

	}
	
}
int* IrregularPolygon::GetID()
{
	return this->id;
}
void IrregularPolygon::SetgroupCenter(Point p)

{

}
Point IrregularPolygon::getCenter()
{
	return Center;
}
void  IrregularPolygon::setID(int* id)
{
	this->id = id;
}
void IrregularPolygon::Draw(GUI* pUI) const
{
	int size = arrayX.size();
	pUI->DrawPol(a, b, size, ShpGfxInfo);
}

void IrregularPolygon::Save(ofstream& outfile) {  //Rghda added
	////////////////////////////////////////////////////
	 //name,id,corners x , y,drawclr,borderwdth,fillclr//
	////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = 7;

	outfile << "Irreg"<< " "<< numberofsides<<" ";
	for (int i = 0; i < arrayX.size(); i++)
	{
		outfile << arrayX[i] << " " << arrayY[i] << " ";
	}
	
	outfile << " " << id <<" "<< redcolorlevel << " " << greencolorlevel << " " << bluecolorlevel << " ";

	outfile << ShpGfxInfo.BorderWdth << " ";

	if (ShpGfxInfo.isFilled != true)
		outfile << "0 0 0" << " " ;
	else
		outfile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " "
		<< (int)ShpGfxInfo.FillClr.ucBlue << " ";


	outfile << endl;

} 

string IrregularPolygon::PrintOnTool() {  //Rghda added
	int id = 7;
	string values = "you selected a IrregularPolygon,ID: " + to_string(id) + to_string(arrayX.size()) + "sides";
	string onepoint;
		for (int i = 0; i < arrayX.size(); i++)
		{
			 onepoint= " Point" + to_string(i + 1) + ": (" + to_string(arrayX[i]) + ", " + to_string(arrayY[i]) + ") ";
			 values = values + onepoint;
		}
	
	return values;
}
bool IrregularPolygon::IsShapeExisting(int x, int y) {  //Rghda added  I should edit this and put its data 
	int c1 = 0;

	for (int i = 0; i < arrayX.size() - 1; i++) {
		Point p1 = { arrayX[i],arrayY[i] };
		Point p2 = { arrayX[i + 1],arrayY[i + 1] };
		if (y < p1.y != y < p2.y && x < (p2.x - p1.x) * (y - p1.y) / (p2.y - p1.y) + p1.x) {
			c1 += 1;
		}

		
	}
	return c1 % 2 == 0 ? false : true;


}
void IrregularPolygon::Move(int x, int y) {   //Rghda Salah

}
Point IrregularPolygon::firstxofshape() {
	return Center;
}

void IrregularPolygon::Load(ifstream& inputfile) {

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int rf, gf, bf;

	inputfile >> ID >>
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

};

shape* IrregularPolygon::Copy() {
	shape* copiedshape = new IrregularPolygon(arrayofpoints, ShpGfxInfo);
	return copiedshape;
}