#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include <vector>

class Input : public OgreBites::InputListener
{
	OgreBites::Keycode m_KeyCode;

	//We can use and enum and timer for creating OnKey,OnKeyDown and OnkeyUp just like unity but for now bool is enough jsut for key up and down;
	bool m_IsHold = false;

public:
	Input(OgreBites::Keycode keyCode);
	virtual ~Input() {};

	bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
	bool keyReleased(const OgreBites::KeyboardEvent& evt) override;
	bool IsHold();
};

//TODO: make InputManager Singleton
class InputManager : public Ogre::FrameListener
{
private:
	Input* m_UpInput = new Input(OgreBites::SDLK_UP);
	Input* m_DownInput = new Input(OgreBites::SDLK_DOWN);
	Input* m_RightInput = new Input(OgreBites::SDLK_RIGHT);
	Input* m_LeftInput = new Input(OgreBites::SDLK_LEFT);
	std::vector<Input*> m_Inputs = {m_UpInput,m_DownInput,m_RightInput,m_LeftInput};

	Ogre::Vector2 m_MoveInput;
	void CalculateMoveInput();

public:
	InputManager();
	~InputManager();
	const std::vector<Input*>& GetInputs() const;
	bool frameStarted(const Ogre::FrameEvent& evt) override;
	const Ogre::Vector2& GetMoveInput() const;
};
