#pragma once

/* sử dụng list */
#include"List.h"
#include"Sprite.h"

/* khai báo 1 define viết tắt cho chữ SpriteManager::getSprite */
#define SPR SpriteManager::getSprite

/* ta tạo 1 sprite info để lưu thông tin của các sprite */
enum SPRITE_INFO
{
	SPRITE_INFO_WATER = -5,
	SPRITE_INFO_ENDSTAIR = -4,
	SPRITE_INFO_STAIR = -3,
	SPRITE_INFO_GATE1 = -2,
	/* đối tượng không có hình ảnh ta sẽ đặt số âm */
	SPRITE_INFO_GROUND = -1,
	/* đối tượng có hình ảnh ta sẽ đặt số dương */
	SPRITE_INFO_SIMON = 0,
	// thêm các sprite_info khác ở đây

	SPRITE_INFO_ZOMBIE = 1,

	SPRITE_INFO_FIRE = 2,

	SPRITE_INFO_CANDLE = 3,

	SPRITE_INFO_PANTHER = 4,

	SPRITE_INFO_ITEM_HEART = 5,

	SPRITE_INFO_MERMAN = 6,

	SPRITE_INFO_ITEM_UPGRADE = 7,


	SPRITE_INFO_EXPLOSION_EFFECT = 8,

	SPRITE_INFO_MORNINGSTAR = 9,
	SPRITE_INFO_WATER_EFFECT = 10,

	SPRITE_COUNT
};

class SpriteManager
{
	/* ta lưu tất cả sprite ở đây */
	List<Sprite*> sprites;

	/* singleton pattern */
	static SpriteManager* instance;
public:
	static SpriteManager* getInstance();

	/* dùng để lấy sprite từ spriteManager */
	static Sprite* getSprite(int spriteInfo);

	SpriteManager();
	~SpriteManager();
};