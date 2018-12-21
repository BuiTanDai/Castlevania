#pragma once
#include "SpaceManager.h"

SpaceManager* SpaceManager::instance = 0;

SpaceManager* SpaceManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SpaceManager();
	}
	return instance;
}

void SpaceManager::setCurrentSpace(int space)
{
	this->currentSpace = listSpace.at(space);
	Camera::getInstance()->setSpace(currentSpace);
	ResetLocation();
}

Space* SpaceManager::getCurrentSpace()
{
	return currentSpace;
}

void SpaceManager::ResetLocation()
{
	Camera::getInstance()->setLocation(getCurrentSpace()->cameraX, getCurrentSpace()->cameraY);
	Player::getInstance()->setLocation(getCurrentSpace()->playerX, getCurrentSpace()->playerY);
}

SpaceManager::SpaceManager()
{
	int numberOfSpaces = 0;
	ifstream fsSpace("assets/levels/level1/spaces.dat");
	/* enter 1 dòng */
	ignoreLineIfstream(fsSpace, 1);
	fsSpace >> numberOfSpaces;
	for (size_t i = 0; i < numberOfSpaces; i++)
	{
		ignoreLineIfstream(fsSpace, 4);
		Space* space = new Space();
		fsSpace >> space->X >> space->Y >> space->Width >> space->Height;

		ignoreLineIfstream(fsSpace, 2);
		fsSpace >> space->cameraX >> space->cameraY;

		ignoreLineIfstream(fsSpace, 2);
		fsSpace >> space->playerX >> space->playerY;

		listSpace._Add(space);
	}
	setCurrentSpace(0);
}


SpaceManager::~SpaceManager()
{
}
