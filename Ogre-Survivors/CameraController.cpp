#include"CameraController.h"

static float moveSpeed = 2;

CameraController::CameraController(Ogre::Camera* camera, Ogre::SceneNode* sceneNode, InputManager* inputManager)
	: m_Camera(camera), m_SceneNode(sceneNode),m_InputManager(inputManager)
{
}

bool CameraController::frameStarted(const Ogre::FrameEvent& evt) 
{
	Ogre::Vector3 nodePosition = m_SceneNode->getPosition();
	Ogre::Vector2 moveInput = m_InputManager->GetMoveInput();
	Ogre::Vector2 speedVector = moveInput * moveSpeed;
	m_SceneNode->setPosition(nodePosition.x + speedVector.x ,nodePosition.y,nodePosition.z + speedVector.y);
	/*m_SceneNode->lookAt(Ogre::Vector3(0, 0, 0),Ogre::Node::TransformSpace::TS_WORLD);*/

	return true;
}

