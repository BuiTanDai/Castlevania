#pragma once
#include"GameTexture.h"
#include"List.h"
#include"GameTime.h"
#include"FrameAnimation.h"
#include"Animation.h"
#include"Sprite.h"
#include"Tilemap.h"

class Game
{
	/* singleton pattern */
	static Game* instance;

	Tilemap* tilemap;

public:
	static Game* getInstance();

	/* Các câu lệnh khởi tạo game */
	void GameInit();
	/* Các câu lệnh cập nhật game */
	void GameUpdate();
	/* Các câu lệnh vẽ của game */
	void GameRender();
	Game();
	~Game();
};

