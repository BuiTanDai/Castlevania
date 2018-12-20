#include "Water.h"
#include "WaterEffect.h"





void Water::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	/*if (other->getCollisionType() == COLLISION_TYPE_ENEMY)
	{*/
	WaterEffect* water = new WaterEffect();
	water->setX(other->getX());
	water->setY(other->getY() + 15);
	water->setVy(-150);
	water->setVx(-40);


	water = new WaterEffect();
	water->setX(other->getX());
	water->setY(other->getY() + 15);
	water->setVy(-150);
	water->setVx(0);

	water = new WaterEffect();
	water->setX(other->getX());
	water->setY(other->getY() + 15);
	water->setVy(-150);
	water->setVx(40);

	/*}*/
	/*water->setVy(getGlobalValue("water_vy"));
	water->setVx(-getGlobalValue("water_vx"));*/

	/*water = new Water();
	water->setX(other->getX());
	water->setY(other->getY());*/
	/*water->setVy(getGlobalValue("water_vy"));
	water->setVx(0);*/

	/*water = new Water();
	water->setX(other->getX());
	water->setY(other->getY());*/
	/*water->setVy(getGlobalValue("water_vy"));
	water->setVx(getGlobalValue("water_vx"))*/
}

Water::Water()
{
	//setCollisionType(COLLISION_TYPE_WATER);
}


Water::~Water()
{
}
