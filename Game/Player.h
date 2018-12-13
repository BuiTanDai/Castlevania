#pragma once
#include "PhysicsObject.h"
#include"SpriteManager.h"
#include"KEY.h"
#include"MorningStar.h"

enum PLAYER_ACTION
{
	/* animation đầu tiên */
	PLAYER_STAND,
	/* animation thứ 2 */
	PLAYER_RUN,
	/* animation thứ 3 */
	PLAYER_JUMP,
	PLAYER_ATTACK
};

class Player :
	public PhysicsObject
{
	static Player* instance;
public:
	static Player* getInstance();
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void usingMorningStar();
	Player();
	~Player();
};

