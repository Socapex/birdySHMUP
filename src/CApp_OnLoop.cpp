#include "CApp.h"

void CApp::onLoop()
{
    if(splashScreen1_.getIsDone() && currentLevel_ == -1) currentLevel_ = 0;

    if (currentLevel_ == 1)
    {
        if (level1_ == NULL)
        {
            level1_ = new Level1();
            gUI_->getReady();
        }
        level1_->onLoop(Player);
    }

    if (currentLevel_ >= 1) gUI_->onLoop(Player);
    CFPS::FPSControl.onLoop();
}
