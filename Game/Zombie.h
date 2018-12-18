﻿#pragma once
#include"PhysicsObject.h"]
#include"Enemy.h"
/* lớp Zombie để hiện thực lớp PhysicsObject */


//enum ZOMBIE_STATE
//{
//	ZOMBIE_STATE_INVISIBLE,
//	ZOMBIE_STATE_VISIBLE
//};


class Zombie :
	public Enemy
{
	/*ZOMBIE_STATE zombieState;*/
public:
	/*void setZombieState(ZOMBIE_STATE zombieState);*/
	void onInitFormFile(fstream& fs);
	//void setDx(float dx) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void update(float dt);
	Zombie();
	~Zombie();
};
