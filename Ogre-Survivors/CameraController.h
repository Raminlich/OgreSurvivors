#pragma once

#include "Ogre.h"
#include "InputManager.h"

class CameraController : public Ogre::FrameListener
{
private:
	InputManager* m_InputManager;
	Ogre::Camera* m_Camera;
	Ogre::SceneNode* m_SceneNode;
public:
	CameraController(Ogre::Camera* camera, Ogre::SceneNode* sceneNode,InputManager* inputManager);
	~CameraController(){};

	bool frameStarted(const Ogre::FrameEvent& evt) override;
};
