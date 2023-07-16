#include "GameObject.h"
using namespace Ogre;
using namespace std;

GameObject::GameObject(Ogre::SceneManager* sceneManager, Ogre::String name)
{
}

bool GameObject::frameStarted(const Ogre::FrameEvent& event)
{
	return true;
}

void GameObject::initObjectState()
{
	cout << "Object init state" << endl;
}

void GameObject::updateObjectState()
{
}
