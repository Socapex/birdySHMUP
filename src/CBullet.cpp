//
//  CBullet.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-30.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CBullet.h"
#include "CSFX.h"

CBullet::CBullet()
{
    x_ = 0;
    y_ = 0;
    damage_ = 0;
    speed_ = 0;
    CEntity::setDead(true);

    deathExplosion_ = NULL;
    shootSFX_ = NULL;

}

CBullet::~CBullet()
{
    if (deathExplosion_ != NULL) delete deathExplosion_;
    if (shootSFX_ != NULL) delete shootSFX_;
}







void CBullet::shoot(const int x, const int y)
{
    x_ = x;
    y_ = y;
    CEntity::setDead(false);
    shootSFX_->play(SFX_AUDIO_CHANNEL_LASER);
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
CParticles* CBullet::getDeathExplosion() const
{
    return deathExplosion_;
}

bool CBullet::getPlaying() const
{
    return deathExplosion_->getPlaying();
}

