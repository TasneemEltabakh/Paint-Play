#pragma once
#include "opAddirrPol.h"
#include "..//Shapes/IrregularPolygon.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "operation.h"

class Select : public operation
{
private:
	Point P1; //the selected point inside the shape
	GfxInfo SelectedGfxInfo;
	shape* selectedmultishape;
	vector <shape*> multiselectedvector; //a container to hold all shapes which multi selected

public:

	Select(controller* pCont);

	virtual void Execute();

};


