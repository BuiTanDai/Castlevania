#include "ItemUpgrade.h"



void ItemUpgrade::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getState() == ITEM_STATE_VISIBLE)
	{
		this->setAlive(false);
		MorningStar::getInstance()->increaseType();
		Player::getInstance()->setPlayerState(PLAYER_STATE_UPGRADE);
	}
	//MorningStar::getInstance()->increaseType();
	Item::onIntersect(other);
}

ItemUpgrade::ItemUpgrade()
{
}


ItemUpgrade::~ItemUpgrade()
{
}
