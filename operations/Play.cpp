#include "Play.h"

#include <Windows.h>
#include <Mmsystem.h>

Play::Play(controller* pCont) : operation(pCont)
{
}

bool Play::ReadActionParameters()
{
	return false;
}
void Play::dublicate() {
	
	pGraph->GDuplicate();
}

void Play::Scramble()  //Here the scrample function will put
{
	//the function of scramble should put here
	StartGame();
}
void Play::StartGame() {

}
bool Play::restart(Point p) {
	int x = p.x;  
	int y = p.y;
	/*if (x >= 13 * 50 && x <= 15 * 50 && y >= 0 && y <= 50)   //Ishould here put the coorednates of restart
		if (x < 14 * 50)
			return true;*/
	return false;
}

Play::~Play()
{
}