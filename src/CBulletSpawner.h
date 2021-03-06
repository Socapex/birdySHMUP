//
//  CBulletSpawner.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CBulletSpawner__
#define __birdyShmup__CBulletSpawner__

#include <SDL.h>
#include <vector>
#include <cstring>

#include "Game/PlayerBullet1.h"
#include "Game/PlayerBullet2.h"
#include "Game/PlayerBullet3.h"
#include "Game/Enemy1Bullet.h"

class CBulletSpawner {
public:
    CBulletSpawner();
    CBulletSpawner(char* bulletType);
    ~CBulletSpawner();

    void shoot(const float x, const float y);

    void onRender(SDL_Surface* surfDisplay);

    int getBulletWidth() const;

private:
    std::vector<CBullet*> bulletList_;
    
};

#endif /* defined(__birdyShmup__CBulletSpawner__) */
