#include "controller.h"
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

//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddOval(this);
			break;
		case DRAW_TRI:
			pOp = new opAddTriangle(this);
		case DRAW_LINE:
			///create AddLineoperation here
			break;
		case DRAW_regularPOLY:
			pOp = new opAddRegPol(this);
			break;
		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;
		case DRAW_IRREPoly:
			pOp = new opAddirrPol(this);
			break;
		case SAVE:  //Rghda added
			pOp = new Save(this);
			break;
		case EXIT: 
			pOp = new opExit(this);
			break;
		case TO_Pallete:
			pOp = new opChooseColour(this);
			break;

		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}


//==================================================================================//
//							Save function											//  //Rghda added
//==================================================================================//
int controller::NO_SHAPES() const
{
	return ShapeCount;
}

void controller::SaveAll(ofstream& GUIFile)
{
	//Loop on each figure ,then saving it 
	for (int i = 0; i < ShapeCount; i++)
	{
		ShapeList[i]->Save(GUIFile);
	}
}