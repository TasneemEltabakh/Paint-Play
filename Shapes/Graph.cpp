#include "Graph.h"
#include "../GUI/GUI.h"

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
