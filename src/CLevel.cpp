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
    levelStartTime = SDL_GetTicks();

    enemySpawner_ = NULL;
    background1_ = NULL;
    parallax1_ = NULL;
    parallax2_ = NULL;
    music_ = NULL;

}

CLevel::~CLevel()
{
    delete enemySpawner_;
    delete background1_;
    delete parallax1_;
    delete parallax2_;
    delete music_;
}

void CLevel::onLoop(CPlayer* Player)
{

    enemySpawner_->onLoop(Player);

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

    background1_->onRender(surfDisplay_);
	parallax1_->onRender(surfDisplay_);
    parallax2_->onRender(surfDisplay_);

    enemySpawner_->onRender(surfDisplay_);

}






// GETTERS SETTERS
int CLevel::getLevelStartTime() const
{
    return levelStartTime;
}
