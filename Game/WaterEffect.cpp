#include "WaterEffect.h"
#include"SpriteManager.h"



void WaterEffect::update(float dt)
{
	if (getIsLastFrameAnimationDone())
	{
		setAlive(false);
	}
	BaseObject::update(dt);
}

WaterEffect::WaterEffect()
{
	setSprite(SPR(SPRITE_INFO_WATER_EFFECT));
}


WaterEffect::~WaterEffect()
{
}
