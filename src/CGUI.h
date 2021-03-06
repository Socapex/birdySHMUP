//
//  CGUI.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-22.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef birdyShmup_CGUI_h
#define birdyShmup_CGUI_h



#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <sstream>

#include "Defines.h"
#include "FilePaths.h"

#include "CSurface.h"
#include "CPlayer.h"

class CGUI {
public:
    CGUI();
    ~CGUI();

    void getReady();

    void onLoop(CPlayer* player);
    void onRender(SDL_Surface* surfDisplay);
    

private:
    SDL_Rect healthBar_, healthBarBackground_;
    std::vector<SDL_Rect> vLives_;

    SDL_Surface* points_;
    SDL_Surface* getReadySurface_;
    SDL_Surface* fps_;

    TTF_Font* pointFont_;
    TTF_Font* getReadyFont_;

    SDL_Color black;
    SDL_Color white;

    std::string pointText_;

    bool getReadyPlaying;
    unsigned int getReadyTime;
    int getReadyCounter;

    FilePaths Path;
    

};

#endif
