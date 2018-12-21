#include "Bat.h"
#include"Player.h"


void Bat::setBatState(BAT_STATE batState)
{
	this->batState = batState;
}

void Bat::update(float dt)
{
	switch (batState)
	{
	case BAT_STATE_INVISIBLE:
	{
		
		if (abs(Player::getInstance()->getMidX() - getMidX()) < 50)
		{
			setBatState(BAT_STATE_VISIBLE);
			setPhysicsEnable(true);


			//setIsOnGround(true);
			Enemy::update(dt);
		}
	}
	
		break;
	case BAT_STATE_VISIBLE:
	{
		setIsRender(true);
		setAnimation(BAT_ACTION_FLY);


		alpha += 1;
		if (alpha >= 360)
		{
			alpha -= 360;
		}
		setY(this->getY() - 1.5 * sin(alpha * 0.1));
		setVx(-50);
		





		Enemy::update(dt);
	}
		break;
	default:
		break;

	}
}

void Bat::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
}

Bat::Bat()
{
	setBatState(BAT_STATE_INVISIBLE);
	setIsRender(false);
	setPhysicsEnable(false);
	alpha = 0;
	setAy(0);
	setTextureDirection(TEXTURE_DIRECTION_LEFT);
}


Bat::~Bat()
{
}
