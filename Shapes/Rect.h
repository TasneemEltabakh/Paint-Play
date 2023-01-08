#pragma once
#include <vector>
#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	Point center;
	double dist;
	int* id;

public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect(); 
	virtual void Draw(GUI* pUI) const;
	int* GetID() override;
	void Save(ofstream& outfile); //Rghda added
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
	void Move(int x, int y);  //Rghda added
	Point firstxofshape();  //Rghda added for test

	void Load(ifstream& inputfile);
	void Resize(double n);	//Resize the shape
	void Rotate();
	void zoom(double s, int, int) override;
	void ResizeThisbydrag(Point corner, int  xto, int yto) override;
	void SetgroupCenter(Point) override;
	Point getCenter() override;
	void setID(int*) override;
	shape* Copy();

};

