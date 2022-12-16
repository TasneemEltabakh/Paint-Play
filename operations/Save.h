//Save.h
#pragma once
#include <fstream>


//#include "operations/operation.h"    //Icomment this part as when i change its place, it made error in them,
//#include"CMUgraphicsLib/colors.h"    //so I copy this part from another file in folder operation too

#include "opAddirrPol.h"
#include "..//Shapes/IrregularPolygon.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "operation.h"

//here i inherted the save class from 'operation' class as the TA mention in the report

class  Save : public operation
{
private:
	ofstream GUIFile;
	string Name;


public:
	Save(controller* pCont);

	virtual void Execute();

};