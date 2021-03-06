 #include "CPlayer.h"

CPlayer::CPlayer()
{
    setType(ENTITY_TYPE_PLAYER);

    moveLeft_ = false;
    moveRight_ = false;
    moveUp_ = false;
    moveDown_ = false;
    shooting_ = false;

    x_ = PLAYER_START_XPOSITION;
    y_ = PLAYER_START_YPOSITION;

    speedX_ = 0;
    speedY_ = 0;
    accelX_ = 0;
    accelY_ = 0;

    maxSpeedX_ = PLAYER_SPEED;
    maxSpeedY_ = PLAYER_SPEED;

    health_ = maxHealth_ = PLAYER_LIFE;
    life_ = NB_STARTING_LIVES;

    playerPoints_ = 0;

    shootLastTime_ = SDL_GetTicks();

    bullets1_ = NULL;
    feuDuCul_ = NULL;
    collisionExplosion_ = NULL;

    currentBullets_ = 0;
    bullets1_ = new CBulletSpawner("player1");
    bullets2_ = new CBulletSpawner("player2");
    bullets3_ = new CBulletSpawner("player3");

    feuDuCul_ = new CParticles(255, 255, 0, x_ + 32, y_ + 64,
                               5, 8, 100, 1000, 100,
                                10, "fireworks", true);
    collisionExplosion_ = new CParticles("explosion3", x_, y_,
                                         100, 1000, 1, 10);

}
CPlayer::~CPlayer()
{
    if (bullets1_ != NULL) delete bullets1_;
    if (feuDuCul_ != NULL) delete feuDuCul_;
    if (collisionExplosion_ != NULL) delete collisionExplosion_;
}



// FONCTION SPECIFIC
bool CPlayer::onLoad(const char* file, const int width, const int height,
                     const int maxFrames)
{
    if (CEntity::onLoad(file, width, height, maxFrames) == false) return false;

    return true;
}

void CPlayer::movePlayer()
{
    updateAccel();
    updateSpeed();

    float newX = x_ + speedX_ * CFPS::FPSControl.getSpeedFactor();
    float newY = y_ + speedY_ * CFPS::FPSControl.getSpeedFactor();

    checkCollision(newX, newY);

    if (isInScreenX(newX))
        x_ = newX;
    if (isInScreenY(newY))
        y_ = newY;
}

void CPlayer::updateAccel()
{
    if(moveLeft_)
        accelX_ = -20.0f;
    else if(moveRight_)
        accelX_ = 20.0f;
    else
        accelX_ = 0.0f;

    if(moveUp_)
        accelY_ = -20.0f;
    else if(moveDown_)
        accelY_ = 20.0f;
    else
        accelY_ = 0.0f;
    
    if (getFlags() & ENTITY_FLAG_GRAVITY)
        accelY_ = 0.75f;
}

void CPlayer::updateSpeed()
{
    if (moveLeft_ == false && moveRight_ == false)
        speedX_ = 0;
    else
        speedX_ += accelX_;

    if (moveUp_ == false && moveDown_ == false)
        speedY_ = 0;
    else
        speedY_ += accelY_;

    if (speedX_ > maxSpeedX_)
        speedX_ = maxSpeedX_;
    else if (speedX_ < -maxSpeedX_)
        speedX_ = -maxSpeedX_;

    if (speedY_ > maxSpeedY_)
        speedY_ = maxSpeedY_;
    else if (speedY_ < -maxSpeedY_)
        speedY_ = -maxSpeedY_;
}

bool CPlayer::isInScreenX(float newX)
{
   return newX > 0 && newX + getWidth() < WWIDTH;
}

bool CPlayer::isInScreenY(float newY)
{
    return newY > 0 && newY + getHeight() < WHEIGHT;
}


void CPlayer::shoot()
{
    if (currentBullets_ == 0)
    {
        if (shootLastTime_ + PLAYER_BULLET1_SHOOT_DELAY <= SDL_GetTicks())
        {
            shootLastTime_ = SDL_GetTicks();
            bullets1_->shoot(x_ + 20, y_);
            bullets1_->shoot(x_ + getWidth() - bullets1_->getBulletWidth() - 20,
                             y_);
        }
    }

    else if (currentBullets_ == 1)
    {
        if (shootLastTime_ + PLAYER_BULLET2_SHOOT_DELAY <= SDL_GetTicks())
        {
            shootLastTime_ = SDL_GetTicks();
            bullets2_->shoot(x_ - 130, y_);
            //bullets2_->shoot(x_ + getWidth() - bullets1_->getBulletWidth() - 20,
            //                 y_);
        }
    }

    else if (currentBullets_ == 2)
    {
        if (shootLastTime_ + PLAYER_BULLET3_SHOOT_DELAY <= SDL_GetTicks())
        {
            shootLastTime_ = SDL_GetTicks();
            bullets3_->shoot(x_ - 30, y_);
            //bullets3_->shoot(x_ + getWidth() - bullets1_->getBulletWidth() - 20,
            //                 y_);
        }
    }

}

















// FONCTIONS OVERLOADED
void CPlayer::onLoop(CPlayer* player)
{

    if (checkLife())
    {
        movePlayer();

        if (shooting_) shoot();

        //feuDuCul_->setX(x_ + 32);
        //feuDuCul_->setY(y_ + 96);
        feuDuCul_->setX(x_ + 64);
        feuDuCul_->setY(y_ + 150);
        feuDuCul_->play(x_ + 32, y_ + 96);
    }
    else
    {
        // Player is dead
        setDead(true);

        if (life_ > 0) --life_;

        // TODO: Player death
    }
}

void CPlayer::onRender(SDL_Surface* surfDisplay)
{
    bullets1_->onRender(surfDisplay);
    bullets2_->onRender(surfDisplay);
    bullets3_->onRender(surfDisplay);
    
    //feuDuCul_->onRender(surfDisplay);
    collisionExplosion_->onRender(surfDisplay);

    if (!getDead()) CEntity::onRender(surfDisplay);
}


void CPlayer::onAnimate()
{
    // ANIMATIONS DU JOUEUR
    // TODO: setMaxFrames dans onInit... ou ca A du sens ;)
    if (speedX_ != 0) animControl->setMaxFrames(0);
    else animControl->setMaxFrames(0);

    CEntity::onAnimate();
}

bool CPlayer::onCollision(CEntity* Entity)
{
    if (Entity->getType() == ENTITY_TYPE_ENEMY1 && life_ > 0)
    {
        health_ -= (1 * CFPS::FPSControl.getSpeedFactor());
        
        collisionExplosion_->play(x_, y_);
    }

    return true;
}




















// GETTERS ET SETTERS
int CPlayer::getPlayerPoints() const
{
    return playerPoints_;
}


void CPlayer::setMoveLeft(const bool move)
{
    moveLeft_ = move;
}

void CPlayer::setMoveRight(const bool move)
{
    moveRight_ = move;
}

void CPlayer::setMoveUp(const bool move)
{
    moveUp_ = move;
}

void CPlayer::setMoveDown(const bool move)
{
    moveDown_ = move;
}

void CPlayer::setShooting(const bool shoot)
{
    shooting_ = shoot;
}

void CPlayer::setPlayerPoints(const int points)
{
    playerPoints_ = points;
}

void CPlayer::setHealth(const float health)
{
    if(health > 0)
        health_ = health;
    else if (life_ > 1)
    {
        life_--;
        health_ = maxHealth_;
    }
    else
    {
        health_ = 0;
        life_ = 0;
    }
}

void CPlayer::setCurrentBullet(const int bull)
{
    currentBullets_ = bull;
}
