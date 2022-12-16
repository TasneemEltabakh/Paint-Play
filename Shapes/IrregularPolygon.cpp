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
	int id = ID;

	outfile << "Irr Regular Polygon" << " " << id << " "
	<< point1.x << " " << point1.y << " "
	<< point2.x << " " << point2.y << " "
	<<point3.x << " " << point3.y << " ";

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

	string values = "you selected a IrregularPolygon,ID: " + to_string(ID) + 
	"\n . First Point: (" + to_string(point1.x) + ", " + to_string(point1.y) + 
		"). Second Point: (" + to_string(point2.x) + ", " + to_string(point2.y) + ")."+
		"\n . Third Point: (" + to_string(point3.x) + ", " + to_string(point3.y) + 
		"). Fourth Point: (" + to_string(point4.x) + ", " + to_string(point4.y) + ")."+
		"\n . Fifth Point: (" + to_string(point5.x) + ", " + to_string(point5.y) + 
		"). six Point: (" + to_string(point6.x) + ", " + to_string(point6.y) + ").";
	return values;
}
bool IrregularPolygon::IsShapeExisting(int x, int y) {  //Rghda added  I should edit this and put its data 
	return false;

}