#include "CApp.h"

void CApp::OnLoop()
{

    for (int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        CEntity::entityList[i]->OnLoop();
    }

    // COLLISIONS
    for (int i = 0; i < CEntityCol::EntityColList.size(); ++i)
    {
        CEntity* entityA = CEntityCol::EntityColList[i].entityA;
        CEntity* entityB = CEntityCol::EntityColList[i].entityB;

        if (entityA == NULL || entityB == NULL) continue;

        if (entityA->OnCollision(entityB)) entityB->OnCollision(entityA);
    }

    CEntityCol::EntityColList.clear();

    CFPS::FPSControl.OnLoop();

    // EXEMPLES
    //Anim_Yoshi_.OnAnimate();
}
