//
//  CSplashScreen.h
//  birdyShmup
//
//  Created by Benjamin Brodeur Mathieu on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CSplashScreen__
#define __birdyShmup__CSplashScreen__

#include <SDL.h>

#include "Defines.h"
#include "CSurface.h"
#include "CFPS.h"

class CSplashScreen {
public:
    CSplashScreen();
    ~CSplashScreen();

    bool onLoad(const char* file);
    void onRender(SDL_Surface* surfDisplay);
    void onAnimate();

private:
    
    SDL_Surface* surfSplashScreen_;

    int x_;
    float y_;
    float alpha_;

};

#endif /* defined(__birdyShmup__CSplashScreen__) */
