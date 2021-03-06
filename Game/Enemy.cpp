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

//void Enemy::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
//{
//	/*if (other->getCollisionType() == COLLISION_TYPE_PLAYER)
//	{
//		auto player = Player::getInstance();
//		player->setAnimation(PLAYER_INJURED);
//		player->setDx(-5);
//		player->setVy(-70);
//	}*/
//	PhysicsObject::onCollision(other, nx, ny, collisionTime);
//}

void Enemy::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER)
	{
		
		
		if (Player::getInstance()->getPlayerState() != PLAYER_STATE_DIE && Player::getInstance()->getPlayerState() != PLAYER_STATE_INJURED)
		{
			auto player = Player::getInstance();
			player->setHealth(player->getHealth() - 2);
			player->setIsOnGround(false);
			player->setPlayerState(PLAYER_STATE_INJURED);
		}
	}

	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Enemy::onIntersect(MovableRect * other)
{
	
}


