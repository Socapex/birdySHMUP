#ifndef CFPS_H
#define CFPS_H

#include <SDL.h>

class CFPS {
public:
    CFPS();
    ~CFPS();

    void OnLoop();

    int getFPS() const;
    float getSpeedFactor() const;

    static CFPS FPSControl;

private:
    int oldTime;
    int lastTime;
    float speedFactor;
    int numFrames;
    int frames;


};

#endif // CFPS_H
