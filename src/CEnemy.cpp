//
//  CEnemy.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CEnemy.h"
#include "CPlayer.h"
#include "CSFX.h"

CEnemy::CEnemy()
{
    animationStart = 0;
    killPoints_ = 0;
    shootDelay_ = 0;

    deathExplosion_ = NULL;
    bullets_ = NULL;
    deathSound_ = NULL;
}

CEnemy::~CEnemy()
{
    if (deathExplosion_ != NULL) delete deathExplosion_;
    if (bullets_ != NULL) delete bullets_;
    if (deathSound_ != NULL) delete deathSound_;
}







// FUNCTION OVERLOAD

void CEnemy::onLoop(CPlayer* player)
{
    if (!getDead())
    {
        if (checkLife())
        {
            if (shootDelay_ < SDL_GetTicks())
            {
                shootDelay_ += SDL_GetTicks();
                bullets_->shoot(x_, y_);
            }
        }
        else
        {
            setDead(true);
            player->setPlayerPoints(player->getPlayerPoints() + killPoints_);
            deathExplosion_->play(CEntity::x_, CEntity::y_);
            deathSound_->play(SFX_AUDIO_CHANNEL_DEATH);

        }
    }
}

bool CEnemy::onCollision(CEntity *entity)
{
    return true;
}

void CEnemy::onRender(SDL_Surface *surfDisplay)
{
    onAnimate();
    bullets_->onRender(surfDisplay);
    deathExplosion_->onRender(surfDisplay);
    CEntity::onRender(surfDisplay);
}

void CEnemy::onAnimate()
{}










int CEnemy::getAnimStart() const
{
    return animationStart;
}

void CEnemy::setAnimStart(const int time)
{
    animationStart = time;
}
