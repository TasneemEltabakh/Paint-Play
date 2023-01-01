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


public:
    IrregularPolygon(vector<Point>, GfxInfo);
    virtual ~IrregularPolygon();
    virtual void Draw(GUI* pUI) const;
    void generatingPoints();
    void Save(ofstream& outfile); //Rghda added
    string PrintOnTool();  //Rghda added
    bool IsShapeExisting(int x, int y);  //Rghda added
    void Load(ifstream& inputfile);
    void Resize(double n);
    void Rotate();
    void zoom(double s, int, int) override;
    void ResizeThisbydrag(Point corner, int  xto, int yto) override;
};

