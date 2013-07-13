#include "CApp.h"

void CApp::onEvent(SDL_Event* event)
{
    CEvent::onEvent(event);
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch(sym)
    {

        case SDLK_SPACE:
        {
            Player->setShooting(true);
            break;
        }

        case SDLK_LEFT:
        {
            Player->setMoveLeft(true);
            break;
        }

        case SDLK_RIGHT:
        {
            Player->setMoveRight(true);
            break;
        }

        case SDLK_UP:
        {
            Player->setMoveUp(true);
            break;
        }

        case SDLK_DOWN:
        {
            Player->setMoveDown(true);
            break;
        }

        default: {}
    }
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch(sym)
    {

        case SDLK_SPACE:
        {
            Player->setShooting(false);
            break;
        }

        case SDLK_LEFT:
        {
            Player->setMoveLeft(false);
            break;
        }

        case SDLK_RIGHT:
        {
            Player->setMoveRight(false);
            break;
        }

        case SDLK_UP:
        {
            Player->setMoveUp(false);
            break;
        }

        case SDLK_DOWN:
        {
            Player->setMoveDown(false);
            break;
        }

        default: {}
    }
}
