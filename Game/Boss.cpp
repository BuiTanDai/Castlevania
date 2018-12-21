#include "Boss.h"



void Boss::setBossState(BOSS_STATE bossState)
{
	this->bossState = bossState;

}

void Boss::update(float dt)
{
	switch (bossState)
	{
	case BOSS_STATE_INVISIBLE:
		if (abs(Player::getInstance()->getMidX() - getMidX()) < 150)
		{
			setBossState(BOSS_STATE_WAIT);
			setIsRender(true);
			setPhysicsEnable(true);
			setAnimation(BOSS_ACTION_WAIT);
			
			Enemy::update(dt);
		}
		break;
	case BOSS_STATE_WAIT:

		if (abs(Player::getInstance()->getMidX() - getMidX()) < 50)
		{
			//setBossState(BOSS_STATE_FAST);
			setIsRender(true);
			setAnimation(BOSS_ACTION_FLY);
			//setVy(50);

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
		
	/*case BOSS_STATE_FAST:
		break;
	case BOSS_STATE_SLOW:
		break;*/
	default:
		break;

	}
}

void Boss::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
}

Boss::Boss()
{
	setBossState(BOSS_STATE_INVISIBLE);
	setIsRender(false);
	setPhysicsEnable(false);
	alpha = 0;
	setAy(0);

}


Boss::~Boss()
{
}
