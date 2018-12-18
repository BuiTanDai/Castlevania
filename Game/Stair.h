#pragma once
#include"BaseObject.h"
#include"Player.h"
#include"KEY.h"
class Stair : public BaseObject
{
public:
	void onIntersect(MovableRect* other) override;
	Stair();
	~Stair();
};

