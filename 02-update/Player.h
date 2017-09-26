#pragma once

class Player 
{
public:
	float x;
	float y;
	float size;
	float growthTimer;
	float slamTimer;
	float gravity;

	void update();
	void draw();
};

class Player2 
{
public:
	float x;
	float y;
	float size;
	float growthTimer;
	float slamTimer;
	float gravity;

	void update();
	void draw();
};