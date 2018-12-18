#include "Stair.h"


void Stair::onIntersect(MovableRect * other)
{
	auto player = Player::getInstance();
	auto key = KEY::getInstance();
	if (key->isUpDown && key->isRightDown)
	{
		player->setDx(1);
		player->setDy(-1);

		player->setIsOnStair(true);
		player->setIsOnGround(false);
	}

	
}

Stair::Stair()
{
}


Stair::~Stair()
{
}
