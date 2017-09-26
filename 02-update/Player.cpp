#include "Player.h"
#include "sfwdraw.h"
#include <iostream>
void Player::update()
{
	if (sfw::getKey('W') && size < 30)
	{
		if (gravity == 0)
		{
			gravity = 20;
		}
	}
	if (slamTimer == 0)
	{
		gravity -= 1;
	}
	else
	{
		gravity = 0;
	}
	if (y < 25)
	{

		y = 25;
		gravity = 0;
		size = 25;
	}
	y = y + gravity;
	if (sfw::getKey('S') && growthTimer == 0 && y > 25)
	{
		size *= 2;
		growthTimer = 5;
		slamTimer = 10;
	}
	if (sfw::getKey('A'))
	{
		x -= 5;
	}
	if (sfw::getKey('D'))
	{
		x += 5;
	}
	if (gravity == 0 && y < 30)
	{
		growthTimer--;
	}
	if (growthTimer < 0)
	{
		growthTimer = 0;
	}
	if (slamTimer > 0)
	{
		slamTimer--;
	}
}

void Player::draw()
{
	sfw::drawCircle(x, y, size);
}

void Player2::update()
{
	if (sfw::getKey('I') && size < 30)
	{
		if (gravity == 0)
		{
			gravity = 20;
		}
	}
	if (slamTimer == 0)
	{
		gravity -= 1;
	}
	else
	{
		gravity = 0;
	}
	if (y < 25)
	{
		
		y = 25;
		gravity = 0;
		size = 25;
	}
	y = y + gravity;
	if (sfw::getKey('K') && growthTimer == 0 && y > 25)
	{
		size *= 2;
		growthTimer = 5;
		slamTimer = 10;
	}
	if (sfw::getKey('J'))
	{
		x -= 5;
	}
	if (sfw::getKey('L'))
	{
		x += 5;
	}
	if (gravity == 0 && y < 30)
	{
		growthTimer--;
	}
	if (growthTimer < 0)
	{
		growthTimer = 0;
	}
	if (slamTimer > 0)
	{
		slamTimer--;
	}
}

void Player2::draw()
{
	sfw::drawCircle(x, y, size, 12, 0x800000FF);
}
