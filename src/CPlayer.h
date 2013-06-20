#ifndef CPLAYER_H
#define CPLAYER_H

#include "CEntity.h"

class CPlayer : public CEntity {
public:
    CPlayer();
    ~CPlayer();

    bool OnLoad(const char* file, const int width, const int height, const int maxFrames);

    void OnLoop();
    void OnRender(SDL_Surface* Surf_Display);
    void OnCleanup();
    void OnAnimate();
    void OnCollision(CEntity* Entity);
};

#endif // CPLAYER_H
