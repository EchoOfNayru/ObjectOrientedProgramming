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
	Player you;
	me.color = MAGENTA;
	you.color = CYAN;


	me.colForce = 10;
	you.colForce = 10;
	me.launchforce = 0;
	you.launchforce = 0;

	me.x = 400;
	me.y = 25.1;
	you.x = 750;
	you.y = 25.1;
	me.size = 25;
	you.size = 25;
	me.speed = 0;
	you.speed = 0;

	me.upKey = 'W';
	me.downKey = 'S';
	me.leftKey = 'A';
	me.rightKey = 'D';
	
	you.upKey = 'I';
	you.downKey = 'K';
	you.leftKey = 'J';
	you.rightKey = 'L';

	//game loop
	while (sfw::stepContext()) 
	{
		me.update(me, you);
		me.draw();
		you.update(you, me);
		you.draw();

		//sfw::drawLine(me.x, me.y, you.x, you.y, RED);
	}

	//clean up
	sfw::termContext();
}