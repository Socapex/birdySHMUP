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
    song1_ = Mix_LoadMUS(file);
}

CMusic::~CMusic()
{
    Mix_FreeMusic(song1_);
}








void CMusic::play()
{
    Mix_PlayMusic(song1_, -1);
}
