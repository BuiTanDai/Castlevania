#pragma once
#include "PhysicsObject.h"
#include "BaseObject.h"
#include "Player.h"
class Enemy :
	public PhysicsObject
{
	//int health;
public:

	//void setHealth(int health);
	//int getHealth();
	void onInitFromFile(fstream& fs);
	void setDirectionFollowPlayer();
	/*virtual void onDeath();
	virtual void onDecreaseHealth();*/
	void onCollision(MovableRect* other, int nx, int ny, float collisionTime);
	//void onIntersect(MovableRect* other) override;
	//void resetLocation() override;
	//virtual void onContactPlayer();
	//virtual void onContactWeapon();
	//virtual bool canAttackPlayer();
	Enemy();
	~Enemy();
};

