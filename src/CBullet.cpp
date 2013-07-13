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
    this->Init();

    deathExplosion_ = new CParticles(255, 255, 0, x_, y_, 2, 3, 0, 100,
                                               10, 10, "fireworks");
}

CBullet::CBullet(const char* file, const int width, const int height,
                 const int maxFrames)
{
    this->Init();
    CEntity::onLoad(file, width, height, maxFrames);
    deathExplosion_ = new CParticles(255, 255, 0, x_, y_, 2, 3, 0, 100,
                                     10, 10, "fireworks");
}

CBullet::~CBullet()
{
    
}

// PRIVATE
void CBullet::Init()
{
    x_ = 0;
    y_ = 0;
    enemyBullet = false;
    CEntity::setDead(true);
}








void CBullet::shoot(const int x, const int y)
{
    x_ = x;
    y_ = y;
    setDead(false);
}







// FUNCTION OVERLOAD

bool CBullet::onCollision(CEntity* entity)
{

    // TODO: Different collision checks for different bullet types
    if (!enemyBullet)
    {
        if (entity->getType() == ENTITY_TYPE_ENEMY1 && entity->getLife() > 0)
        {
            // this bullet
            setDead(true);
            
            deathExplosion_->play(x_, y_);

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
    y_ -= BULLET_1_SPEED * CFPS::FPSControl.getSpeedFactor();

    checkCollision(x_, y_);

    if (y_ < 0) setDead(true);

}











// GETTERS




