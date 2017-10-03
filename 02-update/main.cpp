#include <iostream>
#include "sfwdraw.h"
#include "Player.h"

int main() 
{
	// create a window
	sfw::initContext(1600, 600, "Pizza");

	// set the BG color
	sfw::setBackgroundColor(NONE);

	Player me;
	Player2 you;

	me.x = 400;
	me.y = 25.1;
	you.x = 750;
	you.y = 25.1;
	me.size = 25;
	you.size = 25;
	me.speed = 0;
	you.speed = 0;

	//game loop
	while (sfw::stepContext()) 
	{
		me.update(me, you);
		me.draw();
		you.update(me, you);
		you.draw();
	}

	//clean up
	sfw::termContext();
}