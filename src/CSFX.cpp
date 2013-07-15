//
//  CSFX.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-14.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CSFX.h"

CSFX::CSFX()
{
    sfx_ = NULL;
}

CSFX::CSFX(const char* file)
{
    if ((sfx_ = Mix_LoadWAV(file)) == NULL)
        printf("Problem loading sfx file : %s\n", Mix_GetError());
}

CSFX::~CSFX()
{
    if (sfx_ != NULL) Mix_FreeChunk(sfx_);
}



void CSFX::play(const int channel) const
{
    Mix_PlayChannel(channel, sfx_, 0);
}