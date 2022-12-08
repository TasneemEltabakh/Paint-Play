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



public:
    IrregularPolygon(vector<Point>, GfxInfo);
    virtual ~IrregularPolygon();
    virtual void Draw(GUI* pUI) const;

    void Save(ofstream& GUIFile); //Rghda added
};

