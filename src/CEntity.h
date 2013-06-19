#ifndef CENTITY_H
#define CENTITY_H

#include <vector>

#include "CAnimation.h"
#include "CSurface.h"

class CEntity {
public:
    CEntity();
    virtual ~CEntity();

    void setX(const float x);
    void setY(const float y);
    void setWidth(const int width);
    void setHeight(const int height);
    void setAnimeState(const int state);


    virtual bool OnLoad(const char* file, int width, int height, int maxFrames);
    virtual void OnLoop();
    virtual void OnRender(SDL_Surface* Surf_Display);
    virtual void OnCleanup();

    static std::vector<CEntity*> entityList;

protected:
    CAnimation Anim_Control;
    SDL_Surface* Surf_Entity;

private:
    // TODO: Rendre ces parametres private?
    float x_;
    float y_;
    int width_;
    int height_;
    int animeState_;

};

#endif // CENTITY_H
