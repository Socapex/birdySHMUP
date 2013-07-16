//
//  CMainMenu.cpp
//  birdyShmup
//
//  Created by Benjamin Brodeur Mathieu on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CMainMenu.h"

CMainMenu::CMainMenu()
{
    x_ = 0;
    y_ = 0;
}

CMainMenu::~CMainMenu()
{
    SDL_FreeSurface(surfMainMenu_);
}

bool CMainMenu::onLoad(const char* file)
{
    if ((surfMainMenu_ = CSurface::onLoad(file)) == NULL) return false;
    // ADD BUTTONS HERE
    if(playButton_.onLoad(filePath_.Files["playButton1Path"].c_str()) == false) return false;
    playButton_.setX((WWIDTH/2-playButton_.getWidth()/2));
    playButton_.setY((WHEIGHT/2-playButton_.getHeight()/2));

    return true;
}

void CMainMenu::onRender(SDL_Surface* surfDisplay)
{
    if (surfMainMenu_ == NULL || surfDisplay == NULL) return;

    onAnimate();
    CSurface::OnDraw(surfDisplay, surfMainMenu_, x_, y_);
    // ADD BUTTONS HERE
    playButton_.onDraw(surfDisplay);
}

void CMainMenu::onAnimate()
{
    //TODO catch event click on button and do stuff
    //TODO animation background (if we want to)
}