#include "Player.h"



Player * Player::instance = 0;
Player * Player::getInstance()
{
	if (instance == 0)
	{
		instance = new Player();
	}
	return instance;
}

void Player::onUpdate(float dt)
{
	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown, keyJumpDown, keyAttackPress;
	keyLeftDown = KEY::getInstance()->isLeftDown;
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;

	keyJumpDown = KEY::getInstance()->isJumpDown;
	keyAttackPress = KEY::getInstance()->isAttackPress;

	float vx = GLOBALS_D("player_vx");


		//mặt đất
		if (getIsOnGround())
		{
			/* nếu nhấn key trái */
			if (keyLeftDown)
			{
				setVx(-vx);
				setAnimation(PLAYER_RUN);
				setTextureDirection(TEXTURE_DIRECTION_LEFT);
			}
			/* nếu nhấn key phải */
			else if (keyRightDown)
			{
				setVx(vx);
				setAnimation(PLAYER_RUN);
				setTextureDirection(TEXTURE_DIRECTION_RIGHT);
			}
			else if (keyDownDown)
			{
				if (keyAttackPress)
				{
					setVx(0);
					setAnimation(PLAYER_SIT_ATTACK);
					usingMorningStar();
					setIsAttacking(true);
				}
				else if (getIsLastFrameAnimationDone()) {
					setVx(0);
					setAnimation(PLAYER_JUMP);
				}

			}
			else if (keyAttackPress & getDx() == 0 & getVx() == 0)
			{
				setAnimation(PLAYER_ATTACK);
				usingMorningStar();
				setIsAttacking(true);
			}
			else if (getIsAttacking())
			{
				if (getIsLastFrameAnimationDone())
				{
					setIsAttacking(false);
					setAnimation(PLAYER_STAND);
					setVx(0);
				}
			}
			else
			{
				setVx(0);
				setAnimation(PLAYER_STAND);
			}

			if (keyJumpDown)
			{
				setIsOnGround(false);
				setVy(-120);
				setAnimation(PLAYER_STAND);

			}
		}
		else
		{
			//trên không
			if (keyLeftDown)
			{
				setAnimation(PLAYER_JUMP);
				setVx(-vx);
				setTextureDirection(TEXTURE_DIRECTION_LEFT);
			}
			else if (keyRightDown)
			{
				setAnimation(PLAYER_JUMP);
				setVx(vx);
				setTextureDirection(TEXTURE_DIRECTION_RIGHT);
			}
			else if (keyAttackPress)
				{
					setIsAttacking(true);
					setVx(0);
					setAnimation(PLAYER_ATTACK);
					usingMorningStar();
				}
			else if (getIsAttacking())
			{
				if (getIsLastFrameAnimationDone())
				{
					setIsAttacking(false);
					setAnimation(PLAYER_STAND);
					setVx(0);
				}
			}
			else
			{ 
				setAnimation(PLAYER_STAND);
				setVx(0);
			}
			
		}
	
		


	PhysicsObject::onUpdate(dt);
	
	
}

void Player::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	/* ngăn chặn di chuyển */

	if(other->getCollisionType()==COLLISION_TYPE_GROUND)
	{
		preventMovementWhenCollision(collisionTime, nx, ny);
		PhysicsObject::onCollision(other, collisionTime, nx, ny);
	}

	/*if (other->getCollisionType() == COLLISION_TYPE_GATE)
	{
		setDx(0);
		PhysicsObject::onCollision(other, collisionTime, nx, ny);
	}*/

	/*if (other->getCollisionType() == COLLISION_TYPE_STAIR)
	{
		preventMovementWhenCollision(collisionTime, nx, ny);
		PhysicsObject::onCollision(other, collisionTime, nx, ny);
	}*/
	
}

void Player::usingMorningStar()
{
	MorningStar::getInstance()->setAlive(true);
}

Player::Player()
{
	setSprite(SPR(SPRITE_INFO_SIMON));
	setTextureDirection(TEXTURE_DIRECTION_RIGHT);
}


Player::~Player()
{
}
