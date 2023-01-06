#pragma once
#include "operation.h"
#include "../controller.h"

class Play :public operation
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
public:
	int WrongAnswers = 0;
	int RightAnswers = 0;
	Play(controller* pCont);

	//Get action parameters function
	virtual bool ReadActionParameters();

	//Execute the action
	//virtual void Scramble();
	void dublicate();
	void Scramble();
	void StartGame();
	bool restart(Point p);
	~Play();
};
