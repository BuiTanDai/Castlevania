#include "Knife.h"
#include"SpriteManager.h"
#include"CollisionType.h"

Knife* Knife::instance = 0;
Knife* Knife::getInstance()
{
	if (instance == 0)
	{
		instance = new Knife();
	}
	return instance;
}
void Knife::update(float dt)
{
	/*if (getIsLastFrameAnimationDone())
	{
		setAlive(false);
	}*/

	BaseObject::update(dt);
}

void Knife::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY)
	{
		other->setAlive(false);
	}
}

Knife::Knife()
{
	setSprite(SPR(SPRITE_INFO_KNIFE));
	setCollisionType(COLLISION_TYPE_MORNING_STAR);
	setAy(0);

}


Knife::~Knife()
{
}
