//
//  CParticles.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-23.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CParticles.h"

std::vector<CParticles> CParticles::particleList;

CParticles::CParticles()
{
    surfaceParticle_ = NULL;
}

CParticles::CParticles(int R, int G, int B, int x, int y, int width, int height,
           float emitSpeed, uint lifeTime, uint quantity)
{
    surfaceParticle_ = NULL;
    R_ = R;
    G_ = G;
    B_ = B;
    startTime = SDL_GetTicks();
    lifeTime_ = lifeTime;
    emitSpeed_ = emitSpeed;
    
    for (int i = 0; i < quantity; ++i)
    {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.h = height;
        rect.w = width;
        rectanglesToDraw_.push_back(rect);
    }

    particleList.push_back(*this);
}

CParticles::CParticles(SDL_Surface* surface, int x, int y, float emitSpeed,
                       float lifeTime, int density)
{

}

CParticles::~CParticles()
{
    if (surfaceParticle_ != NULL) SDL_FreeSurface(surfaceParticle_);
}




void CParticles::onLoop()
{
    
}

void CParticles::onRender(SDL_Surface* surfDisplay)
{
    if (!rectanglesToDraw_.empty())
    {
        // Commencer a dessiner une nouvelle particule?
        if (startTime + emitSpeed_ < SDL_GetTicks())
        {
            startTime = SDL_GetTicks();
            std::pair<SDL_Rect, int> pair_(rectanglesToDraw_.back(), startTime);
            rectanglesDrawing_.push_back(pair_);
            rectanglesToDraw_.pop_back();
        }
    }

    if (!rectanglesDrawing_.empty())
    {
        for (int i = 0; i < rectanglesDrawing_.size(); ++i)
        {
            if (rectanglesDrawing_[i].second + lifeTime_ > SDL_GetTicks())
            {
                rectanglesDrawing_[i].first.x += rand() % 6 - 3;
                rectanglesDrawing_[i].first.y += rand() % 6 - 3;
                SDL_FillRect(surfDisplay, &rectanglesDrawing_[i].first,
                             SDL_MapRGB(surfDisplay->format, R_, G_, B_));
            }
        }
    }

    if (surfaceList_.size() > 0)
    {
        
    }
}




