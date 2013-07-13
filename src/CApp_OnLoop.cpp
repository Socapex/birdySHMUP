#include "CApp.h"

void CApp::onLoop()
{

    if (currentLevel_ == 1)
    {
        if (level1_ == NULL) level1_ = new Level1();
        level1_->onLoop(Player);
    }

    gUI_->onLoop(Player);
    CFPS::FPSControl.onLoop();
}
