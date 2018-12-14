#include "KEY.h"

DWORD getKeyChar(char keyChar)
{
	return ((int)keyChar - 'a') + 0x41;
}

KEY * KEY::instance = 0;
KEY * KEY::getInstance()
{
	if (instance == 0)
		instance = new KEY();
	return instance;
}

void KEY::update()
{
	isUpDown = GetAsyncKeyState(VK_UP);
	isDownDown = GetAsyncKeyState(VK_DOWN);
	isLeftDown = GetAsyncKeyState(VK_LEFT);
	isRightDown = GetAsyncKeyState(VK_RIGHT);

	isJumpDown = GetAsyncKeyState(getKeyChar('x'));

	isAttackDown = GetAsyncKeyState(getKeyChar('z'));
	isAttackPress = isAttackDown && !isPreviousAttackDown;
	isPreviousAttackDown = isAttackDown;

	isNumber1Down = GetAsyncKeyState(VK_NUMPAD1);
	isNumber2Down = GetAsyncKeyState(VK_NUMPAD2);
	isNumber3Down = GetAsyncKeyState(VK_NUMPAD3);
	isNumber4Down = GetAsyncKeyState(VK_NUMPAD4);
	isNumber5Down = GetAsyncKeyState(VK_NUMPAD5);
}

KEY::KEY()
{
}


KEY::~KEY()
{
}
