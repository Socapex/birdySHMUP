#include "CPlayer.h"

CPlayer::CPlayer()
{

}
CPlayer::~CPlayer()
{}

bool CPlayer::OnLoad(const char* file, const int width, const int height, const int maxFrames)
{
    if (CEntity::OnLoad(file, width, height, maxFrames) == false) return false;
    return true;
}

void CPlayer::OnLoop()
{
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
    if (speedX != 0) Anim_Control.setMaxFrames(8);
    else Anim_Control.setMaxFrames(0);

    CEntity::OnAnimate();
}

void CPlayer::OnCollision(CEntity* Entity)
{}
