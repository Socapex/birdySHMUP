//
//  CLevel.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CLevel.h"

CLevel::CLevel()
{

    FilePaths Path;
    
    // ENEMIES
    enemySpawner_.onLoad();


    // BACKGROUND
    background1_.onLoad(Path.backgroundPath.c_str());
	parallax1_.onLoad(Path.parallaxPath.c_str());
	parallax1_.setBackgroundLevel(BACKGROUND_SCROLL_SPEED_LEVEL_4);

    parallax2_.onLoad(Path.parallax2Path.c_str());
    parallax2_.setBackgroundLevel(BACKGROUND_SCROLL_SPEED_LEVEL_2);




    // MUSIC
    music_.onLoad();
    music_.play();


    // TEST
    CParticles* explody = new CParticles(255, 255, 0, 400, 50, 5, 8, 0, 1000,
                                         100, 10, "fireworks");

    explody->play(400, 50);
    //    CParticles* explody2 = new CParticles("explosion3", 400, 200, 1000, 10000,
    //                                      10, 10);
}

CLevel::~CLevel()
{
    for (int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        // Don't delete player
        if (CEntity::entityList[i]->getType() != ENTITY_TYPE_PLAYER)
        {
            CEntity::entityList[i]->onCleanup();            
            delete CEntity::entityList[i];
        }
    }

    CEntity::entityList.clear();

    for (int i = 0; i < CParticles::particleList.size(); ++i)
    {
        delete CParticles::particleList[i];
    }

    CParticles::particleList.clear();
}

void CLevel::onLoop(CPlayer* Player)
{

    enemySpawner_.onLoop(Player);

    // COLLISIONS
    for (int i = 0; i < CEntityCol::EntityColList.size(); ++i)
    {
        CEntity* entityA = CEntityCol::EntityColList[i].entityA;
        CEntity* entityB = CEntityCol::EntityColList[i].entityB;

        if (entityA == NULL || entityB == NULL) continue;

        if (entityA->onCollision(entityB)) entityB->onCollision(entityA);
    }

    CEntityCol::EntityColList.clear();


}

void CLevel::onRender(SDL_Surface* surfDisplay_)
{

    background1_.onRender(surfDisplay_);
	parallax1_.onRender(surfDisplay_);
    parallax2_.onRender(surfDisplay_);

    enemySpawner_.onRender(surfDisplay_);



    // PARTICLES
    for (int i = 0; i < CParticles::particleList.size(); ++i)
    {
        CParticles::particleList[i]->onRender(surfDisplay_);
    }
}