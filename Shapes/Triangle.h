#pragma once
#include "Shape.h"
class Triangle : public shape
{
	private:
		Point Corner1;
		Point Corner2;
		Point Corner3;
	public:
		Triangle(Point P1, Point P2, Point P3 , GfxInfo shapeGfxInfo);
		virtual ~Triangle();
		virtual void Draw(GUI* pUI) const;

		void Save(ofstream& outfile); //Rghda added
		float trianglearea(int x1, int y1, int x2, int y2, int x3, int y3);  //Rghda added
		bool IsShapeExisting(int x, int y);  //Rghda added
		string PrintOnTool();  //Rghda added
		void Load(ifstream& inputfile);
};

