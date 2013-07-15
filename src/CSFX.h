//
//  CSFX.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-14.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CSFX__
#define __birdyShmup__CSFX__

#include <SDL.h>
#include <SDL_mixer.h>

class CSFX {
public:
    CSFX();
    CSFX(const char* file);
    ~CSFX();

    void play() const;

private:
    Mix_Chunk* sfx_;
};

#endif /* defined(__birdyShmup__CSFX__) */
