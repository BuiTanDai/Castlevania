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
	SCORE_LOCATION playerLifeLocation;
	SCORE_LOCATION heartCountLocation;
	SCORE_LOCATION stageLocation;
	SCORE_LOCATION scoreLocation;
	SCORE_LOCATION timeLocation;
	SCORE_LOCATION playerHealthLocation;
	SCORE_LOCATION subWeaponLocation;
	SCORE_LOCATION bossHealthLocation;
	GameTime gameTime;

	int time;
	int health;
	int bossHealth;
	int playerLife;
	int heartCount;
	int currentStageNumber;
	int score;
	
	
public:
	static ScoreBar* getInstance();
	ScoreBar();
	~ScoreBar();
	void render();
	void update();
	void renderNumber(int num, int x, int y, int maxLength);
	void renderHealth(int health, int x, int y, int maxHealth);

	void setTime(int time);
	void decreaseTime(int time);


	int getHealth();
	void setHealth(int health);
	//void increaseHealth(int health);
	void restoreHealth();


	/*int getBossHealth();
	void setBossHealth(int health);
	void increaseBossHealth(int health);
	void restoreBossHealth();*/

	int getPlayerLife();
	void setPlayerLife(int playerLife);
	void increasePlayerLife(int playerLife);

	int getHeartCount();
	void setHeartCount(int heartCount);
	void increaseHeartCount(int heartCount);

	void setCurrentStageNumber(int currentStageNumber);
	int getCurrentStageNumber();
	void increaseCurrentStageNumber(int number);

	void setScore(int score);
	int getScore();
	void increaseScore(int score);
};