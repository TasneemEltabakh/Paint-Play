#pragma once
#include "operation.h"
#include "..//Shapes/Graph.h"
#include "../controller.h"

class Move : public operation
{
private:
	Point pointmove;

public:

	Move(controller* pCont);

	void Execute();

};