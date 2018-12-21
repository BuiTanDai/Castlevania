#pragma once
#include "Enemy.h"

enum BOSS_STATE
{
	BOSS_STATE_INVISIBLE,
	BOSS_STATE_WAIT,
	//BOSS_STATE_FAST,
	//BOSS_STATE_SLOW
};

enum BOSS_ACTION
{
	BOSS_ACTION_WAIT,
	BOSS_ACTION_FLY
};
class Boss :
	public Enemy

{

	BOSS_STATE bossState;
	int alpha;
public:
	
	void setBossState(BOSS_STATE bossState);
	void update(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Boss();
	~Boss();
};

