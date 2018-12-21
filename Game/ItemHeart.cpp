#include "ItemHeart.h"




void ItemHeart::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getState() == ITEM_STATE_VISIBLE)
	{
		auto scoreBar = ScoreBar::getInstance();
		scoreBar->setHeartCount(scoreBar->getHeartCount() + 1);
	}
	Item::onIntersect(other);
}

ItemHeart::ItemHeart()
{
}


ItemHeart::~ItemHeart()
{
}
