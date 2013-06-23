//
//  CParticles.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-23.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__CParticles__
#define __birdyShmup__CParticles__

#include <SDL.h>
#include <vector>
#include <map>

class CParticles {
public:
    CParticles();
    CParticles(int R, int G, int B, int x, int y, int width, int height,
               float emitSpeed, uint lifeTime, uint quantity);
    CParticles(SDL_Surface* surface, int x, int y, float emitSpeed,
               float lifeTime, int density);
    ~CParticles();

    void onLoop();
    void onRender(SDL_Surface* surfDisplay);

    static std::vector<CParticles> particleList;

private:
    std::vector<SDL_Rect> rectanglesToDraw_;
    std::vector<std::pair<SDL_Rect, int>> rectanglesDrawing_;
    std::vector<SDL_Surface*> surfaceList_;
    SDL_Surface* surfaceParticle_;
    int x_, y_, density_, quantity_;
    int startTime;
    int R_, G_, B_;
    uint lifeTime_;
    float emitSpeed_;
};

#endif /* defined(__birdyShmup__CParticles__) */
