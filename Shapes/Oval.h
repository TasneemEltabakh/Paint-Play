#pragma once
using namespace std;
#pragma once
#include "Shape.h"
#include "..//GUI/GUI.h"

class Oval : public shape
{
private:
	Point Corner1;
	Point Corner2;
	//int Hight ;
	//int Width;
public:
	Oval(Point P1, Point P2, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
	void Save(ofstream& GUIFile); //Rghda added
};



