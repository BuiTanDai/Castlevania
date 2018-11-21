#pragma once

#include"GameTexture.h"
/* include để sử dụng kiểu danh sách */
#include"List.h"
#include"GameTime.h"
#include"FrameAnimation.h"
#include"Animation.h"
#include"Sprite.h"

class Game
{
	/* singleton pattern */
	static Game* instance;

	/* Khung hình hiện tại */
	int currentIndex;

	/*animation hiện tại*/
	int currentAnimation;

	Sprite sprite;

	/* dùng để làm chậm animation */
	GameTime timeDelay;

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