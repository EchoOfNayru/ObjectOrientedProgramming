#include "Score.h"
#include "sfwdraw.h"

ScoreBoard::ScoreBoard( float xx, float yy)
{
	Font = sfw::loadTextureMap("fontmap.png", 16, 16);
	
	score = 0;
	w = 15;
	h = 15;
	X = xx;
	Y = yy;
}

void ScoreBoard::Update()
{
	score = p->points;
	printScore = std::to_string(score);

}

void ScoreBoard::Draw()
{
	sfw::drawString(Font, printScore.c_str(), X, Y, w, h);
}
