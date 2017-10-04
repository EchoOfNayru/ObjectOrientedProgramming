#include "Player.h"
#include "sfwdraw.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

float Distance(float x1, float y1, float x2, float y2)
{
	return sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
}

void ApplyForce(Player& one)
{
	one.x += one.speed;
	
}

void Player::update(Player& one, Player& two)
{
	if (sfw::getKey(upKey) && size < 30)
	{
		if (gravity == 0 && one.currentJumps < one.totalJumps)
		{
			gravity = 20;
			currentJumps++;
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
		one.currentJumps = 0;
	}
	y = y + gravity;
	if (sfw::getKey(downKey) && growthTimer == 0 && y > 25)
	{
		size *= 2;
		growthTimer = 5;
		slamTimer = 10;
	}
	if (sfw::getKey(leftKey))
	{
		one.speed -= 5;
	}
	if (sfw::getKey(rightKey))
	{
		one.speed += 5;
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
		if (slamTimer == 0)
		{
			gravity = -20;
		}
	}

	//collision with other player
	

	if (Distance(one.x, one.y, two.x, two.y) < one.size + two.size)
	{
		if (one.x > two.x) 
		{
			one.x += colForce;
			one.speed -= 20;

		}
		else 
		{
			one.x -= colForce;
			one.speed += 20;
		}

		if (one.y > two.y && one.size > two.size) 
		{
			two.launchforce = (one.x > two.x) ? -38 : 38;
		}
		one.x += colForce;
	}
	else
	{
		ApplyForce(one);
	}

	one.speed = 0;
	one.speed += launchforce;
	if (launchforce > 0) 
	{
		launchforce -= 2;
	}
	if (launchforce < 0) 
	{
		launchforce += 2;
	}
}

void Player::draw()
{
	sfw::drawCircle(x, y, size, 12, color);
}