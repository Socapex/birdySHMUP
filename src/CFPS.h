#ifndef CFPS_H
#define CFPS_H

#include <SDL.h>

class CFPS {
public:
    CFPS();
    ~CFPS();

    void onLoop();

    int getFPS() const;
    float getSpeedFactor() const;

    static CFPS FPSControl;

private:
    unsigned int oldTime;
    unsigned int lastTime;
    float speedFactor;
    int numFrames;
    int frames;


};

#endif // CFPS_H
