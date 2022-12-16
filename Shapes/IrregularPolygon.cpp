#include "IrregularPolygon.h"
#include <fstream>
#include <iostream>
#include<string>
using namespace std;


IrregularPolygon::IrregularPolygon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	
	point1 = p1;
	point2 = p2;
    point3 = p3;
	point4 = p4;
	point5 = p5;
	point6 = p6;
}
IrregularPolygon :: ~IrregularPolygon()
{

}
void IrregularPolygon::Draw(GUI* pUI) const
{
	int arrayX[6] = { point1.x, point2.x, point3.x , point4.x  , point5.x , point6.x };
	int arrayY[6] = { point1.y ,point2.y ,  point3.y  , point4.y  ,point5.y  , point6.y };
	pUI->DrawPol(arrayX, arrayY, 6, ShpGfxInfo);
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