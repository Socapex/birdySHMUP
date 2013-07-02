#ifndef CPLAYER_H
#define CPLAYER_H

#include "CEntity.h"
#include "CBullet.h"

class CPlayer : public CEntity {
public:
    CPlayer();
    ~CPlayer();

    bool onLoad(const char* file, const int width, const int height,
                const int maxFrames);
    void movePlayer();
    bool checkLife();

    void onLoop();
    void onRender(SDL_Surface* surfDisplay);
    void onCleanup();
    void onAnimate();
    bool onCollision(CEntity* Entity);

    void shoot();

    void setMoveLeft(const bool move);
    void setMoveRight(const bool move);
    void setMoveUp(const bool move);
    void setMoveDown(const bool move);
    void setShooting(const bool shoot);

private:
    std::vector<CBullet> bulletList_;

    CParticles* feuDuCul_;
    CParticles* feuDuCul2_;

    bool moveLeft_;
    bool moveRight_;
    bool moveUp_;
    bool moveDown_;
    bool shooting_;

    float speedX;
    float speedY;
    float accelX;
    float accelY;


    float maxSpeedX_;
    float maxSpeedY_;

};

#endif // CPLAYER_H
