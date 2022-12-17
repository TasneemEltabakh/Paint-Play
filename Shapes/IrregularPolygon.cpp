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
	
  
}
IrregularPolygon :: ~IrregularPolygon()
{
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

	outfile << "Irreg" << " " << id << " "<< numberofsides<<" ";
	for (int i = 0; i < arrayX.size(); i++)
	{
		outfile << arrayX[i] << " " << arrayY[i] << " ";
	}
	
	outfile << redcolorlevel << " " << greencolorlevel << " " << bluecolorlevel << " ";

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
	int slope;
	int conctant;
	for (int i = 0; i < arrayX.size(); i++)
	{
		
		if (i = arrayX.size() - 1) {
			slope = (arrayY[i] - arrayY[0]) / (arrayX[i] - arrayX[0]);
			conctant = arrayY[i] - (slope * arrayX[i]);
		}
		else {
			slope = (arrayY[i] - arrayY[i + 1]) / (arrayX[i] - arrayX[i + 1]);
			conctant = arrayY[i] - (slope * arrayX[i]);
		}
		

		if (y == slope * x + conctant) {
			return true;
		}
		else {
			return false;
		}
	}
	//return false;
}