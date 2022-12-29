#pragma once
#pragma once

#include "..//Shapes/Shape.h"
#include "..//GUI/GUI.h"
#include <vector>

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int side;
	Point center;
	double diagonl;
	vector<int> arrayX;
	vector<int> arrayY;
public:
	Square(Point, int, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	void generatingCorners();
	void Save(ofstream& outfile); //Rghda added
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
	void Load(ifstream& inputfile);
	void Resize(double n);
	void Rotate();
	void zoomin(GUI* pUI);
};

