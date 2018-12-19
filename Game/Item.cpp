#include "Item.h"





void Item::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == COLLISION_TYPE_MORNING_STAR)
	{
		if (item_state == ITEM_STATE_INVISIBLE)
		{
			setState(ITEM_STATE_VISIBLE);
		}
	}
}

void Item::setState(ITEM_STATE item_state)
{
	this->item_state = item_state;
}

void Item::update(float dt)
{
	switch (item_state)
	{
	case ITEM_STATE_VISIBLE:
		setAlive(true);
		setPhysicsEnable(true);
		break;
	case ITEM_STATE_INVISIBLE:
		setAlive(false);
		setPhysicsEnable(false);
		break;
	default:
		break;
	}
	PhysicsObject::update(dt);
}

Item::Item()
{
}


Item::~Item()
{
}
