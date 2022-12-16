#pragma once
//circle 
using namespace std;
#pragma once
#include "shape.h"
#include "../GUI/GUI.h"

class Circle : public shape 
{
private:
	Point Corner1;
	Point Corner2;
	int radious;
public:
	Circle(Point P1, Point P2, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	void Save(ofstream& GUIFile); //Rghda added
};



