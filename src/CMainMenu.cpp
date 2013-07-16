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
    // surfMainMenu_
    x_ = 0;
    y_ = 0;

    // buttons_
    buttons_.push_back(&playButton_);
    playButton_.setID(buttons_.size() - 1); //So that ID equals position in buttons_
    activeButtonID_ = 0;
    //****** add other buttons here ******//
    buttons_.push_back(&exitButton_);
    exitButton_.setID(buttons_.size() - 1);
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

    if(playButtonActive_.onLoad(filePath_.Files["playButton2Path"].c_str()) == false) return false;
    playButtonActive_.setX(playButton_.getX());
    playButtonActive_.setY(playButton_.getY());

    if(exitButton_.onLoad(filePath_.Files["exitButton1Path"].c_str()) == false) return false;
    exitButton_.setX(playButton_.getX());
    exitButton_.setY(playButton_.getY() + playButton_.getHeight() + 30); //  30 pixels sous play

    if(exitButtonActive_.onLoad(filePath_.Files["exitButton2Path"].c_str()) == false) return false;
    exitButtonActive_.setX(exitButton_.getX());
    exitButtonActive_.setY(exitButton_.getY()); //  30 pixels sous play

    return true;
}

void CMainMenu::onRender(SDL_Surface* surfDisplay)
{
    if (surfMainMenu_ == NULL || surfDisplay == NULL) return;

    onAnimate();
    CSurface::OnDraw(surfDisplay, surfMainMenu_, x_, y_);
    
    // ADD BUTTONS HERE
            for(int i = 0; i < buttons_.size(); ++i)
            {
                if( i != activeButtonID_)
                {
                    buttons_[i]->onDraw(surfDisplay);
                }
                else
                {
                    switch (activeButtonID_)
                    {
                        case 0: 
                            playButtonActive_.onDraw(surfDisplay);
                            break;
                        case 1:
                            exitButtonActive_.onDraw(surfDisplay);
                            break;
                    }
                }
            }
}

void CMainMenu::onAnimate()
{
    //TODO animation background (if we want to)
}

void CMainMenu::previousActiveButtonID()
{
    if(activeButtonID_ != 0)
    {
        --activeButtonID_;
    }
}

void CMainMenu::nextActiveButtonID()
{
    if(activeButtonID_ != buttons_.size() - 1)
    {
        ++activeButtonID_;
    }       
}


int CMainMenu::getActiveButtonID()
{
    return activeButtonID_;
}