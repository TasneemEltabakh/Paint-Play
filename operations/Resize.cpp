#include "Resize.h"
#include "..//controller.h"
#include "operation.h"
#include <string>
#include "Delete.h"


Resize::Resize(controller* pCont) :operation(pCont)
{}
Resize :: ~Resize()
{}

void Resize::Execute()
{

	GUI* pUI = pControl->GetUI();
    Graph * pGraph = pControl->getGraph();
	double wchoice;
	do
	{
		pUI->PrintMessage("Enter The size Only from [1/4 , 1/2 , 2 , 4 ] to resize the current size : ");
		wchoice = stod(pUI->GetSrting());
	}
	while (wchoice != 0.25 && wchoice != 0.5 && wchoice != 2 && wchoice != 4);
	
	

	pUI->ClearStatusBar();
	pUI->CheckIsResized();
	pGraph->resize(wchoice);

}