#pragma once
#include "operation.h"
#include "..//Shapes/Shape.h"
#include <vector> 

class Hide : public operation
{
public:

	Hide(controller* pCont);
	virtual ~Hide();
	virtual void Execute();

};