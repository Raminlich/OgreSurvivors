#pragma once
#include "Ogre.h"
#include "GameObject.h"
#include <vector>

class ObjectManager
{
	ObjectManager(Ogre::Root* root, std::vector<GameObject*> objectList);
	~ObjectManager(){}

};

