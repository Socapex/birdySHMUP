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

}

CEntity::~CEntity()
{}


// FUNCTIONS



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
    if (left1 > right2) return false;

    return true;
}

bool CEntity::OnLoad(const char* file, const int width, const int height,
                     const int maxFrames)
{
    if ((surfaceEntity_ = CSurface::OnLoad(file)) == NULL) return false;

    CSurface::Transparent(surfaceEntity_, 255, 0, 255);

    this->setWidth(width);
    this->setHeight(height);
    Anim_Control.setMaxFrames(maxFrames);
    return true;
}

void CEntity::OnLoop()
{

}

void CEntity::OnRender(SDL_Surface* Surf_Display)
{
    if (surfaceEntity_ == NULL || Surf_Display == NULL) return;

    OnAnimate();

    CSurface::OnDraw(Surf_Display, surfaceEntity_, x_, y_, currentFrameCol * width_,
                    (currentFrameRow + Anim_Control.getCurrentFrame()) * height_,
                    width_, height_);
}

void CEntity::OnCleanup()
{
    if (surfaceEntity_) SDL_FreeSurface(surfaceEntity_);

    surfaceEntity_ = NULL;
}

void CEntity::OnAnimate()
{
    // TODO: Rajouter des defines ou autre chose pour ces chiffres.
    // Completement stupide d'etre couler dans l'beton!
    //if (moveLeft_) currentFrameCol = 0;
    //else if (moveRight_) currentFrameCol = 1;

    Anim_Control.OnAnimate();
}

bool CEntity::OnCollision(CEntity* entity)
{
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






// TODO: GETTERS

float CEntity::getX() const
{
    return x_;
}
float CEntity::getY() const
{
    return y_;
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


