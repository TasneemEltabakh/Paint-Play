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
	int* id;
	bool ishidden;
	int ff=0; //Rghda wll test something
public:
	Circle(Point P1, Point P2, GfxInfo shapeGfxInfo);
	virtual ~Circle();
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
	int* GetID() override;
	void zoom(double s, int, int) override;
	void ResizeThisbydrag(Point corner, int  xto, int yto) override;
	void SetgroupCenter(Point) override;
	Point getCenter() override;
	void setID(int*) override;
	void hide() override;
	bool isHidden();
	//Play
	shape* GDuplicateShape();
};



