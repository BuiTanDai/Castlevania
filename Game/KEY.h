#pragma once
#include<Windows.h>
class KEY
{
public:
	bool
		isLeftDown,
		isRightDown,
		isUpDown,
		isDownDown,

		//true khi jump
		isJumpDown,
		isAttackDown,
		isAttackPress,
		isPreviousAttackDown,

		isNumber1Down,
		isNumber2Down,
		isNumber3Down,
		isNumber4Down,
		isNumber5Down;

	static KEY* instance;
	static KEY* getInstance();

	void update();

	KEY();
	~KEY();
};
