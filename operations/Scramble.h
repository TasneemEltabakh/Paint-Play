#pragma once
#include "operation.h"
#include "..//Shapes/Shape.h"
#include <vector> 

class Scramble : public operation
{
public:

	Scramble(controller* pCont);
	virtual ~Scramble();
	virtual void Execute();

};