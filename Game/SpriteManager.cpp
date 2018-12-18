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
	sprites[SPRITE_INFO_FIRE]->InitFromFile("assets/sprites/fire/image.png", "assets/sprites/fire/fire.info.dat");
	sprites[SPRITE_INFO_CANDLE]->InitFromFile("assets/sprites/candle/image.png", "assets/sprites/candle/candle.info.dat");
	sprites[SPRITE_INFO_MORNINGSTAR]->InitFromFile("assets/sprites/weapon/image.png", "assets/sprites/weapon/weapon.info.dat");
	sprites[SPRITE_INFO_PANTHER]->InitFromFile("assets/sprites/Enemies/panther/image.png", "assets/sprites/Enemies/panther/panther.info.dat");
	sprites[SPRITE_INFO_PANTHER]->image->direction = TEXTURE_DIRECTION_LEFT;

}
SpriteManager::~SpriteManager()
{
}
