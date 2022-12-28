#pragma once
#include "Shape.h"
#include <vector>

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
    vector<int> arrayX;
    vector<int> arrayY;
   int temp[100];
    int* a = nullptr;
    int* b = nullptr;
    const double pi = 3.14159;

public :
    regularPolygon(Point, Point, int , GfxInfo shapeGfxInfo);
    virtual ~regularPolygon();
    virtual void Draw(GUI* pUI) const;


    string PrintOnTool();  //Rghda added
    bool IsShapeExisting(int x, int y);  //Rghda added
    float trianglearea(int x1, int y1, int x2, int y2, int x3, int y3);  //Rghda added
    void generatingPoints();

    void Save(ofstream& outfile); //Rghda added
    void Load(ifstream& inputfile);
    void Resize(double n);
    void Rotate();
};

