#include "WaterEffect.h"
#include"SpriteManager.h"



void WaterEffect::update(float dt)
{
	PhysicsObject::update(dt);
}

WaterEffect::WaterEffect()
{
	setSprite(SPR(SPRITE_INFO_WATER_EFFECT));
}


WaterEffect::~WaterEffect()
{
}
