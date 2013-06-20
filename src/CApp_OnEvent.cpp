#include "CApp.h"

void CApp::OnEvent(SDL_Event* event)
{
    CEvent::OnEvent(event);
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch(sym)
    {
        case SDLK_LEFT:
            {
                player1_.setMoveLeft(true);
                break;
            }

        case SDLK_RIGHT:
            {
                player1_.setMoveRight(true);
                break;
            }

        // Exemples
        // case SDLK_UP:       CCamera::CameraControl.OnMove(0, 5); break;
        // case SDLK_DOWN:     CCamera::CameraControl.OnMove(0, -5); break;
        // case SDLK_LEFT:     CCamera::CameraControl.OnMove(5, 0); break;
        // case SDLK_RIGHT:    CCamera::CameraControl.OnMove(-5, 0); break;
        default: {}
    }
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch(sym)
    {
        case SDLK_LEFT:
            {
                player1_.setMoveLeft(false);
                break;
            }

        case SDLK_RIGHT:
            {
                player1_.setMoveRight(false);
                break;
            }

        default: {}
    }
}
