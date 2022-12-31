#include "Graph.h"
#include "../GUI/GUI.h"
#include <iostream>
#include <string>

Graph::Graph()
{
	selectedShape = nullptr;

	// set the nullptr to a pointer of that shape 


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

	for (auto pointeronshapes : shapesList) {
		if (pointeronshapes->IsShapeExisting(x, y)) {
			return pointeronshapes;
		}
	}

	return nullptr;
}

void Graph::unselectmulti() {
	for (int k = shapesList.size() - 1; k >= 0; k--) {
		shapesList[k]->SetSelected(false);
	}
	multiselectedvector.clear();
}
void Graph::unselectselectedshape(shape* selectedmultishape2) {
	string cnt;
	for (int k = 0; k < multiselectedvector.size(); k++) {
		if (selectedmultishape2 == multiselectedvector[k]) {
			//multiselectedvector[k]->SetSelected(false);
			for (int k = shapesList.size() - 1; k >= 0; k--) {
				if (selectedmultishape2 == shapesList[k]) {
					shapesList[k]->SetSelected(false);
				}
			}
			//delete multiselectedvector[k];
			multiselectedvector.erase(multiselectedvector.begin() + k);
			k--;
		}
	}

}
void Graph::pushbackselectvector(shape* selectedmultishape2) {
	multiselectedvector.push_back(selectedmultishape2);

}
string Graph::numberofselectedshapes()
{
	string cnt;
	int count = 0;
	for (int i = 0; i < multiselectedvector.size(); i++) {
		//if (multiselectedvector[i]->IsSelected())  //I don't think this condition important
			count++;
	}
	cnt = to_string(count);
	return cnt;
}




int Graph::getvectorsize() {  //Rghda added
	return shapesList.size();
}

shape* Graph::getselectedShape() {  //Rghda added for the vector
	return selectedShape;
}
void Graph::setselectedShape(shape* selectedshape2) {  //Rghda added to the vector
	selectedShape = selectedshape2;
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
void Graph::DeleteMultiShapesGraph() {

	for (int i = 0; i < shapesList.size(); i++) {
		if (shapesList[i]->IsSelected()) {
			shapesList[i]->SetSelected(false);
			delete shapesList[i];
			shapesList.erase(shapesList.begin() + i);
			i--;
		}
	}
	for (int j = 0; j < multiselectedvector.size(); j++) {
		multiselectedvector.erase(multiselectedvector.begin() + j);   //delete selected shapes from the vector
		j--;
	}

}

void Graph::EmptyGraph() {
	for (int k = 0; k < shapesList.size(); k++) {
		{
			shapesList.erase(shapesList.begin() + k);
			k--;
		}
	}
}
void Graph::changeFillSelection(color r) {

	//int size=shapesList.size(); //it will not work as //I sould put here the size by this form< as its sive changed 
	for (int k = 0; k < shapesList.size(); k++) {
		if (selectedShape == shapesList[k]) {
			shapesList[k]->ChngFillClr(r); //new addition
		}
	}

	//pGUI->ClearDrawArea(); 
	//UpdateInterface();
}
// change width of selection shape 
void Graph::opChangeSelectedWidth(int x) {


	for (int k = 0; k < shapesList.size(); k++) {
		if (selectedShape == shapesList[k]) {
			shapesList[k]->setCrntPenWidth(x);
		}
	}

	//pGUI->ClearDrawArea(); 
	//UpdateInterface();
}
void Graph::opChangeSelectedBorder(color a)
{
	for (int k = 0; k < shapesList.size(); k++) {
		if (selectedShape == shapesList[k]) {
			shapesList[k]->ChngDrawClr(a);
		}
	}
}

void Graph::Load(ifstream& inputfile) {

	string num; string type;
	getline(inputfile, num);

	int number = stoi(num);


	for (int i = 0; i < number; i++) {
		GfxInfo info = GfxInfo(); Point points = Point();
		vector<Point> parr;
		int size = 0;
		type = "";
		inputfile >> type;

		if (type == "Triangle") {
			Triangle* trig = new Triangle(points, points, points, info);
			trig->Load(inputfile);
			shapesList.push_back(trig);
		}

		else if (type == "RECT") {
			Rect* rect = new Rect(points, points, info);
			rect->Load(inputfile);
			shapesList.push_back(rect);
		}

		else if (type == "Circle") {
			Circle* circ = new Circle(points, points, info);
			circ->Load(inputfile);
			shapesList.push_back(circ);
		}

		else if (type == "Irreg") {

			inputfile >> size;

			for (int i = 0; i < size; i++)
			{
				inputfile >> points.x >> points.y;
				cout << points.x << " and " << points.y << endl;
				parr.push_back(points);

				cout << parr[i].x << " " << parr[i].y << endl;
			}

			IrregularPolygon* irreg = new IrregularPolygon(parr, info);
			irreg->Load(inputfile);
			shapesList.push_back(irreg);
		}

		else if (type == "Line") {
			Line* line = new Line(points, points, info);
			line->Load(inputfile);
			shapesList.push_back(line);
		}

		else if (type == "Oval") {
			Oval* ov = new Oval(points, points, info);
			ov->Load(inputfile);
			shapesList.push_back(ov);
		}

		else if (type == "Reg") {
			inputfile >> size;
			regularPolygon* reg = new regularPolygon(points, points, size, info);
			reg->Load(inputfile);
			shapesList.push_back(reg);
		}

		else if (type == "sQUARE") {
			Square* sq = new Square(points, size, info);
			sq->Load(inputfile);
			shapesList.push_back(sq);
		}

	}

}
void Graph::resize(double n)
{
	for (int k = 0; k < shapesList.size(); k++) {
		if (selectedShape == shapesList[k]) {
			shapesList[k]->Resize(n);
		}
	}
}
void Graph::rotate()
{
	for (int k = 0; k < shapesList.size(); k++) {
		if (selectedShape == shapesList[k]) {
			shapesList[k]->Rotate();
		}
	}
}
void Graph::ZOOM(double scale, int X, int Y)
{
	for (int k = 0; k < shapesList.size(); k++) {
		 
			shapesList[k]->zoom(scale,X,Y);
		
	}
}