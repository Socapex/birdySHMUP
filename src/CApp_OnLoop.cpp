#include "CApp.h"

void CApp::onLoop()
{

    for (int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        CEntity::entityList[i]->onLoop();
    }

    // COLLISIONS
    for (int i = 0; i < CEntityCol::EntityColList.size(); ++i)
    {
        CEntity* entityA = CEntityCol::EntityColList[i].entityA;
        CEntity* entityB = CEntityCol::EntityColList[i].entityB;

        if (entityA == NULL || entityB == NULL) continue;

        if (entityA->onCollision(entityB)) entityB->onCollision(entityA);
    }

    CEntityCol::EntityColList.clear();

    // GUI
    CGUI::gUI.onLoop(&Player);

    CFPS::FPSControl.onLoop();

    // EXEMPLES
    //Anim_Yoshi_.onAnimate();
}
