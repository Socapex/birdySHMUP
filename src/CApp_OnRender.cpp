#include "CApp.h"

void CApp::OnRender()
{

    CArea::AreaControl.OnRender(surfDisplay_, CCamera::CameraControl.getX(),
                                    CCamera::CameraControl.getY());

    for (int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        CEntity::entityList[i]->OnRender(surfDisplay_);
    }

    SDL_Flip(surfDisplay_);

    // EXEMPLES
    //CSurface::OnDraw(surfDisplay_, surfTest_, 0, 0);
    //CSurface::OnDraw(surfDisplay_, surfTest_, 290, 220, 0, Anim_Yoshi_.getCurrentFrame() * 64, 64, 64);
}
