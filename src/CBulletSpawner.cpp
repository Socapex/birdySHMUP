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

    FilePaths Path;

    // Pre-generate bullets
    for (int i = 0; i < 100; ++i)
    {
        CBullet* bullet = new CBullet(Path.bullet1Path.c_str(), 16, 16, 0);
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
}







// GETTERS SETTERS
int CBulletSpawner::getBulletWidth() const
{
    return bulletList_[0]->getWidth();
}