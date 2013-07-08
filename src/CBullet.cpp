//
//  CBullet.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-30.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CBullet.h"

CBullet::CBullet()
{
    x_ = 0;
    y_ = 0;
    enemyBullet = false;
    setDead(true);
}

CBullet::~CBullet()
{
    
}

void CBullet::shoot(const int x, const int y)
{
    x_ = x;
    y_ = y;
    setDead(false);
}









// FUNCTION OVERLOAD

bool CBullet::onLoad(const char* file, const int width, const int height,
                     const int maxFrames)
{
    if (CEntity::onLoad(file, width, height, maxFrames) == false) return false;

    return true;
}

bool CBullet::onCollision(CEntity* entity)
{

    // TODO: Different collision checks for different bullet types
    if (!enemyBullet)
    {
        if (entity->getType() == ENTITY_TYPE_ENEMY1 && life_ > 0)
        {
            setDead(true);
            CParticles* explode = new CParticles(255, 255, 0, x_, y_, 5, 8, 0, 1000,
                                                 100, 10, "fireworks");

            // TODO: Checker le genre de bullet
            entity->setLife(entity->getLife() - 10.0);
        }
    }


    return true;
}

void CBullet::onRender(SDL_Surface *surfDisplay)
{
    onAnimate();
    CEntity::onRender(surfDisplay);
}

void CBullet::onAnimate()
{
    y_ -= BULLET_1_SPEED;
    y_ -= CFPS::FPSControl.getSpeedFactor();

    checkCollision(x_, y_);

    if (y_ < 0) setDead(true);

}











// GETTERS




