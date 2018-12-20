#include "Panther.h"



void Panther::setPantherState(PANTHER_STATE pantherState)
{
	this->pantherState = pantherState;
}

void Panther::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (ny == -1)
	{
		Enemy::onCollision(other, collisionTime, nx, ny);
	}

	if (other->getCollisionType() == COLLISION_TYPE_GROUND && ny == -1 && pantherState == PANTHER_STATE_RUN &&
		((getDx() < 0 && getleft() <= other->getleft()) ||
		(getDx() > 0 && getRight() >= other->getRight()))
		)
	{
		setPantherState(PANTHER_STATE_JUMP);
		setDy(0);

		//setDirectionFollowPlayer();
		setVy(-120);
		setVx(getTextureDirection() * 140);
		setIsOnGround(false);

	}










	/*preventMovementWhenCollision(collisionTime, nx, ny);*/

}

void Panther::update(float dt)
{
	switch (pantherState)
	{
	case PANTHER_STATE_STAND:
		setDirectionFollowPlayer();
		setDx(0);
		setVx(0);
		setVy(0);
		setDy(0);
		setAnimation(PANTHER_ACTION_STAND);
		if (abs(getMidX() - Player::getInstance()->getMidX()) < 50)
		{
			setPantherState(PANTHER_STATE_RUN);
			setDirectionFollowPlayer();
		}
		break;
	case PANTHER_STATE_JUMP:
		setAnimation(PANTHER_ACTION_JUMP);

		if (getIsOnGround())
		{
			//setPhysicsEnable(true);
			setPantherState(PANTHER_STATE_RUN);
			setDirectionFollowPlayer();
			setVx(getTextureDirection() * 80);
		}
		break;
	case PANTHER_STATE_RUN:
		/*	if (abs(getMidX() - Player::getInstance()->getMidX()) > 20)
			{
				setPantherState(PANTHER_STATE_RUN);

			}*/
			//setDirectionFollowPlayer();
		setAnimation(PANTHER_ACTION_RUN);
		setVx(getTextureDirection() * 140);
		break;
	default:
		break;
	}
	Enemy::update(dt);

}

Panther::Panther()
{
}


Panther::~Panther()
{
}
