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

    return true;
}

void CBackground::onRender(SDL_Surface* surfDisplay)
{
    if (surfBackground_ == NULL || surfDisplay == NULL) return;

    onAnimate();

    if (y_ > 0)
    {
        CSurface::OnDraw(surfDisplay, surfBackground_, x_, y_ - surfBackground_->h);
    }

    if (y_ > WHEIGHT)
    {
        y_ = y_ - surfBackground_->h;
    }

    CSurface::OnDraw(surfDisplay, surfBackground_, x_, y_);
}

void CBackground::onAnimate()
{
    y_ += BACKGROUND_SCROLL_SPEED * CFPS::FPSControl.getSpeedFactor();
}