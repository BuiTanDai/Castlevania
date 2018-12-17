#include "Stair.h"


void Stair::onIntersect(MovableRect * other)
{
	auto player = Player::getInstance();
	auto key = KEY::getInstance();
	if (key->isUpDown && key->isRightDown)
	{
		setAnimation(PLAYER_UPSTAIR);
		player->setDx(getDx() + 2);
		player->setDy(getDy() - 2);

		player->setIsOnStair(true);
	}
	
	
	
	

}

Stair::Stair()
{
}


Stair::~Stair()
{
}
