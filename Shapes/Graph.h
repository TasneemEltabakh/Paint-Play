#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
#include "..//CMUgraphicsLib/colors.h"
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) ; //Search for a shape given a point inside the shape

	void SaveGraph(ofstream& outfile);	//Save all shapes to a file  //Rghda edideted its name

	void DeleteGraph();  //Rghda added

	void load(ifstream& inputfile);	//Load all shapes from a file
	
	int getvectorsize();
	shape* getselectedShape();  //Rghda added

	void setselectedShape(shape* selectedshape);  //Rghda added

	void Graph::changeFillSelection(color);
	void Graph::opChangeSelectedWidth(int );
	void Graph::opChangeSelectedBorder(color);
	


};
