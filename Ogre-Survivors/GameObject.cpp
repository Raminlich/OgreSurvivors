#include "GameObject.h"
//#include "fmt/format.h"
using namespace Ogre;
using namespace std;


GameObject::GameObject(Ogre::SceneManager* sceneManager, Ogre::String name)
{
	this->name = name;
	Entity* entity = sceneManager->createEntity(this->name+".mesh");
	node = sceneManager->getRootSceneNode()->createChildSceneNode();
	node->attachObject(entity);
	initObjectState();
}

bool GameObject::frameStarted(const Ogre::FrameEvent& event)
{
	float speed = 0.01;
	Vector3 position = node->getPosition();
	node->setPosition(position.x + speed, position.y, position.z + speed);
	return true;
}

void GameObject::initObjectState()
{
	//cout << fmt::format("Object init state : {0}",this->name) << endl;
}

void GameObject::updateObjectState()
{
}
