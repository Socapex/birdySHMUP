//
//  CBulletSpawner.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CBulletSpawner.h"


CBulletSpawner::CBulletSpawner()
{

    // TODO: Specify bullet type
    
    FilePaths Path;

    // Pre-generate bullets
    for (int i = 0; i < 100; ++i)
    {
        CBullet* bullet = new PlayerBullet1;
        bulletList_.push_back(bullet);
    }
}

CBulletSpawner::CBulletSpawner(char* bulletType)
{

    // TODO: Specify bullet type

    FilePaths Path;

    // Pre-generate bullets
    for (int i = 0; i < 100; ++i)
    {
        CBullet* bullet;
        if (std::strcmp(bulletType, "player") == 0) bullet = new PlayerBullet1;
        else if (std::strcmp(bulletType, "enemy1") == 0) bullet = new Enemy1Bullet;
        bulletList_.push_back(bullet);
    }
}

CBulletSpawner::~CBulletSpawner()
{
    for (int i = 0; i < bulletList_.size(); ++i) {
        delete bulletList_[i];
    }
    bulletList_.clear();
}


void CBulletSpawner::shoot(const int x, const int y)
{
    for (int i = 0; i < bulletList_.size(); ++i)
    {
        if (bulletList_[i]->getDead())
        {
            bulletList_[i]->shoot(x, y);
            break;
        }
    }
}

void CBulletSpawner::onRender(SDL_Surface* surfDisplay)
{
    // Render bullets
    for (int i = 0; i < bulletList_.size(); ++i)
    {
        if (!bulletList_[i]->getDead()) bulletList_[i]->onRender(surfDisplay);
    }

    // Render explosions
    for (int i = 0; i < bulletList_.size(); ++i)
    {
        if (bulletList_[i]->getDead())
            bulletList_[i]->getDeathExplosion()->onRender(surfDisplay);
    }
}







// GETTERS SETTERS
int CBulletSpawner::getBulletWidth() const
{
    return bulletList_[0]->getWidth();
}