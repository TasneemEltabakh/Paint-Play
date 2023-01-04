#pragma once
#include "Shape.h"
#include <vector>
#include "Graph.h"
class groupshape : public shape
{
private:
	shape* thisShape;
	Graph* graph;
	vector <shape*> group;
	int numOfshapes;
public:
	groupshape(vector <shape*>, GfxInfo , int);
	virtual ~groupshape();
	void Resize(double n);
	virtual void Draw(GUI* pUI) const;
	void Save(ofstream& GUIFile); //Rghda added
	string PrintOnTool();  //Rghda added
	
	void Move(int x, int y); //Rghda Salah
	bool IsShapeExisting(int x, int y);
	
	void Rotate();
	void zoom(double s, int, int) override;
	void ResizeThisbydrag(Point corner, int  xto, int yto) override;
};