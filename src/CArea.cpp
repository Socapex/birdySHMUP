#include "CArea.h"

CArea CArea::AreaControl;

CArea::CArea()
{
    areaSize_ = 0;
}

CArea::~CArea()
{}

bool CArea::OnLoad(const char* file)
{
    mapList.clear();

    FILE* FileHandle = fopen(file, "r");
    if (FileHandle == NULL) return false;

    char TilesetFileChar[255];

    fscanf(FileHandle, "%s\n", TilesetFileChar);

    // Creer un string, et prepend un path pour different systems
    std::string TilesetFile = std::string(TilesetFileChar);
    
#ifdef MACTERMINAL
#elif __APPLE__
    TilesetFile.insert(2, "birdyShmup.app/Contents/Resources/");
#endif

    if ((surfTileset_ = CSurface::OnLoad(TilesetFile.c_str())) == false)
    {
        fclose(FileHandle);
        return false;
    }

    fscanf(FileHandle, "%d\n", &areaSize_);

    for (int x = 0; x < areaSize_; ++x)
    {
        for (int y = 0; y < areaSize_; ++y)
        {
            char MapFileChar[255];

            fscanf(FileHandle, "%s ", MapFileChar);

            // Creer un string, et prepend un path pour different systems
            std::string MapFile = std::string(MapFileChar);
            
#ifdef MACTERMINAL
#elif __APPLE__
            MapFile.insert(2, "birdyShmup.app/Contents/Resources/");
#endif

            CMap tempMap;
            if (tempMap.OnLoad(MapFile.c_str()) == false)
            {
                fclose(FileHandle);
                return false;
            }

            tempMap.surfTileset_ = surfTileset_;
            mapList.push_back(tempMap);
        }
        fscanf(FileHandle, "\n");
    }
    fclose(FileHandle);

    return true;

}

void CArea::OnRender(SDL_Surface* Surf_Display, int cameraX, int cameraY)
{
    int mapWidth = MAP_WIDTH * TILE_SIZE;
    int mapHeight = MAP_HEIGHT * TILE_SIZE;

    int firstID = -cameraX / mapWidth;
    firstID = firstID + ((-cameraY / mapHeight) * areaSize_);

    for (int i = 0; i < 4; ++i)
    {
        int ID = firstID + ((i / 2) * areaSize_) + (i % 2);

        if (ID < 0 || ID >= mapList.size()) continue;

        int X = ((ID % areaSize_) * mapWidth) + cameraX;
        int Y = ((ID / areaSize_) * mapHeight) + cameraY;

        mapList[ID].OnRender(Surf_Display, X, Y);
    }
}

void CArea::OnCleanup()
{
    if (surfTileset_) SDL_FreeSurface(surfTileset_);
    mapList.clear();
}






