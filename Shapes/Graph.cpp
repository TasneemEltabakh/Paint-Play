#include "Graph.h"
#include "../GUI/GUI.h"
#include <iostream>
Graph::Graph()
{
	selectedShape = nullptr;




}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}


shape* Graph::Getshape(int x, int y) //Rghda remove const from here
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL
	///Add your code here to search for a shape given a point x,y	

	if (selectedShape!=nullptr) {   //so proud of me :D
		//delete selectedShape;
		selectedShape->SetSelected(0);
		
	}

	for (auto pointeronshapes : shapesList) {
		if (pointeronshapes->IsShapeExisting(x, y) ) {
			selectedShape = pointeronshapes;  //hint**
			pointeronshapes->SetSelected(1);
			return pointeronshapes;
		}
		else {
			pointeronshapes->SetSelected(0);
		}
	}

	return nullptr;  //here I want to put unselect option important
}

int Graph::getvectorsize() {  //Rghda added
	return shapesList.size();
}

shape* Graph::getselectedShape() {  //Rghda added for the vector
	return selectedShape;
}
void Graph::setselectedShapenull() {  //Rghda added to the vector
	selectedShape->SetSelected(false);
}

void Graph::SaveGraph(ofstream& outfile) {  //Rghda added*******

	outfile << shapesList.size() << "\n";
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList[i]->Save(outfile);
	}
}


void Graph::DeleteGraph() {
	
	//int size=shapesList.size(); //it will not work as //I sould put here the size by this form< as its sive changed 
	for (int k = 0; k < shapesList.size(); k++) {   
		if (selectedShape == shapesList[k]) {
		//if (shapesList[k]->IsSelected()) {
			shapesList[k]->SetSelected(false); //new addition
			delete shapesList[k];
			//shapesList.erase(shapesList[i]);  //it didn't work as erase didn't accept
			shapesList.erase(shapesList.begin() + k);
			k--;
		}
	}

	//pGUI->ClearDrawArea(); 
	//UpdateInterface();
}
void Graph::Load(ifstream& inputfile) {

	string num; string type;
	cout << "kk";
	getline(inputfile, num);

	cout << num;
	//getline(inputfile, num);

	//cout << "nd line is"<<endl;
	//cout << num;
	for (int i = 0; i < 3; i++) {
		GfxInfo info = GfxInfo(); Point points = Point();
		type = "";
		inputfile >> type;
		cout <<"1st type "<< type << endl;
		if (type == "Triangle") {
			std::cout << "mytrii" << endl;
			Triangle* trig = new Triangle(points, points, points, info);
			trig->Load(inputfile);
			shapesList.push_back(trig);
		}
		else if (type == "RECT") {
			std::cout << "myrcki" << endl;
			Rect* rect = new Rect(points, points, info);
			rect->Load(inputfile);
			shapesList.push_back(rect);
		}
		else if (type == "Circle") {
			std::cout << "ll" << endl;
			Circle* circ = new Circle( points, points, info);
			circ->Load(inputfile);
			shapesList.push_back(circ);
		}
		/*/else if (type == "Irregular") {
			std::cout << "ll" << endl;
			IrregularPolygon* irreg = new IrregularPolygon( points, points, info);
			irreg->Load(inputfile);
			shapesList.push_back(irreg);
		}/**/
		else if (type == "Line") {
			std::cout << "ll" << endl;
			Line* line = new Line(points, points, info);
			line->Load(inputfile);
			shapesList.push_back(line);
		}
		else if (type == "Oval") {
			std::cout << "ll" << endl;
			Oval* ov = new Oval(points, points, info);
			ov->Load(inputfile);
			shapesList.push_back(ov);
		}
		/*/else if (type == "Regualar") {
			std::cout << "ll" << endl;
			regularPolygon* reg = new regularPolygon(points, points, points, info);
			reg->Load(inputfile);
			shapesList.push_back(reg);
		}/**/
		else if (type == "sQUARE") {
			std::cout << "mysquaree" << endl;
			Square* sq = new Square(points, points, info);
			sq->Load(inputfile);
			shapesList.push_back(sq);
		}
	}
}