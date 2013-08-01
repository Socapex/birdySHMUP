//
//  Enemy1.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "Enemy1.h"
#include "../CBulletSpawner.h"
#include "../CSFX.h"

Enemy1::Enemy1()
{
    FilePaths Path;
    
    health_ = 100;
    killPoints_ = 100;
    shootDelay_ = nextShot_ = 2000;
    nextShot_ += SDL_GetTicks();
    CEntity::onLoad(Path.Files["entity1Path"].c_str(), 64, 64, 8);
    deathExplosion_ = new CParticles("explosion3", x_, y_, 0,
                                     1000, 1, 1);
    bullets_ = new CBulletSpawner("enemy1");
    deathSound_ = new CSFX(Path.Files["sfxMedExplosion"].c_str());
}

Enemy1::~Enemy1()
{

}