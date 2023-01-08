#pragma once
#include "operation.h"
#include "..//Shapes/Shape.h"
#include <vector> 

class Restart : public operation
{
public:

	Restart(controller* pCont);
	virtual ~Restart();
	virtual void Execute();

};