#include "CPlayer.h"

CPlayer::CPlayer()
{
    moveLeft_ = false;
    moveRight_ = false;
    moveUp_ = false;
    moveDown_ = false;
    shooting_ = false;

    x_ = PLAYER_START_XPOSITION;
    y_ = PLAYER_START_YPOSITION;

    speedX = 0;
    speedY = 0;
    accelX = 0;
    accelY = 0;

    maxSpeedX_ = PLAYER_SPEED;
    maxSpeedY_ = PLAYER_SPEED;

    life_ = PLAYER_LIFE;

    // Pre-generate bullets
    for (int i = 0; i < 100; ++i)
    {
        CBullet bullet;
        bulletList_.push_back(bullet);
    }

}
CPlayer::~CPlayer()
{}



// FONCTION SPECIFIC
bool CPlayer::onLoad(const char* file, const int width, const int height,
                     const int maxFrames)
{
    if (CEntity::onLoad(file, width, height, maxFrames) == false) return false;




    // Bullets
    std::string bulletPath = "img/bullet.png";
    
#ifdef MACTERMINAL
    // Rien faire, on n'as pas besoin de changer le path lorsqu'on compile du
    // terminal sur mac.
#elif __APPLE__
    bulletPath.insert(0, "birdyShmup.app/Contents/Resources/");
#elif __WIN32__
    
#endif

    for (int i = 0; i < bulletList_.size(); ++i)
    {
        bulletList_[i].onLoad(bulletPath.c_str(), 16, 16, 0);
    }

//    feuDuCul_ = new CParticles("explosion3", x_ + 32, y_ + 64, 10, 1, 1000,
//                               10, "firefowrks", true);
    feuDuCul2_ = new CParticles(255, 255, 0, x_ + 32, y_ + 64, 5, 8, 100, 1000, 100,
                                10, "fireworks", true);

    return true;
}

void CPlayer::movePlayer()
{
    if (getFlags() & ENTITY_FLAG_GRAVITY) accelY = 0.75f;

    // We're not moving
    if (moveLeft_ == false && moveRight_ == false) speedX = 0;

    if (moveUp_ == false && moveDown_ == false) speedY = 0;

    if (moveLeft_) speedX = -maxSpeedX_; //accelX = -0.5;
    else if (moveRight_) speedX = maxSpeedX_; //accelX = 0.5;

    if (moveUp_) speedY = -maxSpeedY_;
    else if (moveDown_) speedY = maxSpeedY_;

    // if (speedX > maxSpeedX_) speedX = maxSpeedX_;
    // if (speedX < -maxSpeedX_) speedX = -maxSpeedX_;
    // if (speedY > maxSpeedY_) speedY = maxSpeedY_;
    // if (speedY < -maxSpeedY_) speedY = -maxSpeedY_;

    speedX *= CFPS::FPSControl.getSpeedFactor();
    speedY *= CFPS::FPSControl.getSpeedFactor();

    checkCollision(x_ + speedX, y_ + speedY);

    if (x_ + speedX > 0 && x_ + speedX + getWidth() < WWIDTH) x_ += speedX;
    if (y_ + speedY > 0 && y_ + speedY + getHeight() < WHEIGHT) y_ += speedY;
}

bool CPlayer::checkLife()
{
    if (life_ <= 0)
    {
        setDead(true);
        // TODO: Explode player and consume life or show game over.


        return false;
    }

    return true;

}

void CPlayer::shoot()
{
    for (int i = 0; i < bulletList_.size(); ++i)
    {
        if (bulletList_[i].getDead())
        {
            bulletList_[i].shoot(x_, y_);
            bulletList_[i + 1].shoot(x_ + getWidth() - bulletList_[i].getWidth(),
                                     y_);
            break;
        }
    }
}

















// FONCTIONS OVERLOADED
void CPlayer::onLoop()
{

    if (checkLife())
    {
        movePlayer();

        if (shooting_) shoot();

        //feuDuCul_->setX(x_ + 32);
        //feuDuCul_->setY(y_ + 96);
        feuDuCul2_->setX(x_ + 32);
        feuDuCul2_->setY(y_ + 96);

        CEntity::onLoop();
    }
}

void CPlayer::onRender(SDL_Surface* surfDisplay)
{
    // Render bullets
    for (int i = 0; i < bulletList_.size(); ++i)
    {
        if (!bulletList_[i].getDead()) bulletList_[i].onRender(surfDisplay);
    }

    if (!getDead()) CEntity::onRender(surfDisplay);
}

void CPlayer::onCleanup()
{
    CEntity::onCleanup();
}

void CPlayer::onAnimate()
{
    // ANIMATIONS DU JOUEUR
    // TODO: setMaxFrames dans OnInit... ou ca A du sens ;)
    if (speedX != 0) animControl->setMaxFrames(0);
    else animControl->setMaxFrames(0);

    CEntity::onAnimate();
}

bool CPlayer::onCollision(CEntity* Entity)
{
    if (Entity->getType() == ENTITY_TYPE_ENEMY1 && life_ > 0)
    {
        life_ -= (1 * CFPS::FPSControl.getSpeedFactor());
        //CParticles explody(255, 255, 0, x_, y_, 5, 8, 1, 10, 100, rand() % 20 + 1);
        CParticles* explody2 = new CParticles("explosion3", x_, y_, 100, 1000, 1, 10);
    }

    return true;
}




















// GETTERS ET SETTERS
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
