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
    int* a = new int;
    int* b = new int;
    const double pi = 3.14159;
    int* id;

public :
    regularPolygon(Point, Point, int , GfxInfo shapeGfxInfo);
    virtual ~regularPolygon();
    virtual void Draw(GUI* pUI) const;
    void zoom(double s, int, int) override;
    string PrintOnTool();  //Rghda added
    bool IsShapeExisting(int x, int y);  //Rghda added
    void Move(int x, int y); //Rghda Salah
    Point firstxofshape();  //Rghda added for test

    float trianglearea(int x1, int y1, int x2, int y2, int x3, int y3);  //Rghda added
    void generatingPoints();
    int* GetID() override;
    void Save(ofstream& outfile); //Rghda added
    void Load(ifstream& inputfile);
    void Resize(double n);
    void Rotate();
    void ResizeThisbydrag(Point corner, int  xto, int yto) override;
    void SetgroupCenter(Point) override;
    Point getCenter() override;
    void setID(int*) override;

};

