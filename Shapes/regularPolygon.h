#pragma once
#include "Shape.h"

class regularPolygon :
    public shape
{
private:
    Point Center;
    Point start;
    Point end;
    double r;
    double SideLength;
    int NumberOfsides;
    double angle;
    double iteratedangle;
    int* arrayX= new int[100];
    int* arrayY= new int [100];

public :
    regularPolygon(Point, Point, int , GfxInfo shapeGfxInfo);
    virtual ~regularPolygon();
    virtual void Draw(GUI* pUI) const;


    string PrintOnTool();  //Rghda added
    bool IsShapeExisting(int x, int y);  //Rghda added
    void Save(ofstream& outfile); //Rghda added
};

