//
//  PlayerBullet.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "PlayerBullet1.h"

PlayerBullet1::PlayerBullet1()
{
    damage_ = 10.0;
    
    FilePaths Path;
    
    CEntity::onLoad(Path.bullet1Path.c_str(), 16, 16, 0);
    
    deathExplosion_ = new CParticles(255, 255, 0, x_, y_, 2, 3, 0, 100,
                                     10, 10, "fireworks");

}

PlayerBullet1::~PlayerBullet1()
{
    
}

bool PlayerBullet1::onCollision(CEntity* entity)
{

    // TODO: Different collision checks for different bullet types

    if (entity->getType() == ENTITY_TYPE_ENEMY1 && entity->getLife() > 0)
    {
        // this bullet
        setDead(true);

        deathExplosion_->play(x_, y_);

        // TODO: Checker le genre de bullet
        entity->setLife(entity->getLife() - damage_);
    }

    
    return true;
}

void PlayerBullet1::onRender(SDL_Surface *surfDisplay)
{
    onAnimate();
    CBullet::onRender(surfDisplay);
}

void PlayerBullet1::onAnimate()
{
    y_ -= BULLET_1_SPEED * CFPS::FPSControl.getSpeedFactor();

    if (y_ < 0) setDead(true);
    
}