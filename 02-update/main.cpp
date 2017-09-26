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
	me.y = 26;
	you.x = 450;
	you.y = 26;
	me.size = 25;
	you.size = 25;

	//game loop
	while (sfw::stepContext()) 
	{
		me.update();
		me.draw();
		you.update();
		you.draw();
	}

	//clean up
	sfw::termContext();
}