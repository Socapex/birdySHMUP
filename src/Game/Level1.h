//
//  Level1.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__Level1__
#define __birdyShmup__Level1__

#include "../FilePaths.h"

#include "../CLevel.h"


class Level1 : public CLevel {
public:
    Level1();
    ~Level1();

    void onLoop(CPlayer* Player);
    void onRender(SDL_Surface* surfDisplay_);
};

#endif /* defined(__birdyShmup__Level1__) */
