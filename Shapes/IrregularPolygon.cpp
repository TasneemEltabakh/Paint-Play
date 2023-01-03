#include "IrregularPolygon.h"
#include <fstream>
#include <iostream>
#include<string>
using namespace std;


IrregularPolygon::IrregularPolygon(vector<Point> arrayv, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	double sumX = 0 , sumY = 0;

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
  
}
IrregularPolygon :: ~IrregularPolygon()
{
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
	a = &arrayX[0];
	b = &arrayY[0];

}
void IrregularPolygon::ResizeThisbydrag(Point corner, int  xto, int yto)
{


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

void IrregularPolygon::Load(ifstream& inputfile) {

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int rf, gf, bf;

	inputfile >> ID>>
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