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
public:

	Select(controller* pCont);

	virtual void Execute();

};


