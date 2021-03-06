﻿#pragma once
#include "Rect.h"
#include"CollisionType.h"

/* đây là lớp Rect có thể di chuyển */
class MovableRect :
	public Rect
{
	/* độ dời di chuyển của đối tượng */
	bool alive;
	bool isRender;
	float dx, dy;
	COLLISION_TYPE collisionType;
public:
	COLLISION_TYPE getCollisionType();
	void setCollisionType(COLLISION_TYPE collisionType);
	virtual void setDx(float dx);
	virtual void setDy(float dy);
	float getDx();
	float getDy();
	/* phương thức di chuyển */
	void goX();
	void goY();
	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny);

	/* phương thức xử lý va chạm chặn di chuyển khi phát hiện va chạm */
	void preventMovementWhenCollision(float collisionTime, int nx, int ny);
	virtual void onIntersect(MovableRect* other);

	bool getAlive();
	void setAlive(bool alive);

	bool getIsRender();
	void setIsRender(bool isRender);

	MovableRect();
	~MovableRect();
};
