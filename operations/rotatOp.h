#pragma once
#include "operation.h"
class Rotate : public operation
{
public:

	Rotate(controller* pCont);
	virtual ~Rotate();
	virtual void Execute();

};