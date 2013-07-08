//
//  CEnemy.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CEnemy.h"

CEnemy::CEnemy()
{
    life_ = ENEMY1_LIFE;
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

void CEnemy::onLoop(const int vectorPosition)
{
    if (!getDead())
    {
        if (checkLife())
        {

        }
        else
        {
            setDead(true);
            CParticles* explody = new CParticles("explosion3", x_, y_, 0,
                                                 1000, 1, 1);
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