#pragma once
#include "Enemy.h"

enum BAT_STATE
{
	BAT_STATE_INVISIBLE,
	BAT_STATE_VISIBLE
};
enum BAT_ACTION
{
	BAT_ACTION_FLY
};

class Bat :
	public Enemy
{
	BAT_STATE batState;
	int alpha;

public:
	void setBatState(BAT_STATE batState);
	void update(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Bat();
	~Bat();
};

