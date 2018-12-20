#pragma once
#include "Item.h"
#include"MorningStar.h"
class ItemUpgrade :
	public Item
{
public:
	void onIntersect(MovableRect* other) override;
	ItemUpgrade();
	~ItemUpgrade();
};

