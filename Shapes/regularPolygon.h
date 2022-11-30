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
    int PointerToarrayX [1000];
    int PointerToarrayY  [1000];

public :
    regularPolygon(Point, Point, Point , int , GfxInfo shapeGfxInfo);
    virtual ~regularPolygon();
    virtual void Draw(GUI* pUI) const;

};

