#include "CEntity.h"

std::vector<CEntity*> CEntity::entityList;

std::vector<CEntityCol> CEntityCol::EntityColList;

CEntity::CEntity()
{
    Surf_Entity = NULL;

    x_ = y_ = 0.0f;
    width_ = height_ = 0;
    animeState_ = 0;

    moveLeft_ = false;
    moveRight_ = false;

    type_ = ENTITY_TYPE_GENERIC;

    dead_ = false;
    flags_ = ENTITY_FLAG_GRAVITY;

    speedX = 0;
    speedY = 0;
    accelX = 0;
    accelY = 0;

    maxSpeedX_ = 5;
    maxSpeedY_ = 5;

    currentFrameCol = 0;
    currentFrameRow = 0;

    colX = 0;
    colY = 0;
    colWidth = 0;
    colHeight = 0;
}

CEntity::~CEntity()
{}


// FUNCTIONS


void CEntity::OnMove(const float moveX_, const float moveY_)
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
            posValid((int)(newX + x_), (int)(newY + y_));

            x_ += newX;
            y_ += newY;
        }
        else
        {
            if (posValid((int)(x_ + newX), (int)y_)) x_ += newX;
            else speedX = 0;

            if (posValid((int)x_, (int)(y_ + newY))) y_ += newY;
            else speedY = 0;
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

void CEntity::stopMove()
{
    if (speedX > 0) accelX = -1;
    if (speedX < 0) accelX = 1;

    if (speedX < 2.0f && speedX > -2.0f)
    {
        accelX = 0;
        speedX = 0;
    }
}

bool CEntity::collides(const int oX, const int oY, const int oW, const int oH)
{
    int left1, left2, right1, right2, top1, top2, bottom1, bottom2;

    int tX = (int)x_ + colX;
    int tY = (int)y_ + colY;

    left1 = tX;
    left2 = oX;

    right1 = left1 + width_ - 1 - colWidth;
    right2 = oX + oW - 1;

    top1 = tY;
    top2 = oY;

    bottom1 = top1 + height_ - 1 - colHeight;
    bottom2 = oY + oH - 1;

    if (bottom1 < top2) return false;
    if (top1 > bottom2) return false;
    if (right1 < left2) return false;
    if (left1 > right1) return false;

    return true;
}

bool CEntity::OnLoad(const char* file, const int width, const int height, const int maxFrames)
{
    if ((Surf_Entity = CSurface::OnLoad(file)) == NULL) return false;

    CSurface::Transparent(Surf_Entity, 255, 0, 255);

    this->setWidth(width);
    this->setHeight(height);
    Anim_Control.setMaxFrames(maxFrames);
    return true;
}

void CEntity::OnLoop()
{
    // We;re not moving
    if (moveLeft_ == false && moveRight_ == false) stopMove();

    if (moveLeft_) accelX = -0.5;
    else if (moveRight_) accelX = 0.5;

    if (flags_ & ENTITY_FLAG_GRAVITY) accelY = 0.75f;

    speedX += accelX * CFPS::FPSControl.getSpeedFactor();
    speedY += accelY * CFPS::FPSControl.getSpeedFactor();

    if (speedX > maxSpeedX_) speedX = maxSpeedX_;
    if (speedX < -maxSpeedX_) speedX = -maxSpeedX_;
    if (speedY > maxSpeedY_) speedY = maxSpeedY_;
    if (speedY < -maxSpeedY_) speedY = -maxSpeedY_;

    Anim_Control.onAnimate();
    OnMove(speedX, speedY);
}

void CEntity::OnRender(SDL_Surface* Surf_Display)
{
    if (Surf_Entity == NULL || Surf_Display == NULL) return;

    CSurface::OnDraw(Surf_Display, Surf_Entity, x_ - CCamera::CameraControl.getX(),
                    y_ - CCamera::CameraControl.getY(), currentFrameCol * width_,
                    (currentFrameRow + Anim_Control.getCurrentFrame()) * height_,
                    width_, height_);
}

void CEntity::OnCleanup()
{
    if (Surf_Entity) SDL_FreeSurface(Surf_Entity);

    Surf_Entity = NULL;
}

void CEntity::OnAnimate()
{
    if (moveLeft_) currentFrameCol = 0;
    else if (moveRight_) currentFrameRow = 0;

    Anim_Control.onAnimate();
}

void CEntity::OnCollision(CEntity* entity)
{}





// PRIVATE FUNCTIONS
bool CEntity::posValid(const int newX, const int newY)
{
    bool return_ = true;

    int startX = (newX + colX) / TILE_SIZE;
    int startY = (newY + colY) /TILE_SIZE;

    int endX = ((newX + colX) + width_ - colWidth - 1) / TILE_SIZE;
    int endY = ((newY + colY) + height_ - colHeight -1) / TILE_SIZE;

    for (int iY = startY; iY < endY; ++iY)
    {
        for (int iX = startX; iX < endX; ++iX)
        {
            CTile* tile = CArea::AreaControl.getTile(iX * TILE_SIZE, iY * TILE_SIZE);
            if (posValidTile(tile) == false) return_ = false;
        }
    }

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

bool CEntity::posValidTile(CTile* tile)
{
    if (tile == NULL) return true;
    if (tile->typeID == TILE_TYPE_BLOCK) return false;
    return true;
}

bool CEntity::posValidEntity(CEntity* entity, const int newX, const int newY)
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











// SETTERS
void CEntity::setX(const float x)
{
    x_ = x;
}

void CEntity::setY(const float y)
{
    y_ = y;
}

void CEntity::setWidth(const int width)
{
    width_ = width;
}

void CEntity::setHeight(const int height)
{
    height_ = height;
}

void CEntity::setAnimeState(const int state)
{
    animeState_ = state;
}

void CEntity::setMoveLeft(const bool move)
{
    moveLeft_ = move;
}

void CEntity::setMoveRight(const bool move)
{
    moveRight_ = move;
}






// TODO: GETTERS





CEntityCol::CEntityCol()
{
    entityA = NULL;
    entityB = NULL;
}

CEntityCol::~CEntityCol()
{}
