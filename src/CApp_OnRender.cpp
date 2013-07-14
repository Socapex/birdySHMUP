#include "CApp.h"

void CApp::onRender()
{
    if (currentLevel_ == 0) mainMenu1_.onRender(surfDisplay_);

    if (currentLevel_ == 1) level1_->onRender(surfDisplay_);


    if (currentLevel_ >= 1) gUI_->onRender(surfDisplay_);

    SDL_Flip(surfDisplay_);
}
