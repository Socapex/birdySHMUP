//
//  CEnemySpawner.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CEnemySpawner__
#define __birdyShmup__CEnemySpawner__

#include <SDL.h>
#include <vector>
#include <cmath>

#include "FilePaths.h"

#include "CEnemy.h"
#include "CEntity.h"

class CPlayer;

class CEnemySpawner {
public:
    CEnemySpawner();
    CEnemySpawner(const char* file);
    ~CEnemySpawner();

    void onLoop(CPlayer* Player);
    void onRender(SDL_Surface* surfDisplay_);

    void enemyAnimator();

    bool animStraightLine(CEnemy* enemy, const int x, const int y,
                          const float speed);
    

private:
    std::vector<CEnemy*> wave1Enemies_;

    struct wave1 {
        int startTime;
        bool animationStarted;
        bool animationFinished;
    } Wave1;
    
};

#endif /* defined(__birdyShmup__CEnemySpawner__) */
