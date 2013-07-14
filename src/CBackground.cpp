//
//  CBackground.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-30.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CBackground.h"

CBackground::CBackground()
{
	backgroundLevel_ = BACKGROUND_SCROLL_SPEED_LEVEL_1;

    x_ = 0;
    y_ = 0;
}

CBackground::~CBackground()
{
    SDL_FreeSurface(surfBackground_);
}

bool CBackground::onLoad(const char* file)
{
    if ((surfBackground_ = CSurface::onLoad(file)) == NULL) return false;

    // Centrer l'image pour le parallax
    x_ = (WWIDTH / 2) - (surfBackground_->w / 2);

	// Savoir ou le player spawn au debut pour le parallax	
	tempX_ = CEntity::entityList[0]->getX();
	tempY_ = CEntity::entityList[0]->getY();

    return true;
}

void CBackground::onRender(SDL_Surface* surfDisplay)
{
    if (surfBackground_ == NULL || surfDisplay == NULL) return;

    onAnimate();

    if (y_ > 0)
    {
        CSurface::OnDraw(surfDisplay, surfBackground_, x_, y_ - surfBackground_->h - 1);
    }

    if (y_ > WHEIGHT)
    {
        y_ = y_ - surfBackground_->h;
    }

    CSurface::OnDraw(surfDisplay, surfBackground_, x_, y_);
}

void CBackground::onAnimate()
{
	// Ajouter un facteur pour accelerer l'effet de deplacement en y
	y_ += backgroundLevel_ * CFPS::FPSControl.getSpeedFactor();

	//Paralax en x
	if(tempX_ < CEntity::entityList[0]->getX())
	{
		x_ -= (float)backgroundLevel_/4;
	}
	else if(tempX_ > CEntity::entityList[0]->getX())
	{
		x_ += (float)backgroundLevel_/4;
	}
	tempX_ = CEntity::entityList[0]->getX();

	//Parallax en y
	if(tempY_ < CEntity::entityList[0]->getY())
	{
		y_ -= (float)backgroundLevel_/4;
	}
	else if(tempY_ > CEntity::entityList[0]->getY())
	{
		y_ += (float)backgroundLevel_/4;
	}
	tempY_ = CEntity::entityList[0]->getY();

}

void CBackground::setBackgroundLevel(int backgroundLevel)
{
	backgroundLevel_ = backgroundLevel;
}

SDL_Surface* CBackground::getSurface()
{
    return surfBackground_;
}