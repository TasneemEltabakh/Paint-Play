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
	vector <vector <shape*>> groupedshapes;
	vector <shape*> multiselectedvector; //a container to hold all shapes which multi selected
	vector<int* > vectorOfIds;

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
	void MoveGraph(int x, int  y); //Rghda added
	void MoveMultiGraph(int x, int  y);  //Rghda added
	void DeleteGraph();  //Rghda added
	void DeleteMultiShapesGraph();  //Rghda added
	void EmptyGraph();    //Ariam added
	void Load(ifstream& inputfile);
	int getselectedvectorsize();  //Rghda added
	//int getvectorsize();
	shape* getselectedShape();  //Rghda added
	void setselectedShape(shape* selectedshape);  //Rghda added
	void  changeFillSelection(color);
	void  opChangeSelectedWidth(int);
	void  opChangeSelectedBorder(color);
	void  resize(double);
	void  rotate();
	void  ZOOM(double,int , int);
	void  resizebydrag(Point, int, int);
	void  groupthisShapes(int*);
	void  Ungroup(int* n);
	bool isInIds(int* n);
	void Scramble();
	void Hide();
	void Unhide();


	//Play mode
	void GDuplicate();
};
