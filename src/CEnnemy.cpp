//
//  CEnnemy.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CEnnemy.h"

CEnnemy::CEnnemy()
{
    life_ = ENNEMY1_LIFE;
}

CEnnemy::~CEnnemy()
{}







// FUNCTION OVERLOAD

bool CEnnemy::onLoad(const char* file, const int width, const int height,
                     const int maxFrames)
{
    if (CEntity::onLoad(file, width, height, maxFrames) == false) return false;

    return true;
}

void CEnnemy::onLoop(const int vectorPosition)
{
    if (checkLife())
    {

    }
    else
    {
        setDead(true);
        CEntity::entityList.erase(CEntity::entityList.begin() + vectorPosition);
    }
}

bool CEnnemy::onCollision(CEntity *entity)
{
    return true;
}

void CEnnemy::onRender(SDL_Surface *surfDisplay)
{
    onAnimate();
    CEntity::onRender(surfDisplay);
}

void CEnnemy::onAnimate()
{}