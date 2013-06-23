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

#include "Defines.h"
#include "CSurface.h"
#include "CPlayer.h"

class CGUI {
public:
    CGUI();
    ~CGUI();

    void onLoop(CPlayer* player);
    void onRender(SDL_Surface* surfDisplay);

    static CGUI gUI;
    

private:
    SDL_Rect healthBar_, healthBarBackground_;

    

};

#endif
