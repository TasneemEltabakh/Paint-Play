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
	
	GUI* pGUI = pControl->GetUI();
	

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