/*#include"Select.h"
#include "controller.h"
#include <iostream>
using namespace std;
#include "GUI/GUI.h"
#include "Shapes/Graph.h"



//this function should select the shape
void Select::select() {
	SelectedShape->SetSelected(true); //this is bool one which detremine if it selected or not
	pControl->AddSelectedShape(SelectedFig); //this should add this shape to the array or to the vector which collect selected shapes

	//here I should say where the GUI and Graph pointers on the Interface (I will see how i will put them)


	SelectedShape->PrintInfo(pGUI); //show the selected shape info on the status bar (these functions I didn't implement them yet)

}

//this function should unselect shape which was selescted
void Select::Unselect() {
	SelectedShape->SetSelected(false); //set the shape as "unselected"
	pControl->RemoveSelectedShape(SelectedShape);	//here I remove this shape from the array i mentioned above

}*/