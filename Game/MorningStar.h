#pragma once
#include "BaseObject.h"
#include "Camera.h"
#include"ExplosionEffect.h"

enum MORNINGSTAR_TYPE
{
	MORNINGSTAR_TYPE_1,
	MORNINGSTAR_TYPE_2,
	MORNINGSTAR_TYPE_3,
	/*MORNINGSTAR_TYPE_4,
	MORNINGSTAR_TYPE_5,*/
	MORNINGSTAR_TYPE_COUNT
};

struct RopeLocation
{
	int x, y;
};

class MorningStar :
	public BaseObject
{
	static MorningStar* instance;
	MORNINGSTAR_TYPE currentMorningStarType;
public:
	static MorningStar* getInstance();
	void setType(MORNINGSTAR_TYPE morningStarType);
	void increaseType();
	MORNINGSTAR_TYPE getType();
	RopeLocation location[3];
	void update(float dt) override;
	void render(Camera* camera) override;
	void onIntersect(MovableRect* other) override;
	void OnCollision();
	MorningStar();
	~MorningStar();
};


