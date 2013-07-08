#include "CApp.h"

void CApp::onCleanup()
{

    for (int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        CEntity::entityList[i]->onCleanup();

        // Don't delete player cause not dynamic memory
        if (CEntity::entityList[i]->getType() != ENTITY_TYPE_PLAYER)
            delete CEntity::entityList[i];
    }

    CEntity::entityList.clear();

    for (int i = 0; i < CParticles::particleList.size(); ++i)
    {
        delete CParticles::particleList[i];
    }

    CParticles::particleList.clear();

    SDL_FreeSurface(surfDisplay_);
    SDL_Quit();

    // EXEMPLES
    //SDL_FreeSurface(surfTest_);
}
