#pragma once
using namespace std;
#pragma once
#include "Shape.h"
#include "..//GUI/GUI.h"

class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
	double dist;
	Point midPoint;
	int* id;
	bool ishidden;
public:

	Line(Point P1, Point P2, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	void Save(ofstream& GUIFile); //Rghda added
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
	void Move(int x, int y); //Rghda Salah
	Point firstxofshape();  //Rghda added for test
	void scramble(Point p);
	void Load(ifstream& inputfile);
	void Resize(double n);
	void Rotate();
	void zoom(double s, int, int) override;
	void ResizeThisbydrag(Point corner, int  xto, int yto) override;
	void SetgroupCenter(Point) override;
	Point getCenter() override;
	void setID(int*) override;
	int* GetID() override;
	void hide() override;
	bool isHidden();
	void unhide();
	shape* GDuplicateShape();
	int returnId();
	void setId(int newid);
	shape* Copy();
};
