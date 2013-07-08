//
//  CEnnemySpawner.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CEnnemySpawner__
#define __birdyShmup__CEnnemySpawner__

#include <SDL.h>

#include "CEntity.h"

class CEnnemySpawner {
public:
    CEnnemySpawner();
    ~CEnnemySpawner();

    void onLoop();

};

#endif /* defined(__birdyShmup__CEnnemySpawner__) */
