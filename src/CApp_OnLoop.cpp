#include "CApp.h"

void CApp::onLoop()
{

    if (currentLevel_ == 1)
    {
        if (level1_ == NULL) level1_ = new CLevel();
        level1_->onLoop(Player);
    }

    CGUI::gUI.onLoop(Player);
    CFPS::FPSControl.onLoop();

    // EXEMPLES
    //Anim_Yoshi_.onAnimate();
}
