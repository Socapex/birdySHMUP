//
//  CEnemy.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CEnemy__
#define __birdyShmup__CEnemy__

#include <SDL.h>

#include "Defines.h"
#include "CEntity.h"

class CPlayer;

class CEnemy : public CEntity {
public:
    CEnemy();
    ~CEnemy();

    void onLoop(CPlayer* player);
    bool onCollision(CEntity* entity);
    void onRender(SDL_Surface* surfDisplay);
    void onAnimate();


    int getAnimStart() const;

    void setAnimStart(const int time);

protected:
    CParticles* deathExplosion_;

    int animationStart;
    int killPoints_;

};

#endif /* defined(__birdyShmup__CEnemy__) */
