#include <iostream>
#include "sfwdraw.h"
#include "Player.h"
#include "Score.h"

void Reset(Player &one, Player &two) 
{
	one.x = 400;
	one.y = 350;
	one.size = 25;
	one.speed = 0;
	one.slamTimer = 25;
	one.launchforce = 0;

	two.x = 1200;
	two.y = 350;
	two.size = 25;
	two.speed = 0;
	two.slamTimer = 25;
	two.launchforce = 0;
}

void EndRound(Player &one, Player &two) 
{
	if (one.x > 1600 || one.x < 0) 
	{
		two.points++;
		Reset(one, two);
	}

	if (two.x > 1600 || two.x < 0) 
	{
		one.points++;
		Reset(one, two);
	}
}

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
	me.points = 0;
	you.points = 0;

	me.colForce = 10;
	you.colForce = 10;
	me.launchforce = 0;
	you.launchforce = 0;

	Reset(me, you);

	me.upKey = 'W';
	me.downKey = 'S';
	me.leftKey = 'A';
	me.rightKey = 'D';
	
	you.upKey = 'I';
	you.downKey = 'K';
	you.leftKey = 'J';
	you.rightKey = 'L';

	ScoreBoard forMe(50, 500);
	forMe.p = &me;


	ScoreBoard forYou(1550, 500);
	forYou.p = &you;

	//game loop
	while (sfw::stepContext()) 
	{
		me.update(me, you);
		me.draw();
		you.update(you, me);
		you.draw();

		forMe.Update();
		forMe.Draw();
		forYou.Update();
		forYou.Draw();

		EndRound(me, you);
		std::cout << you.points << std::endl;

		//sfw::drawLine(me.x, me.y, you.x, you.y, RED);
	}

	//clean up
	sfw::termContext();
}