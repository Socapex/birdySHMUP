//
//  PlayerBullet.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__PlayerBullet__
#define __birdyShmup__PlayerBullet__

#include "../FilePaths.h"

#include "../CBullet.h"

class PlayerBullet1 : public CBullet {
public:
    PlayerBullet1();
    ~PlayerBullet1();

    bool onCollision(CEntity* entity);
    void onRender(SDL_Surface* surfDisplay);    
    void onAnimate();
    
};

#endif /* defined(__birdyShmup__PlayerBullet__) */
