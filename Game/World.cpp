#include "World.h"
#include"Camera.h"
#include"Player.h"
#include"Zombie.h"
#include"KEY.h"
#include"Collision.h"
#include"Fire.h"
#include"Candle.h"
#include"MorningStar.h"
#include"Gate1.h"
#include"Stair.h"
#include"Panther.h"
#include"EndStair.h"
#include"ItemHeart.h"
#include"Item.h"
#include"AdditionalObject.h"
#include"Aquaman.h"
#include"ItemUpgrade.h"
#include"Water.h"
#include"Bat.h"
#include"Boss.h"

void World::Init(const char * tilesheetPath, 
	const char * matrixPath, 
	const char * objectsPath,
	const char * collisionTypeCollidePath,
	const char * spacePath)
{
	/* khởi tạo vị trí player */
	Player::getInstance()->set(0, 0, 15, 30);
	

	/* khởi tạo tilemap */
	tilemap.Init(tilesheetPath, matrixPath);

	/* khởi tạo phân loại đối tượng */
	for (size_t i = 0; i < COLLISION_TYPE_COUNT; i++)
	{
		objectCategories._Add(new List<BaseObject*>());
	}


	/* khởi tạo đối tượng */
	int objectCount;
	ifstream fs(objectsPath);
	fs >> objectCount;
	for (size_t i = 0; i < objectCount; i++)
	{
		BaseObject* obj;
		int id;
		/* đọc id đối tượng */
		fs >> id;
		switch (id)
		{

		case SPRITE_INFO_ZOMBIE:
			obj = new Zombie();
			break;

		case SPRITE_INFO_FIRE:
			obj = new Fire();
			break;
		case SPRITE_INFO_CANDLE:
			obj = new Candle();
			break;
		case SPRITE_INFO_PANTHER:
			obj = new Panther();
			break;
		case SPRITE_INFO_ITEM_HEART:
			obj = new ItemHeart();
			break;
		case SPRITE_INFO_MERMAN:
			obj = new Aquaman();
			break;
		case SPRITE_INFO_ITEM_UPGRADE:
			obj = new ItemUpgrade();
			break;
		case SPRITE_INFO_BAT:
			obj = new Bat();
			break;
		case SPRITE_INFO_BOSS:
			obj = new Boss();
			break;

		case -2:
			obj = new Gate1();
			break;

		case -3:
			obj = new Stair();
			break;
		case -4:
			obj = new EndStair();
			break;
		case -5:
			obj = new Water();
			break;
		default:
			obj = new BaseObject();
			break;
		}
		/* đọc thông số của đối tượng */
		obj->onInitFromFile(fs);
		if (id >= 0)
		{
			/* nếu id đối tượng không âm tức đối tượng có sprite ta gán sprite cho nó */
			obj->setSprite(SPR(id));
		}
		/* thêm đối tượng vào danh sách */
		allObjects._Add(obj);

		/* thêm object vào từng loại đối tượng */
		objectCategories.at(obj->getCollisionType())->_Add(obj);
	}

	/* đọc collisiontype collide */
	int numberOfCollisionTypeCollides = 0;
	ifstream fsColli(collisionTypeCollidePath);
	fsColli >> numberOfCollisionTypeCollides;
	for (size_t i = 0; i < numberOfCollisionTypeCollides; i++)
	{
		int collisionType1, collisionType2;
		fsColli >> collisionType1 >> collisionType2;
		CollisionTypeCollide* collisionTypeCollide = new CollisionTypeCollide();
		collisionTypeCollide->COLLISION_TYPE_1 = (COLLISION_TYPE)collisionType1;
		collisionTypeCollide->COLLISION_TYPE_2 = (COLLISION_TYPE)collisionType2;
		collisionTypeCollides._Add(collisionTypeCollide);
	}

	/* đọc space */
	int numberOfSpaces = 0;
	ifstream fsSpace(spacePath);
	/* enter 1 dòng */
	ignoreLineIfstream(fsSpace, 1);
	fsSpace >> numberOfSpaces;
	for (size_t i = 0; i < numberOfSpaces; i++)
	{
		/* enter 4 dòng */
		ignoreLineIfstream(fsSpace, 4);
		Space* space = new Space();
		fsSpace >> space->X >> space->Y >> space->Width >> space->Height;

		/* enter 2 dòng */
		ignoreLineIfstream(fsSpace, 2);
		fsSpace >> space->CameraX >> space->CameraY;

		/* enter 2 dòng */
		ignoreLineIfstream(fsSpace, 2);
		fsSpace >> space->PlayerX >> space->PlayerY;

		/* thêm vào space */
		spaces._Add(space);
	}

	/* bắt đầu từ space 0 */
	setCurrentSpace(1);
	resetLocationInSpace();
}

void World::Init(const char * folderPath)
{
	/* tìm đường dẫn tilesheet và matrix object */
	string folderPathString = (string)folderPath;
	string tilesheetString = folderPathString;
	tilesheetString.append("/tilesheet.png");

	string matrixPathString = folderPathString;
	matrixPathString.append("/matrix.dat");

	string objectPathString = folderPathString;
	objectPathString.append("/objects.dat");

	string collisionTypeCollidePath = folderPathString;
	collisionTypeCollidePath.append("/collision_type_collides.dat");

	string spacePath = folderPathString;
	spacePath.append("/spaces.dat");

	Init(tilesheetString.c_str(), 
		matrixPathString.c_str(), 
		objectPathString.c_str(),
		collisionTypeCollidePath.c_str(),
		spacePath.c_str()
	);
}

void World::update(float dt)
{
	KEY* key = KEY::getInstance();
	/* cập nhật key */
	key->update();

	/* chuyển space khi nhấn phím */
	if (key->isNumber1Down)
	{
		setCurrentSpace(0);
		resetLocationInSpace();
	}
	if (key->isNumber2Down)
	{
		setCurrentSpace(1);
		resetLocationInSpace();
	}
	if (key->isNumber3Down)
	{
		setCurrentSpace(2);
		resetLocationInSpace();
	}
	if (key->isNumber4Down)
	{
		setCurrentSpace(3);
		resetLocationInSpace();
	}
	if (key->isNumber5Down)
	{
		setCurrentSpace(4);
		resetLocationInSpace();
	}

	for (size_t i = 0; i < allObjects.Count; i++)
	{
		/* cập nhật đối tượng */
		allObjects[i]->update(dt);
		if (allObjects[i]->getAlive())
		{
			Collision::CheckCollision(Player::getInstance(), allObjects[i]);
			Collision::CheckCollision(allObjects[i], Player::getInstance());
		}
		
	}

	if (MorningStar::getInstance()->getAlive()) {
		for (size_t i = 0; i < allObjects.Count; i++)
		{
			/* cập nhật đối tượng */
			if (allObjects[i]->getAlive())
			{
				Collision::CheckCollision(MorningStar::getInstance(), allObjects[i]);
			}
		}
	}

	/* xét va chạm cho các loại đối tượng với nhau */
	for (size_t i = 0; i < collisionTypeCollides.size(); i++)
	{
		COLLISION_TYPE col1 = collisionTypeCollides.at(i)->COLLISION_TYPE_1;
		COLLISION_TYPE col2 = collisionTypeCollides.at(i)->COLLISION_TYPE_2;

		/* danh sách đối tượng thuộc collision type 1 */
		List<BaseObject*>* collection1 = objectCategories.at(col1);
		/* danh sách đối tượng thuộc collision type 2 */
		List<BaseObject*>* collection2 = objectCategories.at(col2);

		for (size_t i1 = 0; i1 < collection1->size(); i1++)
		{
			for (size_t i2 = 0; i2 < collection2->size(); i2++)
			{
				/* cho xét va chạm của đối tượng dựa vào 1 cặp collisionType trong CollisionTypeCollide */
				Collision::CheckCollision(collection1->at(i1), collection2->at(i2));
			}
		}

	}

	Player::getInstance()->update(dt);
	Camera::getInstance()->update();
	if (MorningStar::getInstance()->getAlive())
		MorningStar::getInstance()->update(dt);
	AdditionalObject::listObjectUpdate(dt);
}

void World::render()
{
	tilemap.render(Camera::getInstance());
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		/* vẽ đối tượng */
		allObjects[i]->render(Camera::getInstance());
	}
	Player::getInstance()->render(Camera::getInstance());
	if (MorningStar::getInstance()->getAlive())
		MorningStar::getInstance()->render(Camera::getInstance());
	AdditionalObject::listObjectRender(Camera::getInstance());
}

void World::setCurrentSpace(int spaceIndex)
{
	this->currentSpace = spaces.at(spaceIndex);
	Camera::getInstance()->setSpace(this->currentSpace);
}

Space * World::getCurrentSpace()
{
	return currentSpace;
}

void World::resetLocationInSpace()
{
	Camera* camera = Camera::getInstance();
	Player* player = Player::getInstance();

	camera->setLocation(getCurrentSpace()->CameraX, getCurrentSpace()->CameraY);
	player->setLocation(getCurrentSpace()->PlayerX, getCurrentSpace()->PlayerY);
	
}

World::World()
{
}
World::~World()
{
}
