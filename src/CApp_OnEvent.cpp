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
//                case SDLK_SPACE:
//                {
//                    break;
//                }

                case SDLK_LEFT:
                {
                    //TODO previous button underlined
                    mainMenu1_.previousActiveButtonID();
                    break;
                }

                case SDLK_RIGHT:
                {
                    //TODO next button underlined
                    mainMenu1_.nextActiveButtonID();
                    break;
                }

                case SDLK_UP:
                {
                    //TODO previous button underlined
                    mainMenu1_.previousActiveButtonID();
                    break;
                }

                case SDLK_DOWN:
                {
                    //TODO next button underlined
                    mainMenu1_.nextActiveButtonID();
                    break;
                }

                case SDLK_RETURN:
                {
                    //TODO activate button
                    if(currentLevel_ == -1) currentLevel_ = 0;
                    else if(mainMenu1_.getActiveButtonID() == 0) currentLevel_ = 1;
                    else if(mainMenu1_.getActiveButtonID() == 1) onExit();
                    break;
                }

                case SDLK_ESCAPE:
                {
                    currentLevel_ = 0;
                    break;
                }

                default:
                {
                    currentLevel_ = 0;
                }
            }
    }
    else
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

                case SDLK_ESCAPE:
                {
                    SDL_Quit();
                    break;
                }

                case SDLK_1:
                {
                    Player->setCurrentBullet(0);
                    break;
                }

                case SDLK_2:
                {
                    Player->setCurrentBullet(1);
                    break;
                }

                case SDLK_3:
                {
                    Player->setCurrentBullet(2);
                    break;
                }

                default: {}
            }
    }
    
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    if (currentLevel_ >= 1)
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
}
