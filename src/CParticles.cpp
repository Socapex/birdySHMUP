//
//  CParticles.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-23.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CParticles.h"
#include "CEntity.h"

std::vector<CParticles*> CParticles::particleList;

CParticles::CParticles()
{
}

CParticles::CParticles(const CParticles& part)
{
    startTime_ = part.startTime_;
    follow_ = part.follow_;
    spread_ = part.spread_;
    R_ = part.R_;
    G_ = part.G_;
    B_ = part.B_;
    lifeTime_ = part.lifeTime_;
    emitSpeed_ = part.emitSpeed_;
    x_ = part.x_;
    y_ = part.y_;
    width_ = part.width_;
    height_ = part.height_;
    density_ = part.density_;
    quantity_ = part.quantity_;

    rectanglesToDraw_ = part.rectanglesToDraw_;
    rectanglesDrawing_ = part.rectanglesDrawing_;
    surfacesToDraw_ = part.surfacesToDraw_;
    surfacesDrawing_ = part.surfacesDrawing_;

}

CParticles::CParticles(int R, int G, int B, int x, int y, int width, int height,
                       float emitSpeed, unsigned int lifeTime,
                       unsigned int quantity, unsigned int spread, bool follow)
{
    startTime_ = SDL_GetTicks();
    follow_ = follow;
    spread_ = spread;
    R_ = R;
    G_ = G;
    B_ = B;
    lifeTime_ = lifeTime;
    emitSpeed_ = emitSpeed;
    x_ = x;
    y_ = y;
    
    
    for (int i = 0; i < quantity; ++i)
    {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.h = height;
        rect.w = width;
        rectanglesToDraw_.push_back(rect);
    }

    particleList.push_back(this);
}

CParticles::CParticles(std::string type, int x, int y, float emitSpeed,
                       unsigned int lifeTime, unsigned int quantity,
                       unsigned int spread, bool follow)
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

    follow_ = follow;
    emitSpeed_ = emitSpeed;
    spread_ = spread;
    startTime_ = SDL_GetTicks();
    lifeTime_ = lifeTime;
    entity.setX(x);
    entity.setY(y);
    x_ = x;
    y_ = y;

    for (int i = 0; i < quantity; ++i)
    {
        surfacesToDraw_.push_back(entity);
    }

    CParticles::particleList.push_back(this);
    

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
        if (startTime_ + emitSpeed_ < SDL_GetTicks())
        {
            startTime_ = SDL_GetTicks();
            std::pair<SDL_Rect, unsigned int>
                                pair_(rectanglesToDraw_.back(), startTime_);
            rectanglesDrawing_.push_back(pair_);
            rectanglesToDraw_.pop_back();
        }
    }

    //printf("vector size: %u\n", rectanglesDrawing_.size());
    if (!rectanglesDrawing_.empty())
    {
        for (int i = 0; i < rectanglesDrawing_.size(); ++i)
        {
            if (rectanglesDrawing_[i].second + lifeTime_ > SDL_GetTicks())
            {
                if (follow_)
                {
                    rectanglesDrawing_[i].first.x = x_;
                    rectanglesDrawing_[i].first.y = y_;
                }
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
        if (startTime_ + emitSpeed_ < SDL_GetTicks())
        {
            startTime_ = SDL_GetTicks();
            std::pair<CEntity, unsigned int> pair_(surfacesToDraw_.back(),
                                                   startTime_);
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
                CEntity entity = surfacesDrawing_[i].first;

                if (follow_)
                {
                    entity.setX(x_ - (entity.getWidth() / 2));
                    entity.setY(y_ - (entity.getHeight() / 2));
                }
                entity.setX(entity.getX() + rand() % (spread_ * 2) - spread_);
                entity.setY(entity.getY() + rand() % (spread_ * 2) - spread_);
                surfacesDrawing_[i].first = entity;
                surfacesDrawing_[i].first.OnRender(surfDisplay);
            }
        }
    }
}













void CParticles::setX(const int x)
{
    x_ = x;

    // Si on dessine des CEntities
    //if (!surfacesToDraw_.empty() || !surfacesDrawing_.empty()) CEntity::setX(x);
}
void CParticles::setY(const int y)
{
    y_ = y;

    // Si on dessine des CEntities
    //if (!surfacesToDraw_.empty() || !surfacesDrawing_.empty()) CEntity::setX(x);
}
