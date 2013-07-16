#include "CApp.h"

void CApp::onEvent(SDL_Event* event)
{
    CEvent::onEvent(event);
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{

    if (currentLevel_ < 1)
    {
        switch(sym)
            {
                case SDLK_SPACE:
                {
                    currentLevel_ = 1;
                    break;
                }

                case SDLK_LEFT:
                {
                    //TODO previous button underlined
                    break;
                }

                case SDLK_RIGHT:
                {
                    //TODO next button underlined
                    break;
                }

                case SDLK_UP:
                {
                    //TODO previous button underlined
                    break;
                }

                case SDLK_DOWN:
                {
                    //TODO next button underlined
                    break;
                }

                case SDLK_RETURN:
                {
                    //TODO activate button
                    break;
                }

                case SDLK_ESCAPE:
                {
                    SDL_Quit();
                    break;
                }

                default: {}
            }
    }
    else
    {
        switch(sym)
            {

                case SDLK_SPACE:
                {
                    Player->setShooting(true);
                    currentLevel_ = 1;
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

                case SDLK_ESCAPE:
                {
                    SDL_Quit();
                    break;
                }                

                default: {}
            }
    }
    
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch(sym)
    {

        case SDLK_SPACE:
        {
            Player->setShooting(false);
            currentLevel_ = 1;
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
