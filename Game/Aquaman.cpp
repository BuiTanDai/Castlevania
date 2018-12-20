
#include "Aquaman.h"
#include "Player.h"



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


		//setMermanState(MERMAN_STATE_ATTACK);

		break;
		/*case MERMAN_STATE_ATTACK:
			setVx(0);

			Enemy::update(dt);

				setDirectionFollowPlayer();
				setMermanState(MERMAN_STATE_RUN);

			break;*/
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
