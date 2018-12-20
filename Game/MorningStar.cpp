#include "MorningStar.h"
#include"Player.h"

MorningStar* MorningStar::instance = 0;
MorningStar * MorningStar::getInstance()
{
	if (instance == 0)
	{
		instance = new MorningStar();
	}
	return instance;
}
void MorningStar::setType(MORNINGSTAR_TYPE morningStarType)
{
	this->currentMorningStarType = morningStarType;
}

void MorningStar::increaseType()
{
	if (currentMorningStarType + 1 < MORNINGSTAR_TYPE_COUNT)
	{
		if (currentMorningStarType == MORNINGSTAR_TYPE_3)
		{
			int a;
		}
		setType((MORNINGSTAR_TYPE)(currentMorningStarType + 1));
	}
	
}

MORNINGSTAR_TYPE MorningStar::getType()
{
	return this->currentMorningStarType;
}

void MorningStar::update(float dt)
{
	setAnimation(currentMorningStarType);
	BaseObject::update(dt);
	if (getIsLastFrameAnimationDone())
	{
		setAlive(false);
	}
}

void MorningStar::render(Camera * camera)
{
	auto playerFrameIndex = Player::getInstance()->getFrameAnimation();
	setFrameAnimation(playerFrameIndex);
	setWidth(getWidthCurrentFrame());
	setHeight(getHeightCurrentFrame());
	setTextureDirection(Player::getInstance()->getTextureDirection());

	auto player = Player::getInstance();

	if (getTextureDirection() == TEXTURE_DIRECTION_RIGHT)
	{
		switch (playerFrameIndex)
		{
		case 0:
			setX(Player::getInstance()->getX()  + location[0].x);
			setY(Player::getInstance()->getY()  + location[0].y);
			break;
		case 1:
			setX(Player::getInstance()->getX() - getWidthCurrentFrame() + location[1].x);
			setY(Player::getInstance()->getY() + location[1].y);
			break;
		case 2:
			setX(Player::getInstance()->getX() + location[2].x);
			setY(Player::getInstance()->getY() + location[2].y);
			/*if (Player::getInstance()->getAction() == SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT)
			{
				setY(getY() + 2);
			}
			if (!Player::getInstance()->isOnGround())
			{
				setY(getY() - 2);
			}*/
			break;
		default:
			break;
		}
	}
	else
	{
		switch (playerFrameIndex)
		{
		case 0:
			setX(Player::getInstance()->getRight() - location[0].x);
			setY(Player::getInstance()->getY() + location[0].y);
			break;
		case 1:
			setX(Player::getInstance()->getRight() - location[1].x);
			setY(Player::getInstance()->getY() + location[1].y);
			break;
		case 2:
			setX(Player::getInstance()->getleft() - getWidthCurrentFrame());
			setY(Player::getInstance()->getY() + location[2].y);
			/*if (Player::getInstance()->getAction() == SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT)
			{
				setY(getY() + 2);
			}
			if (!Player::getInstance()->isOnGround())
			{
				setY(getY() - 2);
			}*/
			break;
		default:
			break;
		}
	}

	BaseObject::render(camera);
}

void MorningStar::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == COLLISION_TYPE_STATIC_OBJECT)
	{
		other->setAlive(false);
	}
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY)
	{
		other->setAlive(false);
	}
	if (other->getCollisionType() == COLLISION_ITEM)
	{
		other->setAlive(true);
	}
	if (other->getCollisionType() == COLLISION_TYPE_STATIC_OBJECT || other->getCollisionType() == COLLISION_TYPE_ENEMY)
	{
		ExplosionEffect* explosion = new ExplosionEffect();
		explosion->setLocation(other->getMidX(), other->getMidY());
	}
}

void MorningStar::OnCollision()
{
}

MorningStar::MorningStar()
{
	setAlive(false);
	setSprite(SPR(SPRITE_INFO_MORNINGSTAR));
	setTextureDirection(TEXTURE_DIRECTION_RIGHT);
	currentMorningStarType = MORNINGSTAR_TYPE_1;
	ifstream fs("assets/sprites/weapon/weapon.location.txt");
	fs >> location[0].x >> location[0].y >> location[1].x >> location[1].y >> location[2].x >> location[2].y;
	setCollisionType(COLLISION_TYPE_MORNING_STAR);
}



MorningStar::~MorningStar()
{
}


