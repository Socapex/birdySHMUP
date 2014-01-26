//
//  PlayerBullet.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "PlayerBullet2.h"
#include "../CSFX.h"

PlayerBullet2::PlayerBullet2()
{
    damage_ = 10.0;
    speed_ = 50.0;
    
    FilePaths Path;
    
    CEntity::onLoad(Path.Files["whiteBullet1"].c_str(), 380, 280, 0);
    
    deathExplosion_ = new CParticles(255, 255, 0, x_, y_, 2, 3, 0, 100,
                                     100, 10, "fireworks");
    shootSFX_ = new CSFX(Path.Files["sfxLaser1"].c_str());

}

PlayerBullet2::~PlayerBullet2()
{
    
}

bool PlayerBullet2::onCollision(CEntity* entity)
{
    if (entity->getType() == ENTITY_TYPE_ENEMY1 && entity->getLife() > 0)
    {
        CBullet::onCollision(entity);
    }
    return true;
}

void PlayerBullet2::onRender(SDL_Surface *surfDisplay)
{
    onAnimate();
    CBullet::onRender(surfDisplay);
}

void PlayerBullet2::onAnimate()
{
    y_ -= speed_ * CFPS::FPSControl.getSpeedFactor();

    if (y_ + height_ < 0) setDead(true); // En dehors de l'ecran
    
}