#include "Graph.h"
#include "../GUI/GUI.h"
#include <iostream>
#include <string>
#include <time.h> /* time */

#include <random>
#include <algorithm>
#include <iterator>   //These four include for randum
#include <iostream>
#include <vector>

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


int Graph::getselectedvectorsize() {  //Rghda added
	return multiselectedvector.size();
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
	int n=-3;

	for (int k = 0; k < shapesList.size(); k++) {
		if (selectedShape == shapesList[k])
		{
			if (shapesList[k]->GetID() != nullptr)
			{
				for (int i = 0; i < groupedshapes.size(); i++)
				{
					for (int j = 0; j < groupedshapes[i].size(); j++)
					{
						if (*shapesList[k]->GetID() == *groupedshapes[i][j]->GetID())
						{
							n = i;
							shapesList[k]->SetSelected(false);
							delete shapesList[k];
							shapesList.erase(shapesList.begin() + k);
							k--;
							
						}
					}
					
				}
				
			}
			else
			{

				shapesList[k]->SetSelected(false);
				delete shapesList[k];
				shapesList.erase(shapesList.begin() + k);
				k--;


			}
		}
	}
	//if (n != -3)
	//{
	//	groupedshapes.erase(groupedshapes.begin() + n);   //delete selected shapes from the vector
	//	n--;
	//	
	//}
	
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

void  Graph::MoveGraph(int x, int  y)
{

	for (int k = 0; k < shapesList.size(); k++) {
		if (selectedShape == shapesList[k]) {
			shapesList[k]->Move(x, y);
		}
	}

}

void  Graph::MoveMultiGraph(int xx, int  yy)
{
	int c = 0;
	Point fixedp;  //corner 1
	for (int i = 0; i < shapesList.size(); i++) {
		if (shapesList[i]->IsSelected()) {

			Point newpoint = shapesList[i]->firstxofshape();  //corner 2
			if (c == 0) {
				fixedp.x = shapesList[i]->firstxofshape().x;
				fixedp.y = shapesList[i]->firstxofshape().y;
				c = c + 1;
				shapesList[i]->Move(xx, yy);
			}
			else if(fixedp.x< newpoint.x && fixedp.y < newpoint.y){
				//Point newpoint = shapesList[i]->firstxofshape();  //corner 2
				Point ctepn = { fixedp.x,newpoint.y };  //corner 3
				int l = sqrt(pow(ctepn.x - newpoint.x, 2) + pow(ctepn.y - newpoint.y, 2));
				int w = sqrt(pow(ctepn.x - fixedp.x, 2) + pow(ctepn.y - fixedp.y, 2));
				
				newpoint.x = (xx + l);
				newpoint.y = (yy + w);
				shapesList[i]->Move(newpoint.x, newpoint.y);	
			}
			else if (fixedp.x > newpoint.x && fixedp.y > newpoint.y) {
				Point ctepn = { newpoint.x,fixedp.y };  //corner 3
				int l = sqrt(pow(ctepn.x - newpoint.x, 2) + pow(ctepn.y - newpoint.y, 2));
				int w = sqrt(pow(ctepn.x - fixedp.x, 2) + pow(ctepn.y - fixedp.y, 2));

				newpoint.x = (xx - w);
				newpoint.y = (yy - l);
				shapesList[i]->Move(newpoint.x, newpoint.y);
			}
			else if (fixedp.x < newpoint.x && fixedp.y > newpoint.y) {
				//Point newpoint = shapesList[i]->firstxofshape();  //corner 2
				Point ctepn = { fixedp.x,newpoint.y };  //corner 3
				int l = sqrt(pow(ctepn.x - newpoint.x, 2) + pow(ctepn.y - newpoint.y, 2));
				int w = sqrt(pow(ctepn.x - fixedp.x, 2) + pow(ctepn.y - fixedp.y, 2));

				newpoint.x = (xx + l);
				newpoint.y = (yy - w);
				shapesList[i]->Move(newpoint.x, newpoint.y);
			}
			else if (fixedp.x > newpoint.x && fixedp.y < newpoint.y) {
				//Point newpoint = shapesList[i]->firstxofshape();  //corner 2
				Point ctepn = { newpoint.x,fixedp.y };  //corner 3
				int l = sqrt(pow(ctepn.x - newpoint.x, 2) + pow(ctepn.y - newpoint.y, 2));
				int w = sqrt(pow(ctepn.x - fixedp.x, 2) + pow(ctepn.y - fixedp.y, 2));

				newpoint.x = (xx -  w);
				newpoint.y = (yy + l);
				shapesList[i]->Move(newpoint.x, newpoint.y);
			}
		}
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
		
		if (shapesList[k]->IsSelected()) 
		{
			if (shapesList[k]->GetID() != nullptr)
			{
				for (int i = 0; i < groupedshapes.size(); i++)
				{
					for (int j = 0; j < groupedshapes[i].size(); j++)
					{
						if (*shapesList[k]->GetID() == *groupedshapes[i][j]->GetID())
						{
							groupedshapes[i][j]->Resize(n);
						}
					}
				}
			}
			else
				shapesList[k]->Resize(n);

			
		}
		
	}
}
void Graph::rotate()
{
	for (int k = 0; k < shapesList.size(); k++) {
		if (shapesList[k]->IsSelected()) {
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
void  Graph::resizebydrag (Point corner,int xto, int  yto)
{

	for (int k = 0; k < shapesList.size(); k++)
		if (selectedShape == shapesList[k]) {
			shapesList[k]->ResizeThisbydrag(corner, xto, yto);
		}
	

}

void Graph::groupthisShapes(int* n)
{

	vector<shape*> p;
	for (int i = 0; i < multiselectedvector.size(); i++)
	{
		multiselectedvector[i]->setID(n);
		p.push_back(multiselectedvector.at(i));
	}

	groupedshapes.push_back(p);
	vectorOfIds.push_back(n);

}
void Graph::Ungroup(int* n)
{
	int m = 0;
	for (int i = 0; i < groupedshapes.size(); i++)
	{
		for (int j = 0; j < groupedshapes[i].size(); j++)
		{
			if (*groupedshapes[i][j]->GetID())
			{
				m=i;
			}
		}
	}
	for (int i = 0; i < groupedshapes[m].size(); i++)
	{
		groupedshapes[m][i]->setID(nullptr);
	}

	vectorOfIds.erase(vectorOfIds.begin() + m);
}
bool Graph::isInIds(int* n)
{
	for (int i = 0 ; i < vectorOfIds.size(); i++)
	{
		if (*n == *vectorOfIds[i])
			return true;
		
	}
	return false;
}
void Graph::Scramble()
{
	//srand(time(0));
	random_shuffle(shapesList.begin(), shapesList.end());
	srand(time(NULL));
	//cout << endl << shapesList.size() << endl;
	for (unsigned int k = 0; k < shapesList.size(); k++) {
		Point p;
		p.x = rand() % (2000 / 2 - 70) + 70;   //note width of the draw windo==1300
		p.y = rand() % (1000 / 2 - 70) + 70;   //note hieght of the draw windo==700
		//p.x = 70 + rand() % (1300 - 700 + 1);   //note width of the draw windo==1300
		//p.y = 70 + rand() % (1300 - 700 + 1);   //note hieght of the draw windo==700
		//p.x += 1300 / 2;
		shapesList[k]->scramble(p);
		if (k < shapesList.size() / 2) {
			shapesList[k]->ChngDrawClr(color(0, 0, 255));
		}
		else {
			shapesList[k]->ChngDrawClr(color(173, 255, 47));
		}
	}
}
void Graph::Hide()
{
	for (int k = 0; k < shapesList.size(); k++) {

		shapesList[k]->hide();

	}
}
void Graph::Unhide()
{
	for (int k = 0; k < shapesList.size(); k++) {

		//shapesList[k]->unhide();
	}
}
/////////////
////Play////
///////////
void Graph::GDuplicate(GUI* pGUI) {
	const int n = shapesList.size();  //Rghda edit this fantastic :D I proud of me that I could find the error
	//cout << "OLD SIZE" << n << endl;
	for (int k = 0; k < n; k++) {
		keepshapesList.push_back(shapesList[k]);   //to save all shapes Rghda added
		shape* creatnewshape;
		creatnewshape = shapesList[k]->GDuplicateShape();
		shapesList.push_back(creatnewshape);
		//shapesList[k]->ChngDrawClr(color(0, 0, 255));
	}

	//for (int j = 0;j< shapesList.size()/2;j++) {
	//	shapesList[j]->Draw(pGUI);
	//	shapesList[j]->Resize(2);
	//	pGUI->ClearStatusBar();
	//	pGUI->CreateDrawToolBar();
	//	//pControl->UpdateInterface();
	//}
	//cout << "NEW SIZE" << shapesList.size() << endl;
}

bool Graph::matchgraph(shape* shape1, shape* shape2) {
	for (int i = 0; i < shapesList.size(); i++) {
		if (shape1 == shapesList[i]) {
			for (int k = 0; k < shapesList.size(); k++) {
				if (shape2 == shapesList[k]) {

					//if (shapesList[i]->getGfxInfo() == shapesList[k]->getGfxInfo()) {
					if (k=(shapesList.size()/2)+i) {
						//delete first shape
						//shapesList[i]->SetSelected(false); 
						//delete shapesList[i];
						//shapesList.erase(shapesList.begin() + i);
						//i--;
						////delete second shape
						//shapesList[k]->SetSelected(false);
						//delete shapesList[k];
						//shapesList.erase(shapesList.begin() + k);
						//k--;
						//DeleteMultiShapesGraph();
						return true;
					}
					else 
					{
						return false;
					}
				}
			}
		}
		
	}

}
void Graph::returnallshapesforplay() {
	for (int k = 0; k < keepshapesList.size(); k++) {
		shapesList.push_back(keepshapesList[k]);
	}
}
	
