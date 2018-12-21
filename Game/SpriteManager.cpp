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
	sprites[SPRITE_INFO_ITEM_HEART]->InitFromFile("assets/sprites/Item/item_heart.png", "assets/sprites/Item/item_heart.info.dat");
	//sprites[SPRITE_INFO_EXPLOSION_EFFECT]->InitFromFile("assets/sprites/candle/1/image.png", "assets/sprites/candle/1/explosion.info.dat");
	sprites[SPRITE_INFO_MERMAN]->InitFromFile("assets/sprites/Enemies/merman/image.png", "assets/sprites/Enemies/merman/merman.info.dat");
	sprites[SPRITE_INFO_MERMAN]->image->direction = TEXTURE_DIRECTION_LEFT;
	sprites[SPRITE_INFO_EXPLOSION_EFFECT]->InitFromFile("assets/sprites/effect/image.png", "assets/sprites/effect/explosion.info.dat");
	//sprites[SPRITE_INFO_ITEM_UPGRADE]->InitFromFile("assets/sprites/candle/image.png", "assets/sprites/candle/candle.info.dat");
	sprites[SPRITE_INFO_ITEM_UPGRADE]->InitFromFile("assets/sprites/Item/item_upgrade/image.png", "assets/sprites/Item/item_upgrade/item_upgrade.info.dat");
	sprites[SPRITE_INFO_WATER_EFFECT]->InitFromFile("assets/sprites/water/image.png", "assets/sprites/water/water.info.dat");
	sprites[SPRITE_INFO_ITEMS_IN_SCORE_BAR]->InitFromFile("assets/sprites/misc/items.png", "assets/sprites/misc/items.info.dat");
	//sprites[SPRITE_INFO_ITEMS_IN_SCORE_BAR]->InitFromFile("assets/sprites/water/image.png", "assets/sprites/water/water.info.dat");
	sprites[SPRITE_INFO_KNIFE]->InitFromFile("assets/sprites/knife/image.png", "assets/sprites/knife/knife.info.dat");
	sprites[SPRITE_INFO_BULLET]->InitFromFile("assets/sprites/bullet/image.png", "assets/sprites/bullet/bullet.info.dat");

}
SpriteManager::~SpriteManager()
{
}
