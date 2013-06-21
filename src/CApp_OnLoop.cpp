#include "CApp.h"

void CApp::OnLoop()
{

    for (int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        CEntity::entityList[i]->OnLoop();
    }

    CFPS::FPSControl.OnLoop();

    // EXEMPLES
    //Anim_Yoshi_.onAnimate();
}
