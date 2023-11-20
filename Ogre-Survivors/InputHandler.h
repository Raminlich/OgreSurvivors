#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include <iostream>

class InputHandler : public OgreBites::InputListener
{
public:
	bool keyPressed(const OgreBites::KeyboardEvent& keyEvent);
};

