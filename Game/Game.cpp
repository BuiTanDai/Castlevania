#include "Game.h"


/* singleton pattern */
Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

/* Các câu lệnh khởi tạo game */
void Game::GameInit()
{
	sprite.InitFromFile("test/tool/image.png", "test/tool/simon.info.dat");
	currentIndex = 0;
	currentAnimation =1;
	/* khởi tạo thời gian làm chậm cỡ 1s (100 ms)*/
	timeDelay.init(100);
}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate()
{
	/* Set ràng buộc */
	if (timeDelay.atTime())
	{
		sprite.update(currentAnimation, currentIndex);
	}
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ hình tại vị trí khung hình hiện tại currentIndex tùy vào frame*/
	sprite.render(10, 10, currentAnimation, currentIndex);
}

Game::Game()
{
}


Game::~Game()
{
}
