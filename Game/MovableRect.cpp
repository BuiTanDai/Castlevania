#include "MovableRect.h"


void MovableRect::preventMovementWhenCollision(float collisionTime, int nx, int ny)
{
	/* dời vật M về sát vật S */
	if (nx != 0)
	{
		/* nếu vật va chạm theo phương x */
		setDx(collisionTime*getDx());
	}
	if (ny != 0)
	{
		/* nếu vật va chạm theo phương y */
		setDy(collisionTime*getDy());
	}

}

void MovableRect::onIntersect(MovableRect * other)
{
}

bool MovableRect::getAlive()
{
	return alive;
}

void MovableRect::setAlive(bool alive)
{
	this->alive = alive;
}

bool MovableRect::getIsRender()
{
	return isRender;
}

void MovableRect::setIsRender(bool isRender)
{
	this->isRender = isRender;
}

MovableRect::MovableRect()
{
	dx = 0;
	dy = 0;
	alive = true;
}

COLLISION_TYPE MovableRect::getCollisionType()
{
	return this->collisionType;
}
void MovableRect::setCollisionType(COLLISION_TYPE collisionType)
{
	this->collisionType = collisionType;
}


void MovableRect::setDx(float dx)
{
	this->dx = dx;
}
void MovableRect::setDy(float dy)
{
	this->dy = dy;
}
float MovableRect::getDx()
{
	return dx;
}
float MovableRect::getDy()
{
	return dy;
}

void MovableRect::goX()
{
	Rect::moveX(dx);
}

void MovableRect::goY()
{
	Rect::moveY(dy);
}

void MovableRect::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
}

MovableRect::~MovableRect()
{
}
