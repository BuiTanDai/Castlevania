#include "SpriteManager.h"
SpriteManager * SpriteManager::instance = 0;
SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SpriteManager();
	}
	return instance;
}
Sprite * SpriteManager::getSprite(int spriteInfo)
{
	return getInstance()->sprites[spriteInfo];
}
SpriteManager::SpriteManager()
{
	/* thêm SPRITE_COUNT phần tử cho list sprite */
	for (size_t i = 0; i < SPRITE_COUNT; i++)
	{
		sprites._Add(new Sprite());
	}

	/* thêm sprite ở đây */

	/* thêm sprite cho zombie*/
	sprites[SPRITE_INFO_ZOMBIE]->InitFromFile("test/zombie/image.png", "test/zombie/zombie.info.dat");
	sprites[SPRITE_INFO_SIMON]->InitFromFile("assets/sprites/simon/image.png", "assets/sprites/simon/simon.info.dat");
	sprites[SPRITE_INFO_SIMON]->image->direction =TEXTURE_DIRECTION_RIGHT;
}
SpriteManager::~SpriteManager()
{
}
