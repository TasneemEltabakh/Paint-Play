#include "Square.h"
#include <fstream>
#include <iostream>

Square::Square(Point P1, int s , GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	
	Corner1 = P1;
	side = s; 
	Corner2.x = (P1.x + s*50);
	Corner2.y = (P1.y + s*50);

	




	}


Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a r on the screen	
	pUI->DrawSquare(Corner1, Corner2, ShpGfxInfo);   

}
void Square:: Save(ofstream& outfile) {  //Rghda added
	//I tried to put the coordinate in a single line
		//and the colors in another one, but it will make it hard for load function
		  ////////////////////////////////////////////////////
		 //name,id,corners x , y,drawclr,borderwdth,fillclr//
		////////////////////////////////////////////////////

	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int id = 4;

	outfile << "sQUARE" << " " << id << " "    //the name and id
		<< Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " "; //the corners

	outfile << redcolorlevel << " " << greencolorlevel << " " << bluecolorlevel << " ";

	outfile << ShpGfxInfo.BorderWdth << " ";

	if (ShpGfxInfo.isFilled != true)
		outfile << "0 0 0" << " ";
	else
		outfile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " "
		<< (int)ShpGfxInfo.FillClr.ucBlue << " ";

	outfile << endl;
} 

string Square::PrintOnTool()
{
	int id = 4;
	string values = "you selected a square,ID: " + to_string(id) + "\n . First Point: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "). Second Point: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ").";
	return values;
}


bool Square::IsShapeExisting(int x, int y)  //Rghda added
{
	return false;
}

void Square::Load(ifstream& inputfile) {
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

	cout << "s" << Corner1.x << Corner1.y << Corner2.x << Corner2.y << endl;
	cout << "square loaded";
}