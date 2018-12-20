#pragma once
#include "PhysicsObject.h"
#include"SpriteManager.h"
#include"KEY.h"
#include"MorningStar.h"

enum PLAYER_STATE
{
	PLAYER_STATE_NORMAL,
	PLAYER_STATE_ON_STAIR,
	PLAYER_STATE_UPGRADE
};

enum PLAYER_ACTION
{
	PLAYER_START,
	PLAYER_INJURED,
	PLAYER_DIE,
	PLAYER_STAND,
	PLAYER_RUN,
	PLAYER_JUMP,
	PLAYER_ATTACK,
	PLAYER_SIT_ATTACK,
	PLAYER_UPSTAIR,
	PLAYET_STAND_STAIR_UP,
	PLAYER_DOWNSTAIR,
	PLAYER_UPSTAIR_ATTACK,
	PLAYER_DOWNSTAIR_ATTACK,
	PLAYER_UPGRADE
};

class Player :
	public PhysicsObject
{
	static Player* instance;
	bool isOnStair;
	bool isMoveUp;
	bool isMovingStair;
	PLAYER_STATE player_state;
public:
	static Player* getInstance();
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void usingMorningStar();
	bool getIsOnStair();
	void setIsOnStair(bool isOnStair);
	void setPlayerState(PLAYER_STATE player_state);
	PLAYER_STATE getPlayerState();
	void setIsMoveUp(bool moveup);
	bool getIsMoveUp();
	void setIsMovingStair(bool isMovingStair);
	bool getIsMovingStair();
	Player();
	~Player();
};

