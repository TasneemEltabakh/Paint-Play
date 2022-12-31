#pragma once
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
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
	void Load(ifstream& inputfile);
	void Resize(double n);
	void Rotate();
	void zoom(double s, int, int) override;
};



