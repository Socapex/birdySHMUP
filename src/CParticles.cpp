//
//  CParticles.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-23.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CParticles.h"
#include "CEntity.h"

std::vector<CParticles> CParticles::particleList;

CParticles::CParticles()
{
}

CParticles::CParticles(int R, int G, int B, int x, int y, int width, int height,
           float emitSpeed, uint lifeTime, uint quantity, uint spread)
{
    spread_ = spread;
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

CParticles::CParticles(std::string type, int x, int y, float emitSpeed,
                       uint lifeTime, uint quantity, uint spread)
{
    // Image paths, can't really do this in onInit :(
    std::string explosion1Path = "img/particles/explosion1.jpg";
    std::string explosion2Path = "img/particles/explosion2.png";
    std::string explosion3Path = "img/particles/explosion3.png";
    std::string explosion4Path = "img/particles/explosion4.png";

    // Platform specific:
#ifdef MACTERMINAL
    // Rien faire, on n'as pas besoin de changer le path lorsqu'on compile du
    // terminal sur mac.
#elif __APPLE__
    explosion1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    explosion2Path.insert(0, "birdyShmup.app/Contents/Resources/");
    explosion3Path.insert(0, "birdyShmup.app/Contents/Resources/");
    explosion4Path.insert(0, "birdyShmup.app/Contents/Resources/");

#elif __WIN32__
#endif

    CEntity entity;

    if (type == "explosion1")
    {
        entity.OnLoad(explosion1Path.c_str(), 320, 300, 20);
        
    }

    else if (type == "explosion2")
    {
        entity.OnLoad(explosion2Path.c_str(), 256, 192, 64);
    }

    else if (type == "explosion3")
    {
        entity.OnLoad(explosion3Path.c_str(), 96, 96, 17);
    }

    else if (type == "explosion4")
    {
        entity.OnLoad(explosion4Path.c_str(), 64, 64, 25);
    }

    emitSpeed_ = emitSpeed;
    spread_ = spread;
    startTime = SDL_GetTicks();
    lifeTime_ = lifeTime;
    entity.setX(x);
    entity.setY(y);

    for (int i = 0; i < quantity; ++i)
    {
        surfacesToDraw_.push_back(entity);
    }

    CParticles::particleList.push_back(*this);
    

}

CParticles::~CParticles()
{}




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
            std::pair<SDL_Rect, uint> pair_(rectanglesToDraw_.back(), startTime);
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
                // TODO: Implementer des animations cool
                rectanglesDrawing_[i].first.x += rand() % (spread_ * 2) - spread_;
                rectanglesDrawing_[i].first.y += rand() % (spread_ * 2) - spread_;
                SDL_FillRect(surfDisplay, &rectanglesDrawing_[i].first,
                             SDL_MapRGB(surfDisplay->format, R_, G_, B_));
            }
        }
    }

    if (!surfacesToDraw_.empty())
    {
        if (startTime + emitSpeed_ < SDL_GetTicks())
        {
            startTime = SDL_GetTicks();
            std::pair<CEntity, uint> pair_(surfacesToDraw_.back(), startTime);
            surfacesDrawing_.push_back(pair_);
            surfacesToDraw_.pop_back();
        }
    }

    if (!surfacesDrawing_.empty())
    {
        for (int i = 0; i < surfacesDrawing_.size(); ++i)
        {
            if (surfacesDrawing_[i].second + lifeTime_ > SDL_GetTicks())
            {
                surfacesDrawing_[i].first.setX(surfacesDrawing_[i].first.getX() +
                                         rand() % (spread_ * 2) - spread_);
                surfacesDrawing_[i].first.setY(surfacesDrawing_[i].first.getY() +
                                               rand() % (spread_ * 2) - spread_);
                surfacesDrawing_[i].first.OnRender(surfDisplay);
            }
        }
    }
}




