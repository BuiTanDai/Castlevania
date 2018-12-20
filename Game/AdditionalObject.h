#pragma once
#include "BaseObject.h"
#include "Camera.h"
class AdditionalObject :
	public BaseObject
{
	static List<AdditionalObject*>* listObject;
public:
	static List<AdditionalObject*>* getListObject();
	static void listObjectUpdate(float dt);
	static void listObjectRender(Camera* camera);
	AdditionalObject();
	~AdditionalObject();
};

