//
//  CBullet.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-30.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CBullet__
#define __birdyShmup__CBullet__

#include <SDL.h>

#include "CEntity.h"

class CBullet : public CEntity {
public:
    CBullet();
    ~CBullet();

    void shoot(const int x, const int y);

    virtual bool onCollision(CEntity* entity);
    virtual void onRender(SDL_Surface* surfDisplay);

    CParticles* getDeathExplosion() const;
    bool getPlaying() const;

protected:
    CParticles* deathExplosion_;

    float damage_;
    float speed_;

};

#endif /* defined(__birdyShmup__CBullet__) */
