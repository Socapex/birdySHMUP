//
//  CLevel.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CLevel__
#define __birdyShmup__CLevel__

#include <SDL.h>

#include "Defines.h"
#include "FilePaths.h"

#include "CEntity.h"
#include "CEnemySpawner.h"
#include "CBackground.h"
#include "CMusic.h"

class CPlayer;

class CLevel {
public:
    CLevel();
    ~CLevel();

    virtual void onLoop(CPlayer* Player);
    virtual void onRender(SDL_Surface* surfDisplay_);

private:

    CEnemySpawner enemySpawner_;

    CBackground background1_;
	CBackground parallax1_;
    CBackground parallax2_;

    CMusic music_;
};

#endif /* defined(__birdyShmup__CLevel__) */
