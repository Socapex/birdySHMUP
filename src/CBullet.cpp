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
    damage_ = 0;
    speed_ = 0;
    CEntity::setDead(true);

}

CBullet::~CBullet()
{
    //TODO: delete ParticleSpawner (not the static particle vector)
    delete deathExplosion_;
}







void CBullet::shoot(const int x, const int y)
{
    x_ = x;
    y_ = y;
    CEntity::setDead(false);
}







// FUNCTION OVERLOAD

bool CBullet::onCollision(CEntity* entity)
{
    // this bullet
    setDead(true);

    deathExplosion_->play(x_, y_);

    // TODO: Checker le genre de bullet
    entity->setLife(entity->getLife() - damage_);
    return true;
}

void CBullet::onRender(SDL_Surface *surfDisplay)
{
    checkCollision(x_, y_);
    deathExplosion_->onRender(surfDisplay);
    CEntity::onRender(surfDisplay);
}












// GETTERS




