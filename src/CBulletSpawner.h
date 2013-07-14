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

#include "CBullet.h"

class CBulletSpawner {
public:
    CBulletSpawner();
    ~CBulletSpawner();

    void shoot(const int x, const int y);

    void onRender(SDL_Surface* surfDisplay);

    int getBulletWidth() const;

private:
    std::vector<CBullet*> bulletList_;
    
};

#endif /* defined(__birdyShmup__CBulletSpawner__) */
