#pragma once
#include "PhysicsObject.h"

enum ITEM_STATE
{
	ITEM_STATE_INVISIBLE,
	ITEM_STATE_VISIBLE,
};

class Item :
	public PhysicsObject
{
	ITEM_STATE item_state;
public:
	void onIntersect(MovableRect* other) override;
	void setState(ITEM_STATE item_state);
	ITEM_STATE getState();
	void update(float dt) override;
	Item();
	~Item();
};

