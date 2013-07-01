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

    

private:
    int x_;
    int y_;
};

#endif /* defined(__birdyShmup__CBullet__) */
