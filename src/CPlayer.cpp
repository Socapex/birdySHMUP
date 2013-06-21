#include "CPlayer.h"

CPlayer::CPlayer()
{
    moveLeft_ = false;
    moveRight_ = false;
    moveUp_ = false;
    moveDown_ = false;

    speedX = 0;
    speedY = 0;
    accelX = 0;
    accelY = 0;

    maxSpeedX_ = 5;
    maxSpeedY_ = 5;
}
CPlayer::~CPlayer()
{}



// FONCTION SPECIFIC
bool CPlayer::OnLoad(const char* file, const int width, const int height, const int maxFrames)
{
    if (CEntity::OnLoad(file, width, height, maxFrames) == false) return false;
    return true;
}

void CPlayer::stopMove()
{

    accelX = accelY = 0;
    speedX = speedY = 0;

    // Je ne pense pas utiliser d'acceleration... On va voir
    // if (speedX > 0) accelX = -1;
    // if (speedX < 0) accelX = 1;

    // if (speedX < 2.0f && speedX > -2.0f)
    // {
    //     accelX = 0;
    //     speedX = 0;
    // }
}


void CPlayer::OnMove(const float moveX_, const float moveY_)
{
    if (moveX_ == 0 && moveY_ == 0) return;

    double newX = 0;
    double newY = 0;

    // Pas modifier les const!!!
    float moveX = moveX_;
    float moveY = moveY_;

    moveX *= CFPS::FPSControl.getSpeedFactor();
    moveY *= CFPS::FPSControl.getSpeedFactor();

    if (moveX != 0)
    {
        if (moveX >= 0) newX = CFPS::FPSControl.getSpeedFactor();
        else newX = -CFPS::FPSControl.getSpeedFactor();
    }

    if (moveY != 0)
    {
        if (moveY >= 0) newY = CFPS::FPSControl.getSpeedFactor();
        else newY = -CFPS::FPSControl.getSpeedFactor();
    }

    while(true)
    {
        if (flags_ & ENTITY_FLAG_GHOST)
        {
            // We don't care about collisions, but still send events to other entities
            //posValid((int)(newX + x_), (int)(newY + y_));

            x_ += newX;
            y_ += newY;
        }
        else
        {
            //if (posValid((int)(x_ + newX), (int)y_)) x_ += newX;
            //else speedX = 0;

            //if (posValid((int)x_, (int)(y_ + newY))) y_ += newY;
            //else speedY = 0;
        }

        moveX += -newX;
        moveY += -newY;

        if (newX > 0 && moveX <= 0) newX = 0;
        if (newX < 0 && moveX >= 0) newX = 0;

        if(newY > 0 && moveY <= 0) newY = 0;
        if(newY < 0 && moveY >= 0) newY = 0;

        if(moveX == 0) newX = 0;
        if(moveY == 0) newY = 0;

        if(moveX == 0 && moveY == 0) break;
        if(newX == 0 && newY == 0) break;
    }
}












// FONCTIONS OVERLOADED
void CPlayer::OnLoop()
{
    if (flags_ & ENTITY_FLAG_GRAVITY) accelY = 0.75f;

    // We're not moving
    if (moveLeft_ == false && moveRight_ == false
        && moveUp_ == false && moveDown_ == false) stopMove();

    else
    {

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

        x_ += speedX;
        y_ += speedY;

    }



    // On verra si on garde cette fonction OnMove
    //OnMove(speedX, speedY);
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
    if (speedX != 0) Anim_Control.setMaxFrames(0);
    else Anim_Control.setMaxFrames(0);

    CEntity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity* Entity)
{
    return true;
}










// PRIVATE FUNCTIONS
bool CPlayer::posValid(const int newX, const int newY)
{
    bool return_ = true;

    if (flags_ & ENTITY_FLAG_MAPONLY) {}
    else
    {
        for (int i = 0; i < entityList.size(); ++i)
        {
            if (posValidEntity(entityList[i], newX, newY) == false) return_ = false;

        }
    }

    return return_;
}

bool CPlayer::posValidEntity(CEntity* entity, const int newX, const int newY)
{
    if (this != entity && entity != NULL && entity->dead_ == false
        && entity->flags_ ^ ENTITY_FLAG_MAPONLY
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
