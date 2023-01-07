#pragma once
#include "operation.h"
#include "../controller.h"

class Play :public operation
{
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
public:
	int wrongAnswers = 0;
	int rightAnswers = 0;
	Play(controller* pCont);

	//Execute the action
	void match();
	void Execute();
};
