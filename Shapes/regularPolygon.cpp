#include "regularPolygon.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include<string>
using namespace std;


regularPolygon ::regularPolygon(Point P1, Point P2, int Sides,  GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	
	const double pi = 3.14159;
	Center.x = P1.x;
	Center.y = P1.y;
	start.x = P2.x;
	start.y = P2.y;
	
	r = sqrt(pow((P1.x - P2.x),2) + pow((P1.y - P2.y),2));
    int NumberOfsides = Sides;
	


	for (int i = 0; i < NumberOfsides; i++)
	{
		angle = i* (2 * pi) / NumberOfsides;
		double xOfvertix =  r * cos(angle)  + Center.x;
		arrayX.push_back(xOfvertix);
		double yOfvertix =  r * sin(angle) + Center.y ;
		arrayY.push_back(yOfvertix);
		
		
	}
	//arrayY.push_back(arrayY.front());
	//arrayX.push_back(arrayX.front());
	a = &arrayX[0];
	b = &arrayY[0];
}
regularPolygon:: ~regularPolygon()
{}
void  regularPolygon::Draw(GUI* pUI) const
{
	int numberofv = arrayY.size();
	pUI->DrawPol(a, b, numberofv, ShpGfxInfo);
}

void regularPolygon::Save(ofstream& outfile) {  //Rghda added
	
	////////////////////////////////////////////////////
	//name,id,corners x , y,drawclr,borderwdth,fillclr//
   ////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = ID;

	outfile << "Regular Polygon" << " " << id << " "
	<< Center.x << " " << Center.y << " "
	<< start.x << " " << start.y << " ";

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

	return"here the ifo of regular should appear";
}
bool regularPolygon::IsShapeExisting(int x, int y) {  //Rghda added  //I should put the function here
	return false;
} 

void regularPolygon::Load(ifstream& inputfile) {
	//GUI* pUI = ;
	int Draw[3], Fill[3];

	inputfile >> ID >> Center.x >> Center.y >> start.x >> start.y >>
		Draw[0] >> Draw[1] >> Draw[2] >> ShpGfxInfo.BorderWdth >> Fill[0] >> Fill[1] >> Fill[2];

	ShpGfxInfo.DrawClr = color(Draw[0], Draw[1], Draw[2]);

	if (Fill[0] == Fill[1] == Fill[2] == 0)
	{
		ShpGfxInfo.FillClr = WHITE;
		ShpGfxInfo.isFilled = false;
	}
	else {
		ShpGfxInfo.FillClr = color(Fill[0], Fill[1], Fill[2]);
		ShpGfxInfo.isFilled = true;
	}

	cout << "s" << Center.x << Center.y << start.x << start.y << endl;
	cout << "square loaded";
}