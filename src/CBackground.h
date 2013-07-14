//
//  CBackground.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-30.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CBackground__
#define __birdyShmup__CBackground__

#include <SDL.h>

#include "Defines.h"
#include "CSurface.h"
#include "CFPS.h"
#include "CEntity.h"

class CBackground {
public:
    CBackground();
    ~CBackground();

    bool onLoad(const char* file);
    void onRender(SDL_Surface* surfDisplay);
    void onAnimate();

	void setBackgroundLevel(int backgroundLevel);

private:
    SDL_Surface* surfBackground_;

	int backgroundLevel_;

    float x_;
    float y_;
	
	float tempX_; // Keep track of last player position
	float tempY_; // Keep track of last player position
	

};

#endif /* defined(__birdyShmup__CBackground__) */
