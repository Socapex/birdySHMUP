//
//  CParticles.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-23.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CParticles.h"
#include "CEntity.h"

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

CParticles::CParticles(int R, int G, int B, float x, float y, int width, int height,
                       float emitSpeed, unsigned int lifeTime,
                       unsigned int quantity, unsigned int spread,
                       std::string animationType, bool follow)
{
    quantity_ = quantity;
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
    play_ = false;


    for (unsigned int i = 0; i < quantity; ++i)
    {
        SDL_Rect rect;
        rect.x = static_cast<int>(x+0.5);
        rect.y = static_cast<int>(y+0.5);
        rect.h = height;
        rect.w = width;
        rectanglesToDraw_.push_back(rect);
    }

    createAnimation(animationType);
}

CParticles::CParticles(std::string type, float x, float y, float emitSpeed,
                       unsigned int lifeTime, unsigned int quantity,
                       unsigned int spread, std::string animationType,
                       bool follow)
{

    CEntity* entity = new CEntity();

    FilePaths Path;

    if (type == "explosion1")
    {
        entity->onLoad(Path.Files["explosion1Path"].c_str(), 320, 300, 20);
        
    }

    else if (type == "explosion2")
    {
        entity->onLoad(Path.Files["explosion2Path"].c_str(), 256, 192, 64);
    }

    else if (type == "explosion3")
    {
        entity->onLoad(Path.Files["explosion3Path"].c_str(), 96, 96, 17);
    }

    else if (type == "explosion4")
    {
        entity->onLoad(Path.Files["explosion4Path"].c_str(), 64, 64, 25);
    }

    quantity_ = quantity;
    follow_ = follow;
    emitSpeed_ = emitSpeed;
    spread_ = spread;
    startTime_ = SDL_GetTicks();
    lifeTime_ = lifeTime;
    entity->setX(x);
    entity->setY(y);
    x_ = x;
    y_ = y;
    play_ = false;

    for (unsigned int i = 0; i < quantity; ++i)
    {
        surfacesToDraw_.push_back(entity);
    }
}

CParticles::~CParticles()
{
    for (unsigned int i = 0; i < surfacesToDraw_.size(); ++i)
    {
        delete surfacesToDraw_[i];
    }
    surfacesToDraw_.clear();

    for (unsigned int i = 0; i < surfacesDrawing_.size(); ++i)
    {
        delete surfacesDrawing_[i].first;
    }
    surfacesDrawing_.clear();
}


void CParticles::play(const float x, const float y)
{
    play_ = true;
    startTime_ = SDL_GetTicks();

    // Reset vectors
    for (unsigned int i = 0; i < surfacesDrawing_.size(); ++i)
    {
        surfacesToDraw_.push_back(surfacesDrawing_.back().first);
        surfacesDrawing_.pop_back();
    }

    for (unsigned int i = 0; i < rectanglesDrawing_.size(); ++i)
    {
        rectanglesToDraw_.push_back(rectanglesDrawing_.back().first);
        rectanglesDrawing_.pop_back();
    }

    // Reset x and y
    if (!surfacesToDraw_.empty())
    {
        for (unsigned int i = 0; i < surfacesToDraw_.size(); ++i)
        {
            surfacesToDraw_[i]->setX(x);
            surfacesToDraw_[i]->setY(y);
        }
    }

    if (!rectanglesToDraw_.empty())
    {
        for (unsigned int i = 0; i < rectanglesToDraw_.size(); ++i)
        {
            rectanglesToDraw_[i].x = static_cast<int>(x+0.5);
            rectanglesToDraw_[i].y = static_cast<int>(y+0.5);
        }
    }

}









void CParticles::onLoop()
{
    
}

void CParticles::onRender(SDL_Surface* surfDisplay)
{
    if (play_)
    {
        if (!rectanglesToDraw_.empty())
        {
            // If emit speed = 0, draw them all at once (insta boom)
            if (emitSpeed_ == 0)
            {
                for (unsigned int i = 0; i < rectanglesToDraw_.size(); ++i)
                {
                    startTime_ = SDL_GetTicks();
                    std::pair<SDL_Rect, unsigned int>
                    pair_(rectanglesToDraw_.back(), startTime_);
                    rectanglesDrawing_.push_back(pair_);
                    rectanglesToDraw_.pop_back();
                }
            }

            // Commencer a dessiner une nouvelle particule?
            else if (startTime_ + emitSpeed_ < SDL_GetTicks())
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
            for (unsigned int i = 0; i < rectanglesDrawing_.size(); ++i)
            {
                if (rectanglesDrawing_[i].second + lifeTime_ > SDL_GetTicks())
                {
                    if (follow_)
                    {
                        //Offset movement
                        float lastX = x_ - rectanglesDrawing_[i].first.x + speedX[i];
                        float lastY = y_ - rectanglesDrawing_[i].first.y + speedY[i];

                        //printf("firstx: %i\n", rectanglesDrawing_[i].first.x);
                        //printf("x: %i\n", x_);
                        //printf("lastx: %i\n", lastX);

                        rectanglesDrawing_[i].first.x += static_cast<int>(lastX+0.5);
                        rectanglesDrawing_[i].first.y += static_cast<int>(lastY+0.5);
                        //printf("addition: %i\n", rectanglesDrawing_[i].first.x);

                    }
                    // TODO: Implementer des animations cool
                    rectanglesDrawing_[i].first.x += static_cast<int>(speedX[i]+0.5);
                    rectanglesDrawing_[i].first.y += static_cast<int>(speedY[i]+0.5);
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
                std::pair<CEntity*, unsigned int> pair_(surfacesToDraw_.back(),
                                                       startTime_);
                surfacesDrawing_.push_back(pair_);
                surfacesToDraw_.pop_back();
            }
        }

        if (!surfacesDrawing_.empty())
        {
            for (unsigned int i = 0; i < surfacesDrawing_.size(); ++i)
            {
                if (surfacesDrawing_[i].second + lifeTime_ > SDL_GetTicks())
                {
                    CEntity* entity = surfacesDrawing_[i].first;

                    if (follow_)
                    {
                        entity->setX(x_ - (entity->getWidth() / 2));
                        entity->setY(y_ - (entity->getHeight() / 2));
                    }
                    entity->setX(entity->getX() + rand() % (spread_ * 2) - spread_);
                    entity->setY(entity->getY() + rand() % (spread_ * 2) - spread_);
                    surfacesDrawing_[i].first = entity;
                    surfacesDrawing_[i].first->onRender(surfDisplay);
                }
            }
        }

        // Done drawing?
        if (surfacesToDraw_.empty() && !surfacesDrawing_.empty())
        {
            if (surfacesDrawing_.back().second + lifeTime_ < SDL_GetTicks())
                play_ = false;
        }

        if (rectanglesToDraw_.empty() && !rectanglesDrawing_.empty())
        {
            if (rectanglesDrawing_.back().second + lifeTime_ < SDL_GetTicks())
                play_ = false;
        }
    }
}









// FUNCTIONS PRIVATE
void CParticles::createAnimation(std::string type)
{
    if (type == "fireworks")
    {
        for (int i = 0; i < quantity_; ++i)
        {
            speedX.push_back(static_cast<float>((rand() % (spread_ * 2)) - spread_));
        }

        for (int i = 0; i < quantity_; ++i)
        {
            speedY.push_back(static_cast<float>((rand() % (spread_ * 2)) - spread_));
        }
    }
}









// GETTERS SETTERS
bool CParticles::getPlaying() const
{
    return play_;
}

void CParticles::setX(const float x)
{
    x_ = x;

    // Si on dessine des CEntities
    //if (!surfacesToDraw_.empty() || !surfacesDrawing_.empty()) CEntity::setX(x);
}
void CParticles::setY(const float y)
{
    y_ = y;

    // Si on dessine des CEntities
    //if (!surfacesToDraw_.empty() || !surfacesDrawing_.empty()) CEntity::setX(x);
}


