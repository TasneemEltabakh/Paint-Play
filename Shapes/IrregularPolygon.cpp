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

	outfile << "Irr Regular Polygon" << " " << id << " ";
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

	string values = "you selected a IrregularPolygon,ID: " + to_string(ID) + to_string(numberofsides) + "sides";
		for (int i = 0; i < arrayX.size(); i++)
		{
			values = " Point" + to_string(i + 1) + ": (" + to_string(arrayX[i]) + ", " + to_string(arrayY[i]) + ") ";
		}
	
	return values;
}
bool IrregularPolygon::IsShapeExisting(int x, int y) {  //Rghda added  I should edit this and put its data 
	return false;

}

/*/void IrregularPolygon::Load(ifstream& inputfile) {
	//GUI* pUI = ;
	int Draw[3], Fill[3];

	inputfile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >>
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

	cout << "x" << Corner1.x << Corner1.y << Corner2.x << Corner2.y << endl;
	cout << "tyoe is";
}/**/