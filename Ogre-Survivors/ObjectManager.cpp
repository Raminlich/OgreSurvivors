#include "ObjectManager.h"

ObjectManager::ObjectManager(Ogre::Root* root, std::vector<GameObject*> objectList)
{
	for (auto& item : objectList)
	{
		root->addFrameListener(item);
	}
}
