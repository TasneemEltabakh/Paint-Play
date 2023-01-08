#pragma once
#pragma once

#include "..//Shapes/Shape.h"
#include "..//GUI/GUI.h"
#include <vector>

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int side;
	Point center;
	double diagonl;
	vector<int> arrayX;
	vector<int> arrayY;
	Point groupcenter;
	int* id;
	bool ishidden;
public:
	Square(Point, int, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	void generatingCorners();
	void Save(ofstream& outfile); //Rghda added
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
	int* GetID() override;
	void Move(int x, int y); //Rghda Salah
	Point firstxofshape();  //Rghda added for test
	void hide() override;
	void Load(ifstream& inputfile);
	void Resize(double n);
	void Rotate();
	void scramble(Point p) ;
	void zoom(double s, int, int) override;
	void ResizeThisbydrag(Point corner, int  xto, int yto) override;
	void SetgroupCenter(Point) override;
	Point getCenter() override;
	void setID(int* ) override;
	bool isHidden();
	void unhide();
	shape* GDuplicateShape();
	int returnId();
	void setId(int newid);
};

