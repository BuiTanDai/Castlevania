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
	this->morningStarType = morningStarType;
}

MORNINGSTAR_TYPE MorningStar::getType()
{
	return this->morningStarType;
}

void MorningStar::update(float dt)
{
	if (getIsLastFrameAnimationDone())
	{
		setAlive(false);
	}
	BaseObject::update(dt);
}

void MorningStar::render(Camera * camera)
{
	//auto playerFrameIndex = Player::getInstance()->getFrameAnimation();
	//setFrameAnimation(playerFrameIndex);
	//setWidth(getWidthCurrentFrame());
	//setHeight(getHeightCurrentFrame());
	//setTextureDirection(Player::getInstance()->getTextureDirection());

	//auto player = Player::getInstance();

	//if (getTextureDirection() == TEXTURE_DIRECTION_RIGHT)
	//{
	//	switch (playerFrameIndex)
	//	{
	//	case 0:
	//		setX(Player::getInstance()->getX() - getWidthCurrentFrame() + location[0].x);
	//		setY(Player::getInstance()->getY() - location[0].y);
	//		break;
	//	case 1:
	//		setX(Player::getInstance()->getX() - getWidthCurrentFrame() + location[1].x);
	//		setY(Player::getInstance()->getY() - location[1].y);
	//		break;
	//	case 2:
	//		setX(Player::getInstance()->getX() + location[2].x);
	//		setY(Player::getInstance()->getY() - location[2].y);
	//		/*if (Player::getInstance()->getAction() == SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT)
	//		{
	//			setY(getY() + 2);
	//		}
	//		if (!Player::getInstance()->isOnGround())
	//		{
	//			setY(getY() - 2);
	//		}*/
	//		break;
	//	default:
	//		break;
	//	}
	//}
	//else
	//{
	//	switch (playerFrameIndex)
	//	{
	//	case 0:
	//		setX(Player::getInstance()->getRight());
	//		setY(Player::getInstance()->getY() - location[0].y);
	//		break;
	//	case 1:
	//		setX(Player::getInstance()->getRight());
	//		setY(Player::getInstance()->getY() - location[1].y);
	//		break;
	//	case 2:
	//		setX(Player::getInstance()->getleft() - getWidth());
	//		setY(Player::getInstance()->getY() - location[2].y);
	//		/*if (Player::getInstance()->getAction() == SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT)
	//		{
	//			setY(getY() + 2);
	//		}
	//		if (!Player::getInstance()->isOnGround())
	//		{
	//			setY(getY() - 2);
	//		}*/
	//		break;
	//	default:
	//		break;
	//	}
	//}
	
	BaseObject::render(camera);
}

void MorningStar::OnCollision()
{
}

MorningStar::MorningStar()
{
	setSprite(SPR(SPRITE_INFO_MORNINGSTAR));
	setTextureDirection(TEXTURE_DIRECTION_RIGHT);
	morningStarType = MORNINGSTAR_TYPE_1;
	ifstream fs("assets/sprites/weapon/weapon.location.txt");
	fs >> location[0].x >> location[0].y >> location[1].x >> location[1].y >> location[2].x >> location[2].y;
}



MorningStar::~MorningStar()
{
}


