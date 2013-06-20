#ifndef CMAP_H
#define CMAP_H

#include "SDL/SDL.h"
#include <vector>

#include "CTile.h"
#include "CSurface.h"

class CMap {
public:
    CMap();
    ~CMap();

    CTile* getTile(const int x, const int y);

    bool OnLoad(const char* file);
    void OnRender(SDL_Surface* Surf_Display, int mapX, int mapY);

    std::vector<CTile> tileList_;
    SDL_Surface* surfTileset_;

};

#endif //CMAP_H
