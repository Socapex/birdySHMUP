#ifndef CENTITY_H
#define CENTITY_H

#include <vector>

#include "CAnimation.h"
#include "CSurface.h"
#include "CCamera.h"
#include "CFPS.h"

enum {ENTITY_TYPE_GENERIC = 0, ENTITY_TYPE_PLAYER};
enum {ENTITY_FLAG_NONE = 0, ENTITY_FLAG_GRAVITY = 0x00000001,
        ENTITY_FLAG_GHOST = 0x00000002, ENTITY_FLAG_MAPONLY = 0x00000004};

class CEntity {
public:
    CEntity();
    virtual ~CEntity();

    bool collides(const int oX, const int oY, const int oW, const int oH);

    virtual bool OnLoad(const char* file, const int width, const int height, const int maxFrames);
    virtual void OnLoop();
    virtual void OnRender(SDL_Surface* Surf_Display);
    virtual void OnCleanup();
    virtual void OnAnimate();
    virtual bool OnCollision(CEntity* entity);

    static std::vector<CEntity*> entityList;

    void setX(const float x);
    void setY(const float y);
    void setWidth(const int width);
    void setHeight(const int height);
    void setAnimeState(const int state);

    // TODO: make private
    float x_;
    float y_;

    int type_;
    bool dead_;
    int flags_;

    int width_;
    int height_;

protected:
    CAnimation Anim_Control;
    SDL_Surface* Surf_Entity;

    int currentFrameCol;
    int currentFrameRow;

    int colX;
    int colY;
    int colWidth;
    int colHeight;

private:


    int animeState_;




};

class CEntityCol {
public:
    CEntityCol();
    ~CEntityCol();

    CEntity* entityA;
    CEntity* entityB;

    static std::vector<CEntityCol> EntityColList;

};

#endif // CENTITY_H
