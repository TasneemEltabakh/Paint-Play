#pragma once
#pragma once

#include "Shape.h"
#include "..//GUI/GUI.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int numberofSide;
	int arrayX[4];
	int arrayY[4];
public:
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	void Save(ofstream& GUIFile); //Rghda added
};

