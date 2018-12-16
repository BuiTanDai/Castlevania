#include "SpaceManager.h"


SpaceManager* SpaceManager::instance = 0;

SpaceManager * SpaceManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SpaceManager();
	}
	return instance;
}

void SpaceManager::Init(const char * spacePath)
{
	/* đọc space */
	int numberOfSpaces = 0;
	ifstream fsSpace(spacePath);
	/* enter 1 dòng */
	ignoreLineIfstream(fsSpace, 1);
	fsSpace >> numberOfSpaces;
	for (size_t i = 0; i < numberOfSpaces; i++)
	{
		/* enter 4 dòng */
		ignoreLineIfstream(fsSpace, 4);
		Space* space = new Space();
		fsSpace >> space->X >> space->Y >> space->Width >> space->Height;

		/* enter 2 dòng */
		ignoreLineIfstream(fsSpace, 2);
		fsSpace >> space->CameraX >> space->CameraY;

		/* enter 2 dòng */
		ignoreLineIfstream(fsSpace, 2);
		fsSpace >> space->PlayerX >> space->PlayerY;

		/* thêm vào space */
		spaceManager._Add(space);
	}
}

SpaceManager::SpaceManager()
{
}


SpaceManager::~SpaceManager()
{
}
