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
#include <string>

class CEntity;


class CParticles {
public:
    CParticles();
    CParticles(int R, int G, int B, int x, int y, int width, int height,
               float emitSpeed, uint lifeTime, uint quantity, uint spread);
    CParticles(std::string type, int x, int y, float emitSpeed,
               uint lifeTime, uint quantity, uint spread);
    ~CParticles();

    void onLoop();
    void onRender(SDL_Surface* surfDisplay);

    static std::vector<CParticles> particleList;

private:
    std::vector<SDL_Rect> rectanglesToDraw_;
    std::vector<std::pair<SDL_Rect, int>> rectanglesDrawing_;
    std::vector<CEntity> surfacesToDraw_;
    std::vector<std::pair<CEntity, uint>> surfacesDrawing_;
    int x_, y_, width_, height_, density_, quantity_;
    int startTime;
    int R_, G_, B_;
    uint lifeTime_, spread_;
    float emitSpeed_;
};

#endif /* defined(__birdyShmup__CParticles__) */
