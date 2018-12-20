#include "Stair.h"


void Stair::onIntersect(MovableRect * other)
{
	auto player = Player::getInstance();
	auto key = KEY::getInstance();
	if (key->isUpDown && key->isRightDown)
	{
		player->setIsMoveUp(true);
		player->setPlayerState(PLAYER_STATE_ON_STAIR);
	}

	
}

Stair::Stair()
{
}


Stair::~Stair()
{
}
