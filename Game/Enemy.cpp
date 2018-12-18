#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::onInitFromFile(fstream & fs)
{
}

void Enemy::setDirectionFollowPlayer()
{
	if (Player::getInstance()->getMidX() - getMidX() < 0)
	{
		setTextureDirection(TEXTURE_DIRECTION_LEFT);
	}
	else
	{
		setTextureDirection(TEXTURE_DIRECTION_RIGHT);
	}
}

void Enemy::onCollision(MovableRect * other, int nx, int ny, float collisionTime)
{
	PhysicsObject::onCollision(other, nx, ny, collisionTime);
}


