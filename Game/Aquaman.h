#pragma once
#include "Enemy.h"

enum MERMAN_STATE
{
	MERMAN_STATE_INVISIBLE,
	MERMAN_STATE_JUMP,
	MERMAN_STATE_RUN,
	MERMAN_STATE_ATTACK
};
enum MERMAN_ACTION
{
	MERMAN_ACTION_JUMP,
	MERMAN_ACTION_RUN,
	MERMAN_ACTION_SHOOT
};


class Aquaman :
	public Enemy
{

	MERMAN_STATE mermanState;
	//MERMAN_ACTION mermanAction;

	/*DelayTime runDelay;
	DelayTime attackDelay;*/
public:

	void update(float dt);
	void setMermanState(MERMAN_STATE mermanState);
	//MERMAN_STATE getMermanState();
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny);
	Aquaman();
	~Aquaman();
};

