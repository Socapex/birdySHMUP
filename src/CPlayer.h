#ifndef CPLAYER_H
#define CPLAYER_H

#include "CEntity.h"

class CPlayer : public CEntity {
public:
    CPlayer();
    ~CPlayer();

    bool OnLoad(const char* file, const int width, const int height,
                const int maxFrames);
    void stopMove();
    void OnMove(const float moveX_, const float moveY_);

    void OnLoop();
    void OnRender(SDL_Surface* Surf_Display);
    void OnCleanup();
    void OnAnimate();
    bool OnCollision(CEntity* Entity);

    void setMoveLeft(const bool move);
    void setMoveRight(const bool move);
    void setMoveUp(const bool move);
    void setMoveDown(const bool move);

private:
    bool posValid(const int newX, const int newY);
    bool posValidEntity(CEntity* entity, const int newX, const int newY);

    bool moveLeft_;
    bool moveRight_;
    bool moveUp_;
    bool moveDown_;

    float speedX;
    float speedY;
    float accelX;
    float accelY;


    float maxSpeedX_;
    float maxSpeedY_;

};

#endif // CPLAYER_H
