#pragma once
#include "PhysicsObject.h"
class Fire:
	public PhysicsObject
{
public: 
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	Fire();
	~Fire();
};

