#include "IrregularPolygon.h"
#include <fstream>
#include <iostream>
#include<string>
using namespace std;


IrregularPolygon::IrregularPolygon(vector<Point> arrayv, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	for (int i = 0; i < arrayv.size(); i++)
	{
		arrayX.push_back(arrayv[i].x);
		arrayY.push_back(arrayv[i].y);
	}
	
	arrayY.push_back(arrayY.front());
    arrayX.push_back(arrayX.front());
	a = &arrayX[0];
	b = &arrayY[0];
	numberofsides = arrayX.size();
  
}
IrregularPolygon :: ~IrregularPolygon()
{
}

void IrregularPolygon::Resize(double n)
{
	for (int i = 0; i < arrayX.size(); i++)
	{
		arrayX[i] = arrayX[i] * n;
		arrayY[i] = arrayY[i] * n;
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
	int c2 = 0;
	int slope;
	int constant;
	for (int i = 0; i < arrayX.size(); i++) {

		slope = (arrayY[i] - arrayY[i + 1]) / (arrayX[i] - arrayX[i + 1]);
		constant = arrayY[i] - (slope * arrayX[i]);
		if (y == slope * x + constant) {
			c1 = c1 + 1;
		}

		if (c1 % 2 != 0) {   //if it is odd  it is outside the shape
			return false;
		}
		else {  //if the number of intersection is even  so it is inside the shape
			return true;
		}
	}
	//return false;

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