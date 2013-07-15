//
//  PlayerBullet.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "PlayerBullet1.h"
#include "../CSFX.h"

PlayerBullet1::PlayerBullet1()
{
    damage_ = 10.0;
    speed_ = 50.0;
    
    FilePaths Path;
    
    CEntity::onLoad(Path.Files["bullet1Path"].c_str(), 16, 16, 0);
    
    deathExplosion_ = new CParticles(255, 255, 0, x_, y_, 2, 3, 0, 100,
                                     100, 10, "fireworks");
    shootSFX_ = new CSFX(Path.Files["sfxLaser1"].c_str());

}

PlayerBullet1::~PlayerBullet1()
{
    
}

bool PlayerBullet1::onCollision(CEntity* entity)
{
    if (entity->getType() == ENTITY_TYPE_ENEMY1 && entity->getLife() > 0)
    {
        CBullet::onCollision(entity);
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
    y_ -= speed_ * CFPS::FPSControl.getSpeedFactor();

    if (y_ < 0) setDead(true);
    
}