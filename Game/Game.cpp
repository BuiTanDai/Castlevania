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
	/* khởi tạo danh sách vị trí khung hình */

	/* Thêm khung hình 1 vào list */
	FrameAnimation* r1 = new FrameAnimation();
	SetRect(r1, 1, 6, 1 + 21, 6 + 28);
	r1->anchorX = 8;
	r1->anchorY = 0;
	rectAnimations._Add(r1);

	/* Thêm khung hình 2 vào list */
	FrameAnimation* r2 = new FrameAnimation();
	SetRect(r2, 27, 6, 27 + 16, 6 + 28);
	r2->anchorX = 4;
	r2->anchorY = 0;
	rectAnimations._Add(r2);

	/* Thêm khung hình 3 vào list */
	FrameAnimation* r3 = new FrameAnimation();
	SetRect(r3, 46, 6, 46 + 23, 6 + 28);
	r3->anchorX = 4;
	r3->anchorY = 0;
	rectAnimations._Add(r3);

	/* cho khung hình hiện tại là 0 */
	currentIndex = 0;

	/* đường dẫn hình là test/helichomer.png màu cần ẩn có r=109 g = 167 b= 131 */
	mario.Init("test/mario.png", D3DCOLOR_XRGB(255, 255, 255));

	/* khởi tạo thời gian làm chậm cỡ 1s (100 ms)*/
	timeDelay.init(100);
}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate()
{
	/* Animation có 3 khung hình tức khung hình hiện tại chỉ có thể là khung hình 0, 1 hoặc 2
		Nếu là 0 thì vẽ hình tại vị trí r1
		Nếu là 1 thì vẽ hình tại vị trí r2
		Nếu là 2 thì vẽ hình tại vị trí r3
	*/
	/* Set ràng buộc */
	if (timeDelay.atTime())
	{
		currentIndex++;
		if (currentIndex > 2)
		{
			currentIndex = 0;
		}
	}
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ hình tại vị trí khung hình hiện tại currentIndex tùy vào frame*/
	auto frame = rectAnimations.at(currentIndex);
	mario.Render(10, 10, frame->anchorX, frame->anchorY, frame);
}

Game::Game()
{
}


Game::~Game()
{
}
