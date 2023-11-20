#include "InputHandler.h"

bool InputHandler::keyPressed(const OgreBites::KeyboardEvent& keyEvent)
{
    if (keyEvent.keysym.sym == OgreBites::SDLK_RIGHT)
    {
        std::cout << "Right key pressed"<<std::endl;
    }
    return true;
}
