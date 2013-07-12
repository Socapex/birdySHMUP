#include "CApp.h"

void CApp::onRender()
{
    mainMenu1_.onRender(surfDisplay_);

    if (currentLevel_ == 1) level1_->onRender(surfDisplay_);



    CGUI::gUI.onRender(surfDisplay_);

    SDL_Flip(surfDisplay_);

    // EXEMPLES
    //CSurface::OnDraw(surfDisplay_, surfTest_, 0, 0);
    //CSurface::OnDraw(surfDisplay_, surfTest_, 290, 220, 0, Anim_Yoshi_.getCurrentFrame() * 64, 64, 64);
}
