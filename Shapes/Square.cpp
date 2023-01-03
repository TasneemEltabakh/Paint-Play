#include "Square.h"
#include <fstream>
#include <iostream>

Square::Square(Point P1, int s , GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	
	Corner1 = P1;
	side = s; 
	diagonl = sqrt(pow(side, 2) + pow(side, 2));
	generatingCorners();



}
void Square:: generatingCorners()
{
	double pi = 3.14;
	Corner2.x = (Corner1.x + side * 50);
	Corner2.y = (Corner1.y + side * 50);
	center.x = (Corner1.x + (diagonl / 2)) ;
	center.y = (Corner1.y + (diagonl / 2));



}
void Square::Resize(double n)
{
	side = side * n;
	generatingCorners();

}
void Square::Rotate()
{}
void Square::zoom(double s, int x, int y)
{
	Corner1.x = (Corner1.x * s) - (s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s) - (s * x) + x;
	Corner2.y = (Corner2.y * s) - (s * y) + y;

}
void Square::ResizeThisbydrag(Point corner, int  xto, int yto)
{
	/*double d1 = sqrt(pow(Corner1.x - Center.x, 2) + pow(Corner1.y - Center.y, 2));
	double d2 = sqrt(pow(xto - Center.x, 2) + pow(yto - Center.y, 2));
	double s = d2 / d1;
	Resize(s);*/
	
	
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
	string values = "you selected a square,ID: " + to_string(id) + "\n . First Point: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "). Second Point: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")" + "). side long: " + to_string(side) + ".";
	return values;
}


bool Square::IsShapeExisting(int x, int y)  //Rghda added
{
	if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
	/*
	if (Corner2.x > Corner1.x && Corner2.y > Corner1.y) {
		if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (Corner2.x > Corner1.x && Corner1.y > Corner2.y) {
		if ((x > Corner1.x && x < Corner2.x && y > Corner2.y && y < Corner1.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (Corner1.x > Corner2.x && Corner2.y > Corner1.y) {
		if ((x > Corner2.x && x < Corner1.x && y > Corner1.y && y < Corner2.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (Corner1.x > Corner2.x && Corner1.y > Corner2.y) {
		if ((x > Corner2.x && x < Corner1.x && y > Corner2.y && y < Corner1.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/
}
void Square::Move(int x, int y) {   //Rghda Salah

}


void Square::Load(ifstream& inputfile) {
	int redcolorlevel = (int)ShpGfxInfo.DrawClr.ucRed;
	int greencolorlevel = (int)ShpGfxInfo.DrawClr.ucGreen;
	int bluecolorlevel = (int)ShpGfxInfo.DrawClr.ucBlue;
	int rf, gf, bf;

	inputfile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y>>
		redcolorlevel >> greencolorlevel >> bluecolorlevel >> ShpGfxInfo.BorderWdth >> rf >> gf >> bf;
	cout << "id "<< ID<< "size is  " << side << " s1 " << Corner1.x << " " << Corner1.x << " ";
	//Corner2.x = (Corner1.x + side * 50);
	//Corner2.y = (Corner1.y + side * 50);

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
		cout << rf << gf << bf << endl;
	}

}