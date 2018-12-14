#pragma once
#include"PhysicsObject.h"
/* lớp Zombie để hiện thực lớp PhysicsObject */
class Zombie :
	public PhysicsObject
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Zombie();
	~Zombie();
};
