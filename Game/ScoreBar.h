#pragma once

#include"SpriteManager.h"
#include"GameTime.h"
#include"GameTexture.h"


struct SCORE_LOCATION
{
	int X;
	int Y;
	int MaxLength;

};
class ScoreBar
{

	GameTexture* scoreBar;
	Sprite* items_InScoreBar;
	static ScoreBar* instance;
	SCORE_LOCATION lifeLocation;
	SCORE_LOCATION heartLocation;
	SCORE_LOCATION stageLocation;
	SCORE_LOCATION scoreLocation;
	SCORE_LOCATION timeLocation;
	SCORE_LOCATION healthLocation;
	SCORE_LOCATION subWeaponLocation;
	SCORE_LOCATION bossHealthLocation;
	int time;
	GameTime gameTime;
	int maxHealth;
public:
	static ScoreBar* getInstance();
	ScoreBar();
	~ScoreBar();
	void render();
	void update();
	void setTime(int time);
	void decreaseTime(int time);
	void renderNumber(int num, int x, int y, int maxLength);
};