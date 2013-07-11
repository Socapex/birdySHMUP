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
    
}

CMusic::~CMusic()
{}

void CMusic::play()
{
    Mix_PlayMusic(song1_, -1);
}

bool CMusic::onLoad()
{
    FilePaths Path;

    song1_ = Mix_LoadMUS(Path.song1Path.c_str());
    
    return true;
}