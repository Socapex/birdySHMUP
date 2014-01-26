//
//  PlayerBullet.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__PlayerBullet2__
#define __birdyShmup__PlayerBullet2__

#include "../FilePaths.h"

#include "../CBullet.h"

class PlayerBullet2 : public CBullet {
public:
    PlayerBullet2();
    ~PlayerBullet2();

    bool onCollision(CEntity* entity);
    void onRender(SDL_Surface* surfDisplay);    
    void onAnimate();
    
};

#endif /* defined(__birdyShmup__PlayerBullet__) */
