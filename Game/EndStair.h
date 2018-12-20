#pragma once
#include "BaseObject.h"
#include"Player.h"
class EndStair :
	public BaseObject
{
public:
	void onIntersect(MovableRect* other) override;
	EndStair();
	~EndStair();
};

