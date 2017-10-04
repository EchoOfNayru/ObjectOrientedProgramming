#pragma once

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
	float colForce;
	float launchforce;
	float currentJumps = 0;
	float totalJumps = 2;
	
	int points;
	

	// player specific settings
	unsigned int upKey;
	unsigned int downKey;
	unsigned int leftKey;
	unsigned int rightKey;

	unsigned int color;
	bool col = false;

	void update(Player& one, Player& two);
	void draw();
};