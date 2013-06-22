#ifndef CANIMATION_H
#define CANIMATION_H

#include <SDL.h>

class CAnimation {
public:
    CAnimation();
    ~CAnimation();

    void OnAnimate();
    void setFrameRate(const int rate);
    void setCurrentFrame(const int frame);
    void setMaxFrames(const int max);
    void setOscillate(const bool osc);

    int getCurrentFrame() const;

private:
    int maxFrames_;
    bool oscillate_;
    int currentFrame_;
    int frameInc_;
    int frameRate_; //Milliseconds
    long oldTime_;


};

#endif // CANIMATION_H
