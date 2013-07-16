//
//  Enemy1Bullet.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__Enemy1Bullet__
#define __birdyShmup__Enemy1Bullet__

#include "../CBullet.h"

class Enemy1Bullet : public CBullet {
public:
    Enemy1Bullet();
    ~Enemy1Bullet();

    bool onCollision(CEntity* entity);
    void onRender(SDL_Surface* surfDisplay);
    void onAnimate();
};

#endif /* defined(__birdyShmup__Enemy1Bullet__) */
