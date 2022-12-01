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
    int* PointerToarrayX = new int[NumberOfsides];
    int* PointerToarrayY = new int[NumberOfsides];

public :
    regularPolygon(Point, Point, Point , int , GfxInfo shapeGfxInfo);
    virtual ~regularPolygon();
    virtual void Draw(GUI* pUI) const;

};

