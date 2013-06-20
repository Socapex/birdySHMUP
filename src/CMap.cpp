#include "CMap.h"

CMap::CMap()
{
    surfTileset_ = NULL;
}

CMap::~CMap()
{}

CTile* CMap::getTile(const int x, const int y)
{
    int ID = 0;

    ID = x / TILE_SIZE;
    ID = ID + (MAP_WIDTH * (y / TILE_SIZE));

    if (ID < 0 || ID >= tileList_.size()) return NULL;

    return &tileList_[ID];
}

bool CMap::OnLoad(const char* file)
{
    tileList_.clear();

    FILE* fileHandle = fopen(file, "r");
    if (fileHandle == NULL) return false;

    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            CTile tempTile;
            fscanf(fileHandle, "%d:%d ", &tempTile.tileID, &tempTile.typeID);
            tileList_.push_back(tempTile);
        }
        fscanf(fileHandle, "\n");
    }
    fclose(fileHandle);

    return true;
}

void CMap::OnRender(SDL_Surface* Surf_Display, int mapX, int mapY)
{
    if (surfTileset_ == NULL) return;

    int tileSetWidth = surfTileset_->w / TILE_SIZE;
    int tileSetHeight = surfTileset_->h / TILE_SIZE;
    int ID = 0;

    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            if (tileList_[ID].typeID == TILE_TYPE_NONE)
            {
                ++ID;
                continue;
            }

            int tX = mapX + (x * TILE_SIZE);
            int tY = mapY + (y * TILE_SIZE);

            int tileSetX = (tileList_[ID].tileID % tileSetWidth) * TILE_SIZE;
            int tileSetY = (tileList_[ID].tileID / tileSetWidth) * TILE_SIZE;

            CSurface::OnDraw(Surf_Display, surfTileset_, tX, tY, tileSetX,
                                tileSetY, TILE_SIZE, TILE_SIZE);

            ++ID;
        }
    }
}






