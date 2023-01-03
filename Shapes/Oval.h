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
	double red1;
	double red2;

public:
	Oval(Point P1, Point P2, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
	void Save(ofstream& GUIFile); //Rghda added
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
	void Move(int x, int y); //Rghda Salah
	void Load(ifstream& inputfile);
	void Resize(double n);
	void Rotate();
	void zoom(double s, int, int) override;
	void ResizeThisbydrag(Point corner, int  xto, int yto) override;
};



