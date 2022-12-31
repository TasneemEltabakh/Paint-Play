#pragma once
#include "operation.h"

class Zoom : public operation
{
public:

	Zoom(controller* pCont);
	virtual ~Zoom();
	virtual void Execute();


};