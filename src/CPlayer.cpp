#include "CPlayer.h"

CPlayer::CPlayer()
{
    moveLeft_ = false;
    moveRight_ = false;
    moveUp_ = false;
    moveDown_ = false;

    x_ = PLAYER_START_XPOSITION;
    y_ = PLAYER_START_YPOSITION;

    speedX = 0;
    speedY = 0;
    accelX = 0;
    accelY = 0;

    maxSpeedX_ = PLAYER_SPEED;
    maxSpeedY_ = PLAYER_SPEED;

    life_ = PLAYER_LIFE;


}
CPlayer::~CPlayer()
{}



// FONCTION SPECIFIC
bool CPlayer::OnLoad(const char* file, const int width, const int height,
                     const int maxFrames)
{
    if (CEntity::OnLoad(file, width, height, maxFrames) == false) return false;


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

    posValid(x_ + speedX, y_ + speedY);

    x_ += speedX;
    y_ += speedY;
}

void CPlayer::checkLife()
{
    if (life_ <= 0)
    {
        setDead(true);
        // TODO: Explode player and consume life or show game over.
    }

}











// FONCTIONS OVERLOADED
void CPlayer::OnLoop()
{

    checkLife();
    movePlayer();

    //feuDuCul_->setX(x_ + 32);
    //feuDuCul_->setY(y_ + 96);
    feuDuCul2_->setX(x_ + 32);
    feuDuCul2_->setY(y_ + 96);

    // On verra si on garde cette fonction OnMove
    CEntity::OnLoop();
}

void CPlayer::OnRender(SDL_Surface* Surf_Display)
{
    CEntity::OnRender(Surf_Display);
}

void CPlayer::OnCleanup()
{
    CEntity::OnCleanup();
}

void CPlayer::OnAnimate()
{
    // ANIMATIONS DU JOUEUR
    // TODO: setMaxFrames dans OnInit... ou ca A du sens ;)
    if (speedX != 0) animControl->setMaxFrames(0);
    else animControl->setMaxFrames(0);

    CEntity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity* Entity)
{
    if (Entity->getType() == ENTITY_TYPE_ENEMY1 && life_ > 0)
    {
        life_ -= (1 * CFPS::FPSControl.getSpeedFactor());
        //CParticles explody(255, 255, 0, x_, y_, 5, 8, 1, 10, 100, rand() % 20 + 1);
        CParticles* explody2 = new CParticles("explosion3", x_, y_, 100, 1000, 1, 10);
    }

    return true;
}










// PRIVATE FUNCTIONS
bool CPlayer::posValid(const int newX, const int newY)
{
    bool return_ = true;

    if (getFlags() & ENTITY_FLAG_MAPONLY) {}
    else
    {
        for (int i = 0; i < entityList.size(); ++i)
        {
            if (posValidEntity(entityList[i], newX, newY) == false)
                return_ = false;

        }
    }

    return return_;
}

bool CPlayer::posValidEntity(CEntity* entity, const int newX, const int newY)
{
    if (this != entity && entity != NULL && entity->getDead() == false
        && entity->getFlags() ^ ENTITY_FLAG_MAPONLY
        && entity->collides(newX + colX, newY + colY, width_ - colWidth - 1,
                            height_ - colHeight - 1) == true)
    {
        CEntityCol entityCol;
        entityCol.entityA = this;
        entityCol.entityB = entity;

        CEntityCol::EntityColList.push_back(entityCol);

        return false;
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
