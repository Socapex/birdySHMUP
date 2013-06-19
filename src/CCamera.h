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
    void setPos(const int x, const int y);
    void setTarget(int* x, int* y);

    // GETTERS
    int getX() const;
    int getY() const;

    void OnMove(const int moveX, const int moveY);

    static CCamera CameraControl;
    int targetMode;

private:
    int x_;
    int y_;
    int* targetX_;
    int* targetY_;

};

#endif // CCAMERA_H
