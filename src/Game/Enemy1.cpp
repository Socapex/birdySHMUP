//
//  Enemy1.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "Enemy1.h"

Enemy1::Enemy1()
{
    FilePaths Path;
    
    life_ = 100;
    killPoints_ = 100;
    CEntity::onLoad(Path.entity1Path.c_str(), 64, 64, 8);
    deathExplosion_ = new CParticles("explosion3", x_, y_, 0,
                                     1000, 1, 1);
}

Enemy1::~Enemy1()
{

}