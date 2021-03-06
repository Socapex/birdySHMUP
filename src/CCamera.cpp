#include "CCamera.h"

CCamera CCamera::CameraControl;

CCamera::CCamera()
{
    x_ = y_ = 0;
    targetX_ = targetY_ = NULL;
    targetMode = TARGET_MODE_NORMAL;
}

CCamera::~CCamera()
{}

// SETTERS
void CCamera::setPos(const float x, const float y)
{
    x_ = x;
    y_ = y;
}

void CCamera::setTarget(float* x, float* y)
{
    targetX_ = x;
    targetY_ = y;
}


// GETTERS
float CCamera::getX() const
{
    if (targetX_ != NULL)
    {
        if (targetMode == TARGET_MODE_CENTER) return *targetX_ - (WWIDTH / 2);

        return *targetX_;
    }

    return x_;
}

float CCamera::getY() const
{
    if (targetY_ != NULL)
    {
        if (targetMode == TARGET_MODE_CENTER) return *targetY_ - (WHEIGHT / 2);

        return *targetY_;
    }

    return y_;
}


void CCamera::OnMove(const int moveX, const int moveY)
{
    x_ += moveX;
    y_ += moveY;
}
