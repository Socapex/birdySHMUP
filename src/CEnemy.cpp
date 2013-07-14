//
//  CEnemy.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CEnemy.h"
#include "CPlayer.h"

CEnemy::CEnemy()
{
    animationStart = 0;
    killPoints_ = 0;
}

CEnemy::~CEnemy()
{
    delete deathExplosion_;
}







// FUNCTION OVERLOAD

void CEnemy::onLoop(CPlayer* player)
{
    if (!getDead())
    {
        if (checkLife())
        {

        }
        else
        {
            setDead(true);
            player->setPlayerPoints(player->getPlayerPoints() + killPoints_);
            deathExplosion_->play(CEntity::x_, CEntity::y_);

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
