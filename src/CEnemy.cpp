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
    life_ = ENEMY1_LIFE;

    animationStart = 0;

    deathExplosion_ = new CParticles("explosion3", x_, y_, 0,
                                         1000, 1, 1);
}

CEnemy::~CEnemy()
{}







// FUNCTION OVERLOAD

bool CEnemy::onLoad(const char* file, const int width, const int height,
                     const int maxFrames)
{
    if (CEntity::onLoad(file, width, height, maxFrames) == false) return false;

    return true;
}

void CEnemy::onLoop(const int vectorPosition, CPlayer* player)
{
    if (!getDead())
    {
        if (checkLife())
        {

        }
        else
        {
            setDead(true);
            player->setPlayerPoints(player->getPlayerPoints() + 100);
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
