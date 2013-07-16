#ifndef CCAMERA_H
#define CCAMERA_H

#include <SDL.h>

#include "Defines.h"

enum {TARGET_MODE_NORMAL = 0, TARGET_MODE_CENTER};

class CCamera {
public:
    CCamera();
    ~CCamera();

    // SETTERS
    void setPos(const float x, const float y);
    void setTarget(float* x, float* y);

    // GETTERS
    float getX() const;
    float getY() const;

    void OnMove(const int moveX, const int moveY);

    static CCamera CameraControl;
    int targetMode;

private:
    float x_;
    float y_;
    float* targetX_;
    float* targetY_;

};

#endif // CCAMERA_H
