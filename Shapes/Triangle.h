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
};

