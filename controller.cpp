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
#include "operations/opFillColour.h"
#include "operations/opsSwitch.h"
#include "operations/Select.h"
#include "operations/Delete.h"
#include "operations/opChangeFillSelected.h"
#include "operations/opCahangeSelectedWidth.h"
#include "operations/opCahngeSelectedBorder.h"
#include "operations/opChangeWidth.h"
#include "operations/opSwitchToPlay.h"
#include "operations/ZoomIn.h"
#include "operations/ZoomOut.h"
#include "operations/Resize.h"
#include "operations/rotatOp.h"
#include "operations/ResizeDrag.h"
#include "operations/Move.h"
#include "operations/opSwitchTodraw2.h"

using namespace std;
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
		pOp = new opAddRect(this);
		break;
	case DRAW_TRI:
		pOp = new opAddTriangle(this);
		break;
	case DRAW_LINE:
		pOp = new opAddLine(this);
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
	case SELECT:  //Rghda added
		pOp = new Select(this);
		break;
	case DEL:  //Rghda added
		pOp = new Delete(this); // trial
		break;
	case EXIT:
		pOp = new opExit(this);
		break;
	case TO_Pallete:
		pOp = new opChooseColour(this);
		break;
	case FILL_COLOUR:
		pOp = new opFillColour(this);
		break;
	case DRAWOV:
		pOp = new opAddOval(this);
		break;
	case DRAW_SQ:
		pOp = new opAddSquare(this);
		break;
	case selectfill:
		pOp = new opChangeFillSelected(this);
		break;
	case selectwid:
		pOp = new opChangeSelectedWidth(this);
		break;
	case selsectcol:
		pOp = new opChangeBorderSelected(this);
		break;
	case LOAD:
		pOp = new opLoad(this);
		break;
	case ADD_IMG:
		pOp = new opAddImg(this);
		break;
	case bord:
		pOp = new opChangeWidth(this);
		break;
	case TO_PLAY:
		pOp = new opsSwitch(this);
		break;
	case TO_DRAW:
		pOp = new opSwitchToPlay(this);
		break;
	case MOVE:  //Rghda added
		pOp = new Move(this);
		break;
	case BACK:
		pOp = new opSwitchTodraw2(this);
		break;
	case ROTATE:
		pOp= new Rotate(this);
		break;
	case RESIZE:
		pOp = new Resize(this);
		break;
	case RESIZEBYDRAG:
		pOp = new ResizeDrag(this);
		break;
	case ZOOMOUT:
		pOp = new ZoomOut(this);
		break;
	case ZOOMIN:
		pOp = new ZoomIn(this);
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
GUI* controller::GetUI() const
{
	return pGUI;
}
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


