#include "CEntity.h"

std::vector<CEntity*> CEntity::entityList;

CEntity::CEntity()
{
    Surf_Entity = NULL;

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
    OnAnimate();
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
    // TODO: Rajouter des defines ou autre chose pour ces chiffres.
    // Completement stupide d'etre couler dans l'beton!
    //if (moveLeft_) currentFrameCol = 0;
    //else if (moveRight_) currentFrameCol = 1;

    Anim_Control.OnAnimate();
}

bool CEntity::OnCollision(CEntity* entity)
{}










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








// TODO: GETTERS




