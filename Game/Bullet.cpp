#include "Bullet.h"
#include"SpriteManager.h"


void Bullet::update(float dt)
{
	PhysicsObject::update(dt);
}

void Bullet::onIntersect(MovableRect * other)
{
}

Bullet::Bullet()
{
	setSprite(SPR(SPRITE_INFO_BULLET));
	setAy(0);
	setCollisionType(COLLISION_TYPE_ENEMY);
}


Bullet::~Bullet()
{
}
