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

void ApplyForce2(Player2& two) 
{
	two.x += two.speed;
}

void Player::update(Player& one, Player2& two)
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
		one.speed = -5;
	}
	if (sfw::getKey('D'))
	{
		one.speed = 5;
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
		one.speed *= -1;
		ApplyForce(one);
	}
	else
	{
		ApplyForce(one);
	}

	one.speed = 0;
	std::cout << one.x << "  " << one.y << std::endl;
}

void Player::draw()
{
	sfw::drawCircle(x, y, size);
}

void Player2::update(Player& one, Player2& two)
{
	//gravity and slam
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
		two.speed = -5;
	}
	if (sfw::getKey('L'))
	{
		two.speed = 5;
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
		two.speed *= -1;
		ApplyForce2(two);
	}
	else
	{
		ApplyForce2(two);
	}

	two.speed = 0;
}

void Player2::draw()
{
	printf("%f\n", speed);
	sfw::drawCircle(x, y, size, 12, 0x800000FF);
}