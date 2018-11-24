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
	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown, keyJumpDown;
	keyLeftDown = KEY::getInstance()->isLeftDown;
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;

	keyJumpDown = KEY::getInstance()->isJumpDown;

	float vx = GLOBALS_D("player_vx");

	if (getIsOnGround())
	{
		/* nếu nhấn key trái */
		if (keyLeftDown)
		{
			setVx(-vx);
		}
		/* nếu nhấn key phải */
		else if (keyRightDown)
		{
			setVx(vx);
		}
		else
		{
			setVx(0);
		}

		if (keyJumpDown)
		{
			setVy(-100);
			setIsOnGround(false);
		}
	}

	
	PhysicsObject::onUpdate(dt);
}

void Player::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	/* ngăn chặn di chuyển */
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

Player::Player()
{
	setSprite(SPR(SPRITE_INFO_SIMON));
}


Player::~Player()
{
}
