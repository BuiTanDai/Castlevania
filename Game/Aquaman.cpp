
#include "Aquaman.h"
#include "Player.h"
#include"Bullet.h"



void Aquaman::setMermanState(MERMAN_STATE mermanState)
{
	this->mermanState = mermanState;
}
//
//MERMAN_STATE Aquaman::getMermanState()
//{
//	return this->mermanState;
//}

void Aquaman::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		if (ny == -1)
		{
			//Enemy::onCollision(other, nx, ny, collisionTime);
			preventMovementWhenCollision(collisionTime, nx, ny);
			setIsOnGround(true);

		}

		if (nx != 0)
		{
			setTextureDirection((TEXTURE_DIRECTION)-nx);
		}
	}
	Enemy::onCollision(other, collisionTime, nx, ny);

}



void Aquaman::update(float dt)
{

	switch (mermanState)
	{
	case MERMAN_STATE_INVISIBLE:
		setVx(0);
		if (abs(Player::getInstance()->getMidX() - getMidX()) < 50)
		{
			setVy(-500);
			setPhysicsEnable(true);
			setIsRender(true);
			setMermanState(MERMAN_STATE_JUMP);
			setIsOnGround(false);

		}
		break;
	case MERMAN_STATE_JUMP:
		//setVx(0);
		if (getIsOnGround())
		{
			setMermanState(MERMAN_STATE_RUN);
			//
			setDirectionFollowPlayer();
			;

		}
		Enemy::update(dt);
		break;
	case MERMAN_STATE_RUN:


		setAnimation(MERMAN_ACTION_RUN);
		setDirectionFollowPlayer();
		setVx(50 * getTextureDirection());
		Enemy::update(dt);

		if (abs(Player::getInstance()->getMidX() - getMidX()) < 50)
		{
			setMermanState(MERMAN_STATE_ATTACK);
			Bullet* bullet = new Bullet();
			bullet->setX(getX());
			bullet->setY(getY());
			bullet->setTextureDirection(getTextureDirection());
			bullet->setVx(getTextureDirection() * 150);

		}


		break;

	case MERMAN_STATE_ATTACK:

		setVx(0);
		setAnimation(MERMAN_ACTION_SHOOT);
		setDirectionFollowPlayer();

		Enemy::update(dt);

		if (abs(Player::getInstance()->getMidX() - getMidX()) > 50)
			setMermanState(MERMAN_STATE_RUN);

		break;
	default:
		break;
	}
}


Aquaman::Aquaman()
{

	setMermanState(MERMAN_STATE_INVISIBLE);
	setIsRender(false);
	setPhysicsEnable(false);

}


Aquaman::~Aquaman()
{
}
