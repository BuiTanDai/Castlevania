﻿#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
	setAx(0);
	/* set trọng lực mặc định của đối tượng lấy từ GameConfiguration.cpp */
	setAy(GLOBALS_D("object_default_ay"));
	setVx(0);
	setVy(0);
	/* bật physics cho đối tượng */
	setPhysicsEnable(true);
	isAttacking = false;
}

void PhysicsObject::onUpdate(float dt)
{
	if (getPhysicsEnable())
	{
		/* v = v0 + at công thức vật lý lớp 10 */
		setVx(getVx() + getAx()*dt);
		setVy(getVy() + getAy()*dt);
		/* x = x0 + vx*t = x0 + dx => dx = vx*t*/
		setDx(getVx()*dt);
		setDy(getVy()*dt);
	}
}

PhysicsObject::~PhysicsObject()
{
}

float PhysicsObject::getAx()
{
	return ax;
}

float PhysicsObject::getAy()
{
	return ay;
}

float PhysicsObject::getVx()
{
	return vx;
}

float PhysicsObject::getVy()
{
	return vy;
}

void PhysicsObject::setAx(float ax)
{
	this->ax = ax;
}

void PhysicsObject::setAy(float ay)
{
	this->ay = ay;
}

void PhysicsObject::setVx(float vx)
{
	this->vx = vx;
}

void PhysicsObject::setVy(float vy)
{
	this->vy = vy;
}

bool PhysicsObject::getPhysicsEnable()
{
	return physicsEnable;
}

void PhysicsObject::setPhysicsEnable(bool physicsEnable)
{
	this->physicsEnable = physicsEnable;
}

bool PhysicsObject::getIsOnGround()
{
	return isOnGround;
}

void PhysicsObject::setIsOnGround(bool isOnGround)
{
	this->isOnGround = isOnGround;
}

bool PhysicsObject::getIsAttacking()
{
	return isAttacking;
}

void PhysicsObject::setIsAttacking(bool attacking)
{
	isAttacking = attacking;
}

void PhysicsObject::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		if (ny == -1)
		{
			setIsOnGround(true);
			
		}
		if (ny !=0)
		{
			setVy(10);
		}
		preventMovementWhenCollision(collisionTime, nx, ny);
	}
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

