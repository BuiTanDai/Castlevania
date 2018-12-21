#include "ScoreBar.h"

#define NUMBER_WIDTH 8
#define HEALTH_WIDTH 4

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
	items_InScoreBar = SpriteManager::getInstance()->getSprite(SPRITE_INFO_ITEMS_IN_SCORE_BAR);
	gameTime.setTickPerFrame(1000);
	ifstream ifs("assets/sprites/misc/score_bar_item_location.txt");
	ignoreLineIfstream(ifs, 1);
	ifs >> playerLifeLocation.X >> playerLifeLocation.Y >> playerLifeLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> heartCountLocation.X >> heartCountLocation.Y >> heartCountLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> stageLocation.X >> stageLocation.Y >> stageLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> scoreLocation.X >> scoreLocation.Y >> scoreLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> timeLocation.X >> timeLocation.Y >> timeLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> playerHealthLocation.X >> playerHealthLocation.Y >> playerHealthLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> subWeaponLocation.X >> subWeaponLocation.Y;

	ignoreLineIfstream(ifs, 2);
	ifs >> bossHealthLocation.X >> bossHealthLocation.Y >> bossHealthLocation.MaxLength;

	setTime(1000);
	setPlayerLife(3);
	setHeartCount(5);
	setScore(0);
	setCurrentStageNumber(1);
	setHealth(playerHealthLocation.MaxLength);
}


ScoreBar::~ScoreBar()
{
}

void ScoreBar::render()
{
	scoreBar->Render(0, 0, 0, 0, 0);
	renderNumber(time, timeLocation.X, timeLocation.Y, timeLocation.MaxLength);
	renderNumber(playerLife, playerLifeLocation.X, playerLifeLocation.Y, playerLifeLocation.MaxLength);
	renderNumber(heartCount, heartCountLocation.X, heartCountLocation.Y, heartCountLocation.MaxLength);
	renderNumber(score, scoreLocation.X, scoreLocation.Y, scoreLocation.MaxLength);
	renderNumber(currentStageNumber, stageLocation.X, stageLocation.Y, stageLocation.MaxLength);
	renderHealth(health, playerHealthLocation.X, playerHealthLocation.Y, playerHealthLocation.MaxLength);
}

void ScoreBar::update()
{
	if (gameTime.atTime())
	{
		decreaseTime(1);
	}
}

void ScoreBar::setTime(int time)
{
	if (time >= 0)
	{
		this->time = time;
	}
}

void ScoreBar::decreaseTime(int time)
{
	this->time -= time;
}

int ScoreBar::getHealth()
{
	return health;
}

void ScoreBar::setHealth(int health)
{
	this->health = health;
}

//void ScoreBar::increaseHealth(int health)
//{
//	setHealth(this->health + health);
//}

void ScoreBar::restoreHealth()
{
	this->health = playerHealthLocation.MaxLength;
}

void ScoreBar::renderNumber(int num, int x, int y, int maxLength)
{
	int currentX = x + NUMBER_WIDTH * maxLength;
	int length = 0;
	while (num != 0)
	{
		currentX -= NUMBER_WIDTH;
		int value = num % 10;
		items_InScoreBar->render(currentX, y, MISC_SPRITE_ID_NUMBER, value);
		num /= 10;
		length++;
	}
	for (; length < maxLength; length++)
	{
		currentX -= NUMBER_WIDTH;
		items_InScoreBar->render(currentX, y, MISC_SPRITE_ID_NUMBER, 0);
	}
}

void ScoreBar::renderHealth(int currentHealth, int x, int y, int maxHealth)
{
	int sub = maxHealth - currentHealth;
	int currentX = x + HEALTH_WIDTH * maxHealth;
	while (sub != 0)
	{
		currentX -= HEALTH_WIDTH;
		items_InScoreBar->render(currentX, y, MISC_SPRITE_ID_LOST_HEALTH, 0);
		sub -= 1;
	}
}

int ScoreBar::getPlayerLife()
{
	return playerLife;
}

void ScoreBar::setPlayerLife(int playerLife)
{
	this->playerLife = playerLife;
}

void ScoreBar::increasePlayerLife(int playerLife)
{
	setPlayerLife(this->playerLife + playerLife);
}

int ScoreBar::getHeartCount()
{
	return heartCount;
}

void ScoreBar::setHeartCount(int heartCount)
{
	this->heartCount = heartCount;
}

void ScoreBar::increaseHeartCount(int heartCount)
{
	setHeartCount(this->heartCount + heartCount);
}

void ScoreBar::setCurrentStageNumber(int currentStageNumber)
{
	this->currentStageNumber = currentStageNumber;
}

int ScoreBar::getCurrentStageNumber()
{
	return currentStageNumber;
}

void ScoreBar::increaseCurrentStageNumber(int number)
{
	setCurrentStageNumber(this->currentStageNumber + number);
}

void ScoreBar::setScore(int score)
{
	this->score = score;
}

int ScoreBar::getScore()
{
	return score;
}

void ScoreBar::increaseScore(int score)
{
	setScore(this->score + score);
}
