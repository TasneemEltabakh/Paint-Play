#pragma once
#pragma once

#include "..//Shapes/Shape.h"
#include "..//GUI/GUI.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int side;

public:
	Square(Point, int, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;

	void Save(ofstream& outfile); //Rghda added
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
};

