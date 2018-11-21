#include<Windows.h>
#include"WindowGame.h"
#include"GameDirectX.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

#include"GameTexture.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WindowGame::getInstance()->initHandleWindows(hInstance, nCmdShow);
	srand(time(NULL));

	/* GetTickCount: lấy thời gian hiện tại của hệ thống */
	/* Tính thời gian bắt đầu */
	DWORD startTime = GetTickCount();

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	/* Tính thời gian cho mỗi frame */
	DWORD timePerFrame = 1000 / GLOBALS_D("fps");

	/* b1. Tạo biến imageGame và khởi tạo hình */
	GameTexture imageGame;
	imageGame.Init("test/image_game.png", D3DCOLOR_ARGB(255, 0, 28, 255));

	/* vòng lặp game */
	while (msg.message != WM_QUIT)
	{
		/* now là thời gian hiện tại */
		DWORD now = GetTickCount();
		/* nếu khoảng thời gian kể từ lúc bắt đầu tới bây giờ lớn hơn thời gian cho mỗi frame thì khởi tạo lại thời gian bắt đầu
		là bây giờ*/
		DWORD deltaTime = now - startTime;
		if (deltaTime >= timePerFrame)
		{
			startTime = now;
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			float time = deltaTime / 1000.0f;
			GameDirectX::getInstance()->BeginGraphics();//bat dau ve len backbuffer
			/* b1. Vẽ hình lên vị trí 10,10 */
			/* Thêm biến rect */
			RECT viewRect;
			SetRect(&viewRect, 31, 2, 109, 86);
			imageGame.Render(10, 10, &viewRect);
			GameDirectX::getInstance()->EndGraphics();// ket thuc ve len backbuffer
			GameDirectX::getInstance()->PresentBackBuffer();// ve backbuffer len man hinh
		}

	}
	return nCmdShow;
}
