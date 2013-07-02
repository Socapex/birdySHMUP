//
//  CBackground.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-30.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CBackground__
#define __birdyShmup__CBackground__

#include <SDL.h>

#include "Defines.h"
#include "CSurface.h"
#include "CFPS.h"

class CBackground {
public:
    CBackground();
    ~CBackground();

    bool onLoad(const char* file);
    void onRender(SDL_Surface* surfDisplay);
    void onAnimate();

private:
    SDL_Surface* surfBackground_;

    int x_;
    int y_;

};

#endif /* defined(__birdyShmup__CBackground__) */
