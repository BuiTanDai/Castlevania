#pragma once
#include"Space.h"
#include"List.h"
#include"GameUtils.h"
class SpaceManager
{
	static SpaceManager* instance;
	List<Space*> spaceManager;
	int currentSpace;
public:
	static SpaceManager* getInstance();
	void Init(const char* path);
	/* setCurrentSpace */
	void setCurrentSpace(int spaceIndex);
	Space* getCurrentSpace();
	void nextSpace(int currentSpace);
	void previousSpace(int currentSpace);
	SpaceManager();
	~SpaceManager();
};

