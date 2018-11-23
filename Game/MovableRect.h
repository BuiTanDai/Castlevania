﻿#pragma once
#include "Rect.h"
/* đây là lớp Rect có thể di chuyển */
class MovableRect :
	public Rect
{
	/* độ dời di chuyển của đối tượng */
	float dx, dy;
public:
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

	MovableRect();
	~MovableRect();
};
