//
//  CSplashScreen.cpp
//  birdyShmup
//
//  Created by Benjamin Brodeur Mathieu on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CSplashScreen.h"

CSplashScreen::CSplashScreen()
{
    x_ = 0;
    y_ = 0;
    alpha_ = 0;
}

CSplashScreen::~CSplashScreen()
{
    SDL_FreeSurface(surfSplashScreen_);
}

bool CSplashScreen::onLoad(const char* file)
{
    if ((surfSplashScreen_ = CSurface::onLoad(file)) == NULL) return false;

    return true;
}

void CSplashScreen::onRender(SDL_Surface* surfDisplay)
{
    if (surfSplashScreen_ == NULL || surfDisplay == NULL) return;

    onAnimate();
    CSurface::OnDraw(surfDisplay, surfSplashScreen_, x_, y_);
}

void CSplashScreen::onAnimate()
{
    ++alpha_;

    if (alpha_ < 256)
    {
        SDL_SetAlpha(surfSplashScreen_, SDL_SRCALPHA, 50);  
    }
}