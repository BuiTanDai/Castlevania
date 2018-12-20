#include "EndStair.h"



void EndStair::onIntersect(MovableRect * other)
{
	auto player = Player::getInstance();
	if (player->getIsOnStair() && player->getIsMoveUp() && player->getBottom() > this->getBottom())
	{
		player->setIsMovingStair(true);
	}
}

EndStair::EndStair()
{

}


EndStair::~EndStair()
{
}
