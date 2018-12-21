#pragma once
#include "Item.h"
#include "ScoreBar.h"
#include "AdditionalObject.h"
class ItemHeart :
	public Item
{
public:
	void onIntersect(MovableRect* other) override;
	//void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	ItemHeart();
	~ItemHeart();
};

