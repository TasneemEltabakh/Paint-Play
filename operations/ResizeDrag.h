#pragma once
#include "operation.h"
class ResizeDrag :
	public operation
{
public:
	
	Point c;
	ResizeDrag(controller* pCont);
	virtual ~ResizeDrag();
	virtual void Execute();

};
