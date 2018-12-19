#pragma once
#include "BaseObject.h"
class ExplosionEffect :
	public BaseObject
{
public:
	void update(float dt) override;
	ExplosionEffect();
	~ExplosionEffect();
};

