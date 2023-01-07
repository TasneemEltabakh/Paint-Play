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

	//Get action parameters function
	virtual bool ReadActionParameters();

	//Execute the action
	//virtual void Scramble();
	void dublicate();
	void Scramble();
	void hide();
	void match();
	void StartGame();
	bool restart(Point p);
	void Execute();
};
