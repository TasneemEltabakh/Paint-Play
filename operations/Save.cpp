//save.cpp
#include"Save.h"
#include "opAddirrPol.h"
#include "..//Shapes/IrregularPolygon.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "operation.h"


Save::Save(controller* pCont) :operation(pCont)
{}

void Save::ReadOperationParameters()
{

	//main Idea to edit on any thing---> that you identifay the pointers GUI and the Graph
	//to know where they located in the interfaces
	//I got it as a hint from someone took the course before


	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	pGUI->PrintMessage("name your file please ");

	pGUI->PrintMessage("What do you want to name the file? ");

	Name = pGUI->GetSrting() + ".txt";

	GUIFile.open(Name);

	if (GUIFile.is_open())
		pGUI->PrintMessage("File has been Saved");
	else
		pGUI->PrintMessage("Cannot save file");
}

//Execute the action
void  Save::Execute()
{
	ReadOperationParameters();

	if (GUIFile.is_open())
	{
		int NO_FIGS = pControl->NO_SHAPES();
		

		pControl->SaveAll(GUIFile);
		GUIFile.close();
	}
}