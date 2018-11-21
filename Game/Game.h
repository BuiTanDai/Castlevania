#pragma once
#include "GameTexture.h"
class Game
{
	/* singleton pattern */
	static Game* instance;
public:
	static Game* getInstance();

	GameTexture image;
	/*vị trí bức hình*/
	int x, y;

	/* Các câu lệnh khởi tạo game */
	void GameInit();
	/* Các câu lệnh cập nhật game */
	void GameUpdate();
	/* Các câu lệnh vẽ của game */
	void GameRender();
	Game();
	~Game();
};
