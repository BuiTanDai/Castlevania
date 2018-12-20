#pragma once
#include "BaseObject.h"
class Water :
	public BaseObject
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Water();
	~Water();
};

