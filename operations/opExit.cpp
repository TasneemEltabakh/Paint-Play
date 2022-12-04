/*#include "opExit.h"
#include "operation.h"

opExit::opExit(controller* pCont) :operation(pCont)
{}
opExit :: ~opExit()
{}


window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}

void opExit::Execute()
{


	pW->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);

	msg += " ... Click at Third corner";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(P3.x, P3.y);

	pUI->ClearStatusBar();

	//Preapre all Triangle parameters
	GfxInfo TriangleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pUI->getCrntFillColor();
	TriangleGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	TriangleGfxInfo.isFilled = false;	//default is not filled
	TriangleGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Triangle with the above parameters
	Triangle* T = new Triangle(P1, P2, P3, TriangleGfxInfo);

	//Get a pointer to the graph
	Graph* TR = pControl->getGraph();

	//Add the Triangle to the list of shapes
	TR->Addshape(T);

}*/
