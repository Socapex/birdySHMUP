#ifndef CPLAYER_H
#define CPLAYER_H

#include "FilePaths.h"

#include "CEntity.h"
#include "CBulletSpawner.h"

class CPlayer : public CEntity {
public:
    CPlayer();
    ~CPlayer();

    bool onLoad(const char* file, const int width, const int height,
                const int maxFrames);
    void movePlayer();

    void onLoop(CPlayer* player);
    void onRender(SDL_Surface* surfDisplay);
    void onCleanup();
    void onAnimate();
    bool onCollision(CEntity* Entity);

    void shoot();

    int getPlayerPoints() const;

    void setMoveLeft(const bool move);
    void setMoveRight(const bool move);
    void setMoveUp(const bool move);
    void setMoveDown(const bool move);
    void setShooting(const bool shoot);
    void setPlayerPoints(const int points);

private:
    CParticles* feuDuCul_;
    CParticles* feuDuCul2_;

    CBulletSpawner bullets1_;

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

    int shootLastTime_;

    int playerPoints_;

};

#endif // CPLAYER_H
