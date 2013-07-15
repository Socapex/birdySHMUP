//
//  CEnemySpawner.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CEnemySpawner.h"

CEnemySpawner::CEnemySpawner()
{
	Wave1.startTime = SDL_GetTicks() + 3000;
	Wave1.animationStarted = false;
	Wave1.animationFinished = false;




    // Todo: Read these values from text file
    FilePaths Path;
    for (int i = 0; i < 8; ++i)
    {
        CEnemy* entity1_ = new Enemy1();

        // Init offscreen
        entity1_->setX(i * 75.0f);
        entity1_->setY(-200.0);
        entity1_->setAnimStart(i*500);
        entity1_->setType(ENTITY_TYPE_ENEMY1);
        CEntity::entityList.push_back(entity1_);
        wave1Enemies_.push_back(entity1_);
    }
}

// TODO: Read from text file
CEnemySpawner::CEnemySpawner(const char* file)
{

}

CEnemySpawner::~CEnemySpawner()
{
    for (unsigned int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        // Don't delete player
        if (CEntity::entityList[i]->getType() != ENTITY_TYPE_PLAYER)
        {
            delete CEntity::entityList[i];
        }
    }

    CEntity::entityList.clear();
}


void CEnemySpawner::onLoop(CPlayer* Player)
{
    // ENTITIES
    for (unsigned int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        CEntity::entityList[i]->onLoop(Player);
    }
}

void CEnemySpawner::onRender(SDL_Surface* surfDisplay_)
{
    enemyAnimator();

    // ENTITIES
    for (unsigned int i = 0; i < CEntity::entityList.size(); ++i)
    {
        if (!CEntity::entityList[i]) continue;

        CEntity::entityList[i]->onRender(surfDisplay_);
    }
}

void CEnemySpawner::enemyAnimator()
{
    if (Wave1.startTime >= SDL_GetTicks() || Wave1.animationStarted)
    {
        Wave1.animationStarted = true;


        // TODO: Lire d'un fichier text somehow
        if (!Wave1.animationFinished)
        {
            for (unsigned int i = 0; i < wave1Enemies_.size(); ++i)
            {
                if (Wave1.startTime + wave1Enemies_[i]->getAnimStart() <
                    SDL_GetTicks())
                {
                    bool finished = animStraightLine(wave1Enemies_[i],
                                                     i * 75.0f, 200.0f, 10.0f);

                    if (i == wave1Enemies_.size() - 1) Wave1.animationFinished =
                                                        finished;
                }
            }
        }

//        else
//        {
//            for (int i = 0; i < wave1Enemies_.size(); ++i)
//            {
//                animStraightLine(wave1Enemies_[i],
//                                                 0, -200, 10);
//
//            }
//        }

    }
}

bool CEnemySpawner::animStraightLine(CEnemy* enemy, const float x, const float y,
                                     const float speed)
{
    float deltaX = x - enemy->getX();
    float deltaY = y - enemy->getY();

    // Est-ce que nous somme tres proche?
    if (sqrtf(powf(deltaX, 2) + powf(deltaY, 2)) <= speed)
    {
        enemy->setX(x);
        enemy->setY(y);
        return true;
    }

    float tetaX = acosf(deltaX / sqrtf(powf(deltaX, 2) + powf(deltaY, 2)));
    float tetaY = asinf(deltaY / sqrtf(powf(deltaX, 2) + powf(deltaY, 2)));

    float newX = cosf(tetaX) * speed * CFPS::FPSControl.getSpeedFactor();
    float newY = sinf(tetaY) * speed * CFPS::FPSControl.getSpeedFactor();

    enemy->setX(enemy->getX() + newX);
    enemy->setY(enemy->getY() + newY);

    return false;
}