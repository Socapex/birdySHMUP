#include "CEntity.h"

std::vector<CEntity*> CEntity::entityList;

CEntity::CEntity()
{
    surfaceEntity_ = NULL;

    x_ = y_ = 0.0f;
    width_ = height_ = 0;
    animeState_ = 0;

    type_ = ENTITY_TYPE_GENERIC;

    dead_ = false;
    flags_ = ENTITY_FLAG_NONE;

    currentFrameCol = 0;
    currentFrameRow = 0;

    colX = 0;
    colY = 0;
    colWidth = 0;
    colHeight = 0;

    animControl = new CAnimation();
}

CEntity::~CEntity()
{
    if (surfaceEntity_) SDL_FreeSurface(surfaceEntity_);

    surfaceEntity_ = NULL;

    delete animControl;
}


// FUNCTIONS



bool CEntity::collides(const float oX, const float oY, const float oW, const float oH)
{
    float left1, left2, right1, right2, top1, top2, bottom1, bottom2;

    float tX = x_ + colX;
    float tY = y_ + colY;

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
    if (left1 > right2) return false;

    return true;
}

bool CEntity::checkLife()
{
    if (life_ <= 0)
    {
        return false;
    }

    return true;
    
}










// VIRTUAL FUNCTIONS

bool CEntity::onLoad(const char* file, const int width, const int height,
                     const int maxFrames)
{
    if ((surfaceEntity_ = CSurface::onLoad(file)) == NULL) return false;

    CSurface::Transparent(surfaceEntity_, 255, 0, 255);

    this->setWidth(width);
    this->setHeight(height);
    animControl->setMaxFrames(maxFrames);
    return true;
}

void CEntity::onLoop(CPlayer* player)
{

}

void CEntity::onRender(SDL_Surface* surfDisplay)
{
    if (surfaceEntity_ == NULL || surfDisplay == NULL) return;

    if (!dead_)
    {
        CEntity::onAnimate();

        CSurface::OnDraw(surfDisplay, surfaceEntity_, x_, y_, currentFrameCol * width_,
                         (currentFrameRow + animControl->getCurrentFrame()) * height_,
                         width_, height_);
    }
}

void CEntity::onAnimate()
{
    // TODO: Rajouter des defines ou autre chose pour ces chiffres.
    // Completement stupide d'etre couler dans l'beton!
    //if (moveLeft_) currentFrameCol = 0;
    //else if (moveRight_) currentFrameCol = 1;

    animControl->onAnimate();
}

bool CEntity::onCollision(CEntity* entity)
{
	return true;
}









// PRIVATE FUNCTIONS
bool CEntity::checkCollision(const float newX, const float newY)
{
    bool return_ = true;

    if (getFlags() & ENTITY_FLAG_MAPONLY) {}
    else
    {
        for (int i = 0; i < entityList.size(); ++i)
        {
            if (checkEntityCollision(entityList[i], newX, newY) == false)
                return_ = false;

        }
    }

    return return_;
}

bool CEntity::checkEntityCollision(CEntity* entity, const float newX, const float newY)
{
    if (this != entity && entity != NULL && entity->getDead() == false
        && entity->getFlags() ^ ENTITY_FLAG_MAPONLY
        && entity->collides(newX + colX, newY + colY, width_ - colWidth - 1.0f,
                            height_ - colHeight - 1.0f) == true)
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

void CEntity::setType(const int type)
{
    type_ = type;
}
void CEntity::setDead(const bool dead)
{
    dead_ = dead;
}
void CEntity::setFlags(const int flags)
{
    flags_ = flags;
}
void CEntity::setLife(const float life)
{
    life_ = life;
}






// TODO: GETTERS

float CEntity::getX() const
{
    return x_;
}
float CEntity::getY() const
{
    return y_;
}
int CEntity::getWidth() const
{
    return width_;
}
int CEntity::getHeight() const
{
    return height_;
}
int CEntity::getType() const
{
    return type_;
}
bool CEntity::getDead() const
{
    return dead_;
}
int CEntity::getFlags() const
{
    return flags_;
}
float CEntity::getLife() const
{
    return life_;
}


