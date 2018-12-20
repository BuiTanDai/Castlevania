#pragma once
#include"AdditionalObject.h"
class WaterEffect :
	public AdditionalObject
{
public:
	void update(float dt) override;
	WaterEffect();
	~WaterEffect();
};

