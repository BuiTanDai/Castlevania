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
	/* khởi tạo tilemap */
	world = new World();
	world->Init("test/object");
	Camera::getInstance()->set(
		0,
		0, /* y camera */
		/* kích thước của camera bằng với kích thước của backbuffer */
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));
}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate(float dt)
{
	/* di chuyển camera theo phương x */
	Camera::getInstance()->goX();
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ tile lên game */
	tilemap->render(Camera::getInstance());
}

Game::Game()
{
}


Game::~Game()
{
}
