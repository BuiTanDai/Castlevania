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
	image.Init("test/image_game.png");
	/*khởi tạo vị trí bức hình*/
	x = 10, y = 10;	
}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate()
{
	x++;
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	image.Render(x, y);
}

Game::Game()
{
}


Game::~Game()
{
}
