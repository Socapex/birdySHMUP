#ifndef CSURFACE_H
#define CSURFACE_H

#include <SDL.h>
#include <SDL_image.h>

class CSurface {
public:
    CSurface();

    static SDL_Surface* onLoad(const char* file);
    static bool OnDraw(SDL_Surface* surfDest, SDL_Surface* surfSource, float x,
                       float y);
    static bool OnDraw(SDL_Surface* surfDest, SDL_Surface* surfSource, float x,
                       float y, int x2, int y2, int w, int h);
    static bool Transparent(SDL_Surface* surfDest, uint8_t R, uint8_t G,
                            uint8_t B);

};

#endif // CSURFACE_H
