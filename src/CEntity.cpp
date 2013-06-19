#include "CEntity.h"

std::vector<CEntity*> CEntity::entityList;

CEntity::CEntity()
{
    Surf_Entity = NULL;

    x_ = y_ = 0.0f;
    width_ = height_ = 0;
    animeState_ = 0;
}

CEntity::~CEntity()
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




// FUNCTIONS

bool CEntity::OnLoad(const char* file, int width, int height, int maxFrames)
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
    Anim_Control.onAnimate();
}

void CEntity::OnRender(SDL_Surface* Surf_Display)
{
    if (Surf_Entity == NULL || Surf_Display == NULL) return;

    CSurface::OnDraw(Surf_Display, Surf_Entity, x_, y_, animeState_ * width_,
                    Anim_Control.getCurrentFrame() * height_, width_, height_);
}

void CEntity::OnCleanup()
{
    if (Surf_Entity) SDL_FreeSurface(Surf_Entity);

    Surf_Entity = NULL;
}
