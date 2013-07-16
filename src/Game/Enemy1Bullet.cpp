//
//  Enemy1Bullet.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "Enemy1Bullet.h"
#include "../CSFX.h"

Enemy1Bullet::Enemy1Bullet()
{
    damage_ = 5.0;
    speed_ = 10.0;

    FilePaths Path;

    CEntity::onLoad(Path.Files["bullet1Path"].c_str(), 16, 16, 0);

    deathExplosion_ = new CParticles(255, 255, 0, x_, y_, 2, 3, 0, 100,
                                     100, 10, "fireworks");
    shootSFX_ = new CSFX(Path.Files["sfxLaser1"].c_str());    
}

Enemy1Bullet::~Enemy1Bullet()
{
    
}

bool Enemy1Bullet::onCollision(CEntity* entity)
{
    if (entity->getType() == ENTITY_TYPE_PLAYER && entity->getLife() > 0)
    {
        CBullet::onCollision(entity);
    }
    return true;
}

void Enemy1Bullet::onRender(SDL_Surface *surfDisplay)
{
    onAnimate();
    CBullet::onRender(surfDisplay);
}

void Enemy1Bullet::onAnimate()
{
    y_ += speed_ * CFPS::FPSControl.getSpeedFactor();

    if (y_ > WHEIGHT) setDead(true);
    
}