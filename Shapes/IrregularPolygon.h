#pragma once
#include "Shape.h"
class IrregularPolygon :
    public shape
{
private:

    Point point1, point2, point3, point4, point5, point6;

public:
    IrregularPolygon(Point , Point, Point, Point, Point, Point, GfxInfo);
    virtual ~IrregularPolygon();
    virtual void Draw(GUI* pUI) const;

    void Save(ofstream& GUIFile); //Rghda added
};

