#pragma once
class Player2;

class Player 
{
public:
	float x;
	float y;
	float size;
	float speed;
	float growthTimer;
	float slamTimer;
	float gravity;

	void update(Player& one, Player2& two);
	void draw();
};

class Player2 
{
public:
	float x;
	float y;
	float size;
	float speed;
	float growthTimer;
	float slamTimer;
	float gravity;

	void update(Player& one, Player2& two);
	void draw();
};