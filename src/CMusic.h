//
//  CMusic.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-10.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CMusic__
#define __birdyShmup__CMusic__

#include <SDL.h>
#include <SDL_mixer.h>

#include "FilePaths.h"

class CMusic {
public:
    CMusic();
    CMusic(const char* file);
    ~CMusic();

    void play();

    bool onLoad();

private:
    Mix_Music* song1_;
    
};

#endif /* defined(__birdyShmup__CMusic__) */
