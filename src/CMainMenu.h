//
//  CMainMenu.h
//  birdyShmup
//
//  Created by Benjamin Brodeur Mathieu on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CMainMenu__
#define __birdyShmup__CMainMenu__

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "Defines.h"
#include "CSurface.h"
#include "CButton.h"
#include "CFPS.h"
#include "FilePaths.h"


class CMainMenu {
public:
    CMainMenu();
    ~CMainMenu();

    bool onLoad(const char* file);
    void onRender(SDL_Surface* surfDisplay);
    void onAnimate();
    int getActiveButtonID();
    void previousActiveButtonID();
    void nextActiveButtonID();

private:
    
    SDL_Surface* surfMainMenu_;
    int activeButtonID_;
    CButton playButton_;
    CButton playButtonActive_;
    CButton exitButton_;
    CButton exitButtonActive_;
    std::vector<CButton*> buttons_;
    FilePaths filePath_;

    float x_;
    float y_;
};

#endif /* defined(__birdyShmup__CMainMenu__) */
