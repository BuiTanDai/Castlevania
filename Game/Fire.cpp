#include "Fire.h"



void Fire::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	/* ngăn chặn di chuyển */
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Fire::onIntersect(MovableRect * other)
{
	
}

Fire::Fire()
{
}


Fire::~Fire()
{
}
