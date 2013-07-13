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
    CBullet(const char* file, const int width, const int height,
            const int maxFrames);
    ~CBullet();

    void shoot(const int x, const int y);

    bool onCollision(CEntity* entity);
    void onRender(SDL_Surface* surfDisplay);
    void onAnimate();

private:
    void Init();

    CParticles* deathExplosion_;

    bool enemyBullet;

};

#endif /* defined(__birdyShmup__CBullet__) */
