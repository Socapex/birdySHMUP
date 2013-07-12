#include "CApp.h"

void CApp::onCleanup()
{
    delete Player;
    delete level1_;

    CGUI::gUI.onCleanup();

    SDL_FreeSurface(surfDisplay_);

    TTF_Quit();
    SDL_Quit();

    // EXEMPLES
    //SDL_FreeSurface(surfTest_);
}
