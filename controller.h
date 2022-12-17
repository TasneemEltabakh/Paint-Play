#pragma once
#include "operations\opAddRect.h"
#include "CMUgraphicsLib/CMUgraphics.h"
#include "CMUgraphicsLib/windowinput.h"
#include "operations/opAddTriangle.h"
#include "operations/opAddRegPol.h"
#include "operations/opAddirrPol.h"
#include "operations/opExit.h"
#include"operations/opChooseColour.h"
#include "operations/Save.h"
#include "operations/opAddSquare.h"
#include "operations/opAddCircle.h"
#include"operations/opAddLine.h"
#include "operations/opAddOval.h"
#include "operations/opFillColour.h"
#include "operations/opsSwitch.h"
#include "operations/Select.h"
#include "operations/Delete.h"
#include "operations/Load.h"
#include "DEFS.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"
#include "operations/Save.h"
#include "operations/opAddImg.h"

class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{
	
	int ShapeCount=0;		//Actual number of figures //Rghda added
	enum { MaxShapeCount = 200 };	//Max no of figures  //Rghda added
	shape* ShapeList[MaxShapeCount];	//List of all figures (Array of pointers)  //Rghda added


	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	

	

public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType) ; //Creates an operation
	void Run();
	
	Graph* getGraph() const;
	
	// -- Interface Management Functions
	GUI *GetUI() const; //Return pointer to the UI
	void UpdateInterface() const;	//Redraws all the drawing window	



	int controller::getshape(shape*& r, int x, int y);  //Rghda added
	int controller::getSelectedCount();  //Rghda added
	shape** controller::getSelected();  //Rghda added
};