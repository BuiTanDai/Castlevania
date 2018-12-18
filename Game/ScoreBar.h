#pragma once

#include"SpriteManager.h"
#include"GameTime.h"
#include"GameTexture.h"


//struct SCORE_LOCATION
//{
//	int X;
//	int Y;
//	int MaxLength;
//};
class ScoreBar
{

	GameTexture* scoreBar;
	static ScoreBar* instance;


public:
	static ScoreBar* getInstance();
	ScoreBar();
	~ScoreBar();
	void render();
	void update();



};