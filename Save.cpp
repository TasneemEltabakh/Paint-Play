#include"Save.h"
#include "controller.h"
#include "GUI/GUI.h"
#include "Shapes/Graph.h"



void Save::SaveUserData()
{

	//main Idea to edit on any thing---> that you identifay the pointers GUI and the Graph
	//to know where they located in the interfaces
	//I got it as a hint from someone took the course before


	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	pGUI->PrintMessage("name your file please ");

	Name = pGraph->GetSrting(pGUI) + ".text";


	//I want to add confermation massege that this file was saved, 
	//but I want to check first if this file exit in the desired file or not

	//is_open() this should be a function I found in ths file but it here didn't work
	//I think it wants something else instead of Name

	if (Name.is_open())
		pGUI->PrintMessage("File has been Saved");
	else
		pGUI->PrintMessage("Cannot save file");

}