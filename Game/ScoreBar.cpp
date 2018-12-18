#include "ScoreBar.h"

ScoreBar * ScoreBar::instance = 0;
ScoreBar * ScoreBar::getInstance()
{
	if (instance == 0)
		instance = new ScoreBar();
	return instance;
}

ScoreBar::ScoreBar()
{
	scoreBar = new GameTexture("assets/sprites/misc/score_bar.png", D3DCOLOR_XRGB(10, 20, 60));
}


ScoreBar::~ScoreBar()
{
}

void ScoreBar::render()
{
	scoreBar->Render(0, 0, 0, 0, 0);

}

void ScoreBar::update()
{
}
