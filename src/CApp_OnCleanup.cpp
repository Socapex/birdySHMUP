#include "CApp.h"

void CApp::OnCleanup()
{

    for (int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        CEntity::entityList[i]->OnCleanup();
    }

    CEntity::entityList.clear();

    CArea::AreaControl.OnCleanup();

    SDL_FreeSurface(surfDisplay_);
    SDL_Quit();

    // EXEMPLES
    //SDL_FreeSurface(surfTest_);
}
