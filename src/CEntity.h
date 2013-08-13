#ifndef CENTITY_H
#define CENTITY_H

#include <vector>

#include "CAnimation.h"
#include "CSurface.h"
#include "CCamera.h"
#include "CFPS.h"
#include "CParticles.h"

class CPlayer;

enum {ENTITY_TYPE_GENERIC = 0, ENTITY_TYPE_PLAYER, ENTITY_TYPE_ENEMY1};
enum {ENTITY_FLAG_NONE = 0, ENTITY_FLAG_GRAVITY = 0x00000001,
        ENTITY_FLAG_GHOST = 0x00000002, ENTITY_FLAG_MAPONLY = 0x00000004};

class CEntity {
public:
    CEntity();
    virtual ~CEntity();

    bool collides(const float oX, const float oY, const float oW, const float oH);
    bool checkLife();


    virtual bool onLoad(const char* file, const int width, const int height,
                        const int maxFrames);
    virtual void onLoop(CPlayer* player);
    virtual void onRender(SDL_Surface* surfDisplay);
    virtual void onAnimate();
    virtual bool onCollision(CEntity* entity);

    static std::vector<CEntity*> entityList;

    void setX(const float x);
    void setY(const float y);
    void setWidth(const int width);
    void setHeight(const int height);
    void setAnimeState(const int state);
    void setType(const int type);
    void setDead(const bool dead);
    void setFlags(const int flags);
    virtual void setHealth(const float health);
    void setLife(const int life);

    float getX() const;
    float getY() const;
    int getWidth() const;
    int getHeight() const;
    int getType() const;
    bool getDead() const;
    int getFlags() const;
    float getHealth() const;
    int getLife() const;


protected:
    bool checkCollision(const float newX, const float newY);
    bool checkEntityCollision(CEntity* entity, const float newX, const float newY);

    CAnimation* animControl;
    SDL_Surface* surfaceEntity_;

    float x_;
    float y_;
    
    int width_;
    int height_;

    float health_;
    float maxHealth_;
    int life_;

    int currentFrameCol;
    int currentFrameRow;

    int colX;
    int colY;
    int colWidth;
    int colHeight;

private:

    int type_;
    bool dead_;
    int flags_;

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
