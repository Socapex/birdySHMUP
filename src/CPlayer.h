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
    void setHealth(const float health);
    void setCurrentBullet(const int bull);

    void addLife(){life_++;}

private:
    void updateAccel();
    void updateSpeed();
    bool isInScreenX(float newX);
    bool isInScreenY(float newY);

    CParticles* feuDuCul_;
    CParticles* collisionExplosion_;

    CBulletSpawner* bullets1_;
    CBulletSpawner* bullets2_;
    CBulletSpawner* bullets3_;

    bool moveLeft_;
    bool moveRight_;
    bool moveUp_;
    bool moveDown_;
    bool shooting_;

    float speedX_;
    float speedY_;
    float accelX_;
    float accelY_;


    float maxSpeedX_;
    float maxSpeedY_;

    unsigned int shootLastTime_;

    unsigned int currentBullets_;

    int playerPoints_;

};

#endif // CPLAYER_H
