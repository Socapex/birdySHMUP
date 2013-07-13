#include "CApp.h"

void CApp::onRender()
{
    mainMenu1_.onRender(surfDisplay_);

    if (currentLevel_ == 1) level1_->onRender(surfDisplay_);

    gUI_->onRender(surfDisplay_);

    SDL_Flip(surfDisplay_);
}
