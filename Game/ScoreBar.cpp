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
	ifs >> lifeLocation.X >> lifeLocation.Y >> lifeLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> heartLocation.X >> heartLocation.Y >> heartLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> stageLocation.X >> stageLocation.Y >> stageLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> scoreLocation.X >> scoreLocation.Y >> scoreLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> timeLocation.X >> timeLocation.Y >> timeLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> healthLocation.X >> healthLocation.Y >> maxHealth;

	ignoreLineIfstream(ifs, 2);
	ifs >> subWeaponLocation.X >> subWeaponLocation.Y;

	ignoreLineIfstream(ifs, 2);
	ifs >> bossHealthLocation.X >> bossHealthLocation.Y >> bossHealthLocation.MaxLength;

	setTime(1000);
}


ScoreBar::~ScoreBar()
{
}

void ScoreBar::render()
{
	scoreBar->Render(0, 0, 0, 0, 0);
	renderNumber(time, timeLocation.X, timeLocation.Y, timeLocation.MaxLength);
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
