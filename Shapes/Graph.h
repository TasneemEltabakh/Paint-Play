#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
#include "..//CMUgraphicsLib/colors.h"
#include "Shape.h"
#include <fstream>
#include <vector>
#include "ciecle.h"
#include"Triangle.h"
#include "Rect.h"
#include "Square.h"
#include "IrregularPolygon.h"
#include "Oval.h"
#include "regularPolygon.h"
#include "Line.h"

using namespace std;

//forward decl
class GUI;

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape

	//shape* selectedmultishape;
	vector <shape*> multiselectedvector; //a container to hold all shapes which multi selected


public:
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)

	shape* Getshape(int x, int y); //Search for a shape given a point inside the shape
	void unselectmulti(); //Rghda added
	void unselectselectedshape(shape* selectedmultishape2);  //Rghda added
	void pushbackselectvector(shape* selectedmultishape2);  //Rghda added
	string numberofselectedshapes();  //Rghda added

	void SaveGraph(ofstream& outfile);	//Save all shapes to a file  //Rghda edideted its name
	void MoveGraph(int xto, int  yto); //Rghda added
	void DeleteGraph();  //Rghda added
	void DeleteMultiShapesGraph();  //Rghda added

	void EmptyGraph();    //Ariam added
	void Load(ifstream& inputfile);
	int getvectorsize();
	shape* getselectedShape();  //Rghda added

	void setselectedShape(shape* selectedshape);  //Rghda added

	void Graph::changeFillSelection(color);
	void Graph::opChangeSelectedWidth(int);
	void Graph::opChangeSelectedBorder(color);
	void  resize(double);
	void  rotate();
	void  ZOOM(double,int , int);
	void resizebydrag(Point, int, int);

};
