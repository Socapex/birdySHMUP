#include "CSurface.h"

CSurface::CSurface()
{

}

SDL_Surface* CSurface::onLoad(const char* file)
{
    SDL_Surface* surfTemp = NULL;
    SDL_Surface* surfReturn = NULL;

    if((surfTemp = IMG_Load(file)) == NULL)
    {
        printf("IMG_Load: %s\n", IMG_GetError());
        return NULL;
    }

    surfReturn = SDL_DisplayFormatAlpha(surfTemp);
    SDL_FreeSurface(surfTemp);

    return surfReturn;
}

bool CSurface::OnDraw(SDL_Surface *surfDest, SDL_Surface *surfSource, float x, float y)
{
    if(surfDest == NULL || surfSource == NULL) return false;

    SDL_Rect destRect;
    destRect.x = static_cast<int>(x+0.5);//plus 0.5 pour arrondir correctement
    destRect.y = static_cast<int>(y+0.5);

    SDL_BlitSurface(surfSource, NULL, surfDest, &destRect);

    return true;
}

bool CSurface::OnDraw(SDL_Surface *surfDest, SDL_Surface *surfSource, float x,
                        float y, int x2, int y2, int w, int h)
{
    if(surfDest == NULL || surfSource == NULL) return false;

    SDL_Rect destRect;
    destRect.x = static_cast<int>(x+0.5);
    destRect.y = static_cast<int>(y+0.5);

    SDL_Rect srcRect;
    srcRect.x = x2;
    srcRect.y = y2;
    srcRect.w = w;
    srcRect.h = h;

    SDL_BlitSurface(surfSource, &srcRect, surfDest, &destRect);

    return true;
}

bool CSurface::Transparent(SDL_Surface *surfDest, uint8_t R, uint8_t G, uint8_t B)
{
    if(surfDest == NULL) return false;

    SDL_SetColorKey(surfDest, SDL_SRCCOLORKEY | SDL_RLEACCEL,
                    SDL_MapRGB(surfDest->format, R, G, B));

    return true;
}
