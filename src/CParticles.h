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
#include <typeinfo>

#include "FilePaths.h"


class CEntity;


class CParticles {
public:
    CParticles();
    CParticles(const CParticles& part);
    CParticles(int R, int G, int B, int x, int y, int width, int height,
               float emitSpeed, unsigned int lifeTime, unsigned int quantity,
               unsigned int spread, std::string animationType = "random",
               bool follow = false);
    CParticles(std::string type, int x, int y, float emitSpeed,
               unsigned int lifeTime, unsigned int quantity, unsigned int spread,
               std::string animationType = "random", bool follow = false);
    ~CParticles();

    void play(const int x, const int y);

    void onLoop();
    void onRender(SDL_Surface* surfDisplay);

    bool getPlaying() const;

    void setX(const int x);
    void setY(const int y);

private:
    void createAnimation(std::string type);

    std::vector<SDL_Rect> rectanglesToDraw_;
    std::vector<std::pair<SDL_Rect, int> > rectanglesDrawing_;
    std::vector<CEntity*> surfacesToDraw_;
    std::vector<std::pair<CEntity*, unsigned int> > surfacesDrawing_;

    std::vector<float> speedX;
    std::vector<float> speedY;

    int x_, y_, width_, height_, density_, quantity_;
    int startTime_;
    int R_, G_, B_;
    unsigned int lifeTime_, spread_;
    float emitSpeed_;
    bool follow_;
    bool play_;
};







#endif /* defined(__birdyShmup__CParticles__) */
