//save.cpp
#include"Save.h"
//#include "opAddirrPol.h"
//#include "..//Shapes/IrregularPolygon.h"
#include "..//Shapes/Shape.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "operation.h"

#include "..\Shapes\Graph.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

 //Second version
Save::Save(controller* pCont) :operation(pCont)
{
	Name = "DRAW";
}

//Execute the action
void  Save::Execute()
{
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGUI->PrintMessage("name your file please");
	Name = pGUI->GetSrting() + ".txt";

	GUIFile.open(Name);  // creat file with this name 

	
	do{
		if (GUIFile.good()) {
			break;
		}
		else {
			pGUI->PrintMessage("Please enter valid name");
			Name = pGUI->GetSrting() + ".txt";
			GUIFile.open(Name);
		}

	} while (!GUIFile.good());

	pGraph->SaveGraph(GUIFile);
	GUIFile.close(); //close the file 
	pGUI->PrintMessage("your drawing SAVED");  //Done

}

