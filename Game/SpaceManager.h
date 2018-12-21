#pragma once
#include "List.h"
#include"GameUtils.h"
#include"Player.h"
#include"Camera.h"
#include"Space.h"

class SpaceManager
{
	List<Space*> listSpace;
	static SpaceManager* instance;
	Space* currentSpace;
public:
	static SpaceManager* getInstance();
	void setCurrentSpace(int space);
	Space* getCurrentSpace();
	void ResetLocation();
	SpaceManager();
	~SpaceManager();
};

