#pragma once
#include"BaseObject.h"
class Candle: public BaseObject
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Candle();
	~Candle();
};

