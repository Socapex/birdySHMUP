//
//  CEnemy.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CEnemy__
#define __birdyShmup__CEnemy__

#include <SDL.h>

#include "Defines.h"
#include "CEntity.h"

class CEnemy : public CEntity {
public:
    CEnemy();
    ~CEnemy();

    bool onLoad(const char* file, const int width, const int height,
                const int maxFrames);
    void onLoop(const int vectorPosition);    
    bool onCollision(CEntity* entity);
    void onRender(SDL_Surface* surfDisplay);
    void onAnimate();
    
};

#endif /* defined(__birdyShmup__CEnemy__) */
