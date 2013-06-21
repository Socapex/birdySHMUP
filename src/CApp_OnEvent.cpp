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
                Player.setMoveLeft(true);
                break;
            }

        case SDLK_RIGHT:
            {
                Player.setMoveRight(true);
                break;
            }

        case SDLK_UP:
            {
                Player.setMoveUp(true);
                break;
            }

        case SDLK_DOWN:
            {
                Player.setMoveDown(true);
            }

        case SDLK_SPACE:
            {
                // BANG BANG
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
                Player.setMoveLeft(false);
                break;
            }

        case SDLK_RIGHT:
            {
                Player.setMoveRight(false);
                break;
            }

        case SDLK_UP:
            {
                Player.setMoveUp(false);
                break;
            }

        case SDLK_DOWN:
            {
                Player.setMoveDown(false);
            }

        default: {}
    }
}
