#include "InputManager.h"
#include "fmt/core.h"

#pragma region InputManager

InputManager::InputManager()
{
	//Nothing to do here yet
}

void InputManager::CalculateMoveInput() 
{
	//Calculate m_MoveInput x
	if (m_RightInput->IsHold() && m_LeftInput->IsHold()) 
	{
		m_MoveInput.x = 0;
	}
	else if(m_RightInput->IsHold())
	{
		m_MoveInput.x = -1;
	}
	else if(m_LeftInput->IsHold())
	{
		m_MoveInput.x = 1;
	}
	else
	{
		m_MoveInput.x = 0;
	}

	//Calculate m_MoveInput y
	if (m_UpInput->IsHold() && m_DownInput->IsHold())
	{
		m_MoveInput.y = 0;
	}
	else if (m_UpInput->IsHold())
	{
		m_MoveInput.y = 1;
	}
	else if (m_DownInput->IsHold())
	{
		m_MoveInput.y = -1;
	}
	else
	{
		m_MoveInput.y = 0;
	}
}

const std::vector<Input*>& InputManager::GetInputs() const
{
	return m_Inputs;
}

bool InputManager::frameStarted(const Ogre::FrameEvent& evt)
{
	CalculateMoveInput();
	return true;
}

const Ogre::Vector2& InputManager::GetMoveInput() const
{
	return m_MoveInput;
}

InputManager::~InputManager()
{
	delete m_UpInput;
	delete m_DownInput;
	delete m_RightInput;
	delete m_LeftInput;
}

#pragma endregion


#pragma region Input

Input::Input(OgreBites::Keycode keyCode)
	:m_KeyCode(keyCode)

{
}

bool Input::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	if (evt.keysym.sym == m_KeyCode) 
	{
		m_IsHold = true;
		return true;
	}

	return false;
}

bool Input::keyReleased(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == m_KeyCode) 
	{
		m_IsHold = false;
		return true;
	}

	return false;
}

bool Input::IsHold() 
{
	return m_IsHold;
}

#pragma endregion
