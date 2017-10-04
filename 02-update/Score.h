#pragma once
#include <string>
#include "Player.h"
class ScoreBoard
{
public:
	int score;
	std::string printScore;
	float X;
	float Y;
	float w;
	float h;
	ScoreBoard(float xx, float yy);
	unsigned int Font;
	Player *p;
	void Update();
	void Draw();
};