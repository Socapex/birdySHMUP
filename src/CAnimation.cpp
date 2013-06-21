#include "CAnimation.h"

CAnimation::CAnimation()
{
    maxFrames_ = 0;
    oscillate_ = false;

    currentFrame_ = 0;
    frameInc_ = 1;
    frameRate_ = 100;
    oldTime_ = 0;
}

CAnimation::~CAnimation()
{

}

void CAnimation::OnAnimate()
{
    if (oldTime_ + frameRate_ > SDL_GetTicks()) return;

    oldTime_ = SDL_GetTicks();
    currentFrame_ += frameInc_;

    if (oscillate_)
    {
        if (frameInc_ > 0)
        {
            if (currentFrame_ >= maxFrames_) frameInc_ = -frameInc_;
        }

        else if (currentFrame_ <= 0) frameInc_ = -frameInc_;
    }

    else if (currentFrame_ >= maxFrames_) currentFrame_ = 0;
}

void CAnimation::setFrameRate(const int rate)
{
    frameRate_ = rate;
}

void CAnimation::setCurrentFrame(const int frame)
{
    if (frame < 0 || frame >= maxFrames_) return;

    currentFrame_ = frame;
}

void CAnimation::setMaxFrames(const int max)
{
    maxFrames_ = max;
}
void CAnimation::setOscillate(const bool osc)
{
    oscillate_ = osc;
}




int CAnimation::getCurrentFrame() const
{
    return currentFrame_;
}



