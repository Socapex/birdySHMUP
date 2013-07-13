#include "CApp.h"

void CApp::onRender()
{
    mainMenu1_.onRender(surfDisplay_);

    /*
    background1_.onRender(surfDisplay_);
	
    parallax1_.onRender(surfDisplay_);
    parallax2_.onRender(surfDisplay_);
    
    enemySpawner_.onRender();

    // ENTITIES
    for (int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        CEntity::entityList[i]->onRender(surfDisplay_);
    }

    // PARTICLES
    for (int i = 0; i < CParticles::particleList.size(); ++i)
    {
        CParticles::particleList[i]->onRender(surfDisplay_);
    }

    CGUI::gUI.onRender(surfDisplay_);
    */

    SDL_Flip(surfDisplay_);

    // EXEMPLES
    //CSurface::OnDraw(surfDisplay_, surfTest_, 0, 0);
    //CSurface::OnDraw(surfDisplay_, surfTest_, 290, 220, 0, Anim_Yoshi_.getCurrentFrame() * 64, 64, 64);
}
