#pragma once
#include "Enemy.h"

enum PANTHER_STATE
{
	PANTHER_STATE_STAND,
	PANTHER_STATE_JUMP,
	PANTHER_STATE_RUN
};

enum PANTHER_ACTION
{
	PANTHER_ACTION_STAND,
	PANTHER_ACTION_JUMP,
	PANTHER_ACTION_RUN
};

class Panther :
	public Enemy

{
	PANTHER_STATE pantherState;
public:
	void setPantherState(PANTHER_STATE pantherState);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void update(float dt);
	Panther();
	~Panther();
};

