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
	Point center;

public:
	Oval(Point P1, Point P2, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
	void Save(ofstream& GUIFile); //Rghda added
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
	void Load(ifstream& inputfile);
	void Resize(double n);
	void Rotate();
};



