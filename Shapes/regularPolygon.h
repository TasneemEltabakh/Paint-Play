#pragma once
#include "Shape.h"

class regularPolygon :
    public shape
{
private:
    Point Center;
    Point start;
    Point end;
    double distanceFromCenter;
    double SideLength;
    int NumberOfsides;
    double angle;
public :
    regularPolygon(Point, Point, Point , string , GfxInfo shapeGfxInfo);
    virtual ~regularPolygon();
    virtual void Draw(GUI* pUI) const;

};

