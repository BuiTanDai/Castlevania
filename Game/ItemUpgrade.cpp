#include "ItemUpgrade.h"



void ItemUpgrade::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER)
	{
		this->setAlive(false);
		MorningStar::getInstance()->increaseType();
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
