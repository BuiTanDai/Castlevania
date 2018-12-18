#include "Stair.h"



void Stair::onIntersect(MovableRect * other)
{
	auto player = Player::getInstance();
	auto key = KEY::getInstance();
	/*if (key->isUpDown && key->isRightDown)
	{
		setAnimation(PLAYER_UPSTAIR);
		player->setX(getX() + 8);
		player->setY(getY() - 8);
	}*/
	player->setVx(0);
}

Stair::Stair()
{
}


Stair::~Stair()
{
}
