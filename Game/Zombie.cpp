#include "Zombie.h"



Zombie::Zombie()
{
}

//void Zombie::setZombieState(ZOMBIE_STATE zombieState)
//{
//	this->zombieState = zombieState;
//}

void Zombie::onInitFormFile(fstream & fs)
{
	/*string name;
	fs >> name;
	int direction;
	fs >> direction;
	setTextureDirection((TEXTURE_DIRECTION)direction);
	if (direction == -1)
	{
		setZombieState(ZOMBIE_STATE::ZOMBIE_STATE_VISIBLE);
	}
	else
	{
		setZombieState(ZOMBIE_STATE::ZOMBIE_STATE_INVISIBLE);
	}*/
}

//void Zombie::setDx(float dx)
//{
//	Enemy::setDx(dx);
//}

void Zombie::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER)
	{
		auto player = Player::getInstance();
		player->setVy(-50);
		player->setDx(-4);
	}
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Zombie::update(float dt)
{
	setVx(-40);
	Enemy::update(dt);
}

Zombie::~Zombie()
{
}
