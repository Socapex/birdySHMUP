#include "CApp.h"

bool CApp::OnInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

    // TODO: Choisir notre hauteur + largeur
    if((surfDisplay_ = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) return false;

    // Utiliser des chars pour facilite les changements de path de fichier
    std::string entity1Path = "img/yoshi.bmp";
    std::string entity2Path = "img/yoshi.bmp";

    std::string areaPath = "maps/1.area";

    // Platform specific:
#ifdef MACTERMINAL
    // Rien faire, on n'as pas besoin de changer le path lorsqu'on compile du
    // terminal sur mac.
    
#elif __APPLE__
    entity1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    entity2Path.insert(0, "birdyShmup.app/Contents/Resources/");
    areaPath.insert(0, "birdyShmup.app/Contents/Resources/");
    
#endif

    // Load tous nos entites    
    if (entity1_.OnLoad(entity1Path.c_str(), 64, 64, 8) == false) return false;
    if (entity2_.OnLoad(entity2Path.c_str(), 64, 64, 8) == false) return false;

    // Parametres initiales
    entity2_.setX(100);

    // Rajouter a notre vecteur d'entites
    CEntity::entityList.push_back(&entity1_);
    CEntity::entityList.push_back(&entity2_);


    // Map
    if (CArea::AreaControl.OnLoad(areaPath.c_str()) == false) return false;

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    return true;


    // EXEMPLES
    //if((surfTest_ = CSurface::OnLoad("img/yoshi.bmp")) == NULL) return false;
    //Anim_Yoshi_.setMaxFrames(8);
    //Anim_Yoshi_.setOscillate(true);
}
