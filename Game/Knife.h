#pragma once
#include "AdditionalObject.h"

class Knife :
	public AdditionalObject
{
	static Knife* instance;
public:
	static Knife* getInstance();
	void update(float dt) override;
	void onIntersect(MovableRect* other) override;
	Knife();
	~Knife();
};

