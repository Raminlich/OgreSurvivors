#pragma once
#include "OgreFrameListener.h"
#include "Ogre.h"
#include <iostream>

class GameObject : public Ogre::FrameListener
{
public:
    GameObject(Ogre::SceneManager* sceneManager , Ogre::String name);
    ~GameObject() {}
    bool frameStarted(const Ogre::FrameEvent& event);
    void initObjectState();
    void updateObjectState();
private:
    Ogre::String name;
    Ogre::SceneNode* node;
};

