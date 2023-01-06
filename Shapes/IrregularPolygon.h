#pragma once
#include "Shape.h"
#include <vector>
class IrregularPolygon :
    public shape
{
private:

  
    vector<int> arrayX;
    vector<int> arrayY;
    int* a = nullptr;
    int* b = nullptr;
    int numberofsides;
    Point Center;
    int* id;


public:
    IrregularPolygon(vector<Point>, GfxInfo);
    virtual ~IrregularPolygon();
    virtual void Draw(GUI* pUI) const;
    void generatingPoints();
    int* GetID() override;
    void Save(ofstream& outfile); //Rghda added
    string PrintOnTool();  //Rghda added
    bool IsShapeExisting(int x, int y);  //Rghda added
    void Move(int x, int y); //Rghda Salah
    Point firstxofshape();  //Rghda added for test

    void Load(ifstream& inputfile);
    void Resize(double n);
    void Rotate();
    void zoom(double s, int, int) override;
    void ResizeThisbydrag(Point corner, int  xto, int yto) override;
    void SetgroupCenter(Point) override;
    Point getCenter() override;
    void setID(int*) override;

};

