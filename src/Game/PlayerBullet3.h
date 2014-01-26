//
//  PlayerBullet.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__PlayerBullet3__
#define __birdyShmup__PlayerBullet3__

#include "../FilePaths.h"

#include "../CBullet.h"

class PlayerBullet3 : public CBullet {
public:
    PlayerBullet3();
    ~PlayerBullet3();

    bool onCollision(CEntity* entity);
    void onRender(SDL_Surface* surfDisplay);    
    void onAnimate();
    
};

#endif /* defined(__birdyShmup__PlayerBullet__) */
