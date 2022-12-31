#pragma once
#include "operation.h"
class ResizeDrag :
	public operation
{
public:

	ResizeDrag(controller* pCont);
	virtual ~ResizeDrag();
	virtual void Execute();

};
