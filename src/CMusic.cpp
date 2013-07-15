//
//  CMusic.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-10.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CMusic.h"

CMusic::CMusic()
{
    song1_ = NULL;
}

CMusic::CMusic(const char* file)
{
    if((song1_ = Mix_LoadMUS(file)) == NULL)
        printf("Problem loading music file : %s\n", Mix_GetError());
}

CMusic::~CMusic()
{
    if (song1_ != NULL) Mix_FreeMusic(song1_);
}








void CMusic::play()
{
    if (song1_ != NULL) Mix_PlayMusic(song1_, -1);
}
