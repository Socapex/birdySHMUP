#ifndef CAREA_H
#define CAREA_H

#include <string>

#include "CMap.h"

class CArea {
public:
    CArea();
    ~CArea();

    bool    OnLoad(const char* file);
    void    OnRender(SDL_Surface* Surf_Display, int cameraX, int cameraY);
    void    OnCleanup();

    static CArea AreaControl;
    std::vector<CMap> mapList;

private:
    int areaSize_;
    SDL_Surface* surfTileset_;

};

#endif // CAREA_H
