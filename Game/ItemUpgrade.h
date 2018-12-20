#pragma once
#include "Item.h"
#include"MorningStar.h"
#include"Player.h"
class ItemUpgrade :
	public Item
{
public:
	void onIntersect(MovableRect* other) override;
	ItemUpgrade();
	~ItemUpgrade();
};

