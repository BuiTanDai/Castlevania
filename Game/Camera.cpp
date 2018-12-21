#include "Camera.h"
#include"Player.h"
#include<d3dx9.h>

Camera * Camera::instance = 0;
Camera * Camera::getInstance()
{
	if (instance == 0)
	{
		instance = new Camera();
	}
	return instance;
}

void Camera::convertWorldToView(float xWorld, float yWorld, float & xView, float & yView)
{

	xView = xWorld - this->getX();
	yView = yWorld - this->getY();
}

void Camera::update()
{
	/* mặc định cho camera đứng yên, chỉ khi player chạy nó mới chạy theo */
	setDx(0);

	Player* player = Player::getInstance();
	/* nếu player đang chạy sang trái (player->getDx()<0) và phần giữa camera nằm bên phải phần giữa player */
	if (player->getDx() < 0 && getMidX() > player->getMidX())
	{
		/* thì cho camera chạy theo player (về bên trái) */
		setDx(player->getDx());
	}
	/* nếu player đang chạy sang phải (player->getDx()>0) và phần giữa camera nằm bên trái phần giữa player */
	if (player->getDx() > 0 && getMidX() < player->getMidX())
	{
		/* thì cho camera chạy theo player (về bên phải) */
		setDx(player->getDx());
	}

	//Thêm Space
	/* nếu camera chạy sang trái và vượt quá góc trái space  */
	if (getX() + getDx() < space->X && getDx() < 0)
	{
		setX(space->X);
		setDx(0);
	}

	/* nếu camera chạy sang phải và vượt quá góc phải space  */
	if (getRight() + getDx() > space->X + space->Width && getDx() > 0)
	{
		setX(space->X + space->Width - getWidth());
		setDx(0);
	}

	/* nếu player chạy sang trái và vượt quá góc trái space  */
	if (player->getX() + player->getDx() < space->X && player->getDx() < 0)
	{
		player->setX(space->X);
		player->setDx(0);
	}

	/* nếu player chạy sang phải và vượt quá góc phải space  */
	if (player->getRight() + player->getDx() > space->X + space->Width && player->getDx() > 0)
	{
		player->setX(space->X + space->Width - player->getWidth());
		player->setDx(0);
	}


	/* cập nhật vị trí camera */
	goX();
	goY();
}

void Camera::setSpace(Space * space)
{
	this->space = space;
}

Camera::Camera()
{
}


Camera::~Camera()
{
}
