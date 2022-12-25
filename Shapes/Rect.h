#pragma once
#include <vector>
#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	int check;
	vector <Point> v;
	Point P, R;
	Point center;
	double dist;

public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;

	void Save(ofstream& outfile); //Rghda added
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
	void Load(ifstream& inputfile);
	void Resize(double n);	//Resize the shape

};

