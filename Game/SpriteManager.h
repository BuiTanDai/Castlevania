﻿#pragma once

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

	SPRITE_INFO_BAT = 8,

	SPRITE_INFO_BOSS = 9,

	SPRITE_INFO_EXPLOSION_EFFECT = 10,

	SPRITE_INFO_MORNINGSTAR = 11,
	SPRITE_INFO_WATER_EFFECT = 12,
	SPRITE_INFO_ITEMS_IN_SCORE_BAR = 13,
	SPRITE_INFO_KNIFE = 14,
	SPRITE_INFO_BULLET =15,

	SPRITE_COUNT
};

enum MISC_SPRITE_ID
{
	MISC_SPRITE_ID_NUMBER,
	MISC_SPRITE_ID_MORNING_STAR,
	MISC_SPRITE_ID_LOST_HEALTH,
	MISC_SPRITE_ID_KNIFE_ITEM,
	//MISC_SPRITE_ID_TORCH,
	//MISC_SPRITE_ID_EXPLOSION_EFFECT,
	//MISC_SPRITE_ID_CANDLE,
	//MISC_SPRITE_ID_MERMAN_BULLET,
	//MISC_SPRITE_ID_ITEM_MORNING_STAR,
	//MISC_SPRITE_ID_ITEM_SMALLHEART,
	//MISC_SPRITE_ID_ITEM_WATER,
	//MISC_SPRITE_ID_ITEM_BIGHEART,
	//MISC_SPRITE_ID_ITEM_DAGGER,
	MISC_SPRITE_ID_ITEM_HOLYWATER,
	MISC_SPRITE_ID_ITEM_HOLYCROSS,
	MISC_SPRITE_ID_ITEM_AXE,
	MISC_SPRITE_ID_ITEM_GOLDPOTION,
	MISC_SPRITE_ID_ITEM_STOPWATCH,
	//MISC_SPRITE_ID_ITEM_BREAK_WALL1,
	//MISC_SPRITE_ID_ITEM_BREAK_WALL,
	MISC_SPRITE_ID_ITEM_400PTS,
	MISC_SPRITE_ID_ITEM_700PTS,
	MISC_SPRITE_ID_ITEM_1000PTS,
	MISC_SPRITE_ID_ITEM_BOOMERANG,
	MISC_SPRITE_ID_BOOMERANG,
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