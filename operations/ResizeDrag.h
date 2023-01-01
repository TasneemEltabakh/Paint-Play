#pragma once
#include "operation.h"
class ResizeDrag :
	public operation
{
public:
	int x= 0, y = 0;
	Point c;
	ResizeDrag(controller* pCont);
	virtual ~ResizeDrag();
	virtual void Execute();

};
