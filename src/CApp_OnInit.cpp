#include "CApp.h"

bool CApp::OnInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

    // TODO: Choisir notre hauteur + largeur
    if((surfDisplay_ = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) return false;

    // PATHS:
    // JOUEUR
    std::string player1Path = "img/yoshi.png";
    std::string player2Path = "img/yoshi.png";

    // ENEMIES
    std::string entity1Path = "img/yoshi.bmp";
    std::string entity2Path = "img/yoshi.bmp";

    // MAP & MISC
    std::string areaPath = "maps/1.area";

    // Platform specific:
#ifdef MACTERMINAL
    // Rien faire, on n'as pas besoin de changer le path lorsqu'on compile du
    // terminal sur mac.
#elif __APPLE__
    player1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    player2Path.insert(0, "birdyShmup.app/Contents/Resources/");
    entity1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    entity2Path.insert(0, "birdyShmup.app/Contents/Resources/");
    areaPath.insert(0, "birdyShmup.app/Contents/Resources/");

#endif

    // Load tous nos entites
    // JOUEUR
    if (player1_.OnLoad(player1Path.c_str(), 64, 64, 8) == false) return false;
    if (player2_.OnLoad(player2Path.c_str(), 64, 64, 8) == false) return false;

    // Params initiales
    player1_.setX(300);
    player2_.setX(100);

    // Rajouter a notre vector d'entites
    CEntity::entityList.push_back(&player1_);
    CEntity::entityList.push_back(&player2_);

    // Centrer la camera sur le player (seulement pour le tutoriel)
    CCamera::CameraControl.targetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.setTarget(&player1_.x_, &player1_.y_);

    // ENEMIES
    // if (entity1_.OnLoad(entity1Path.c_str(), 64, 64, 8) == false) return false;
    // if (entity2_.OnLoad(entity2Path.c_str(), 64, 64, 8) == false) return false;

    // entity2_.setX(100);

    // CEntity::entityList.push_back(&entity1_);
    // CEntity::entityList.push_back(&entity2_);


    // Map
    if (CArea::AreaControl.OnLoad(areaPath.c_str()) == false) return false;

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    return true;


    // EXEMPLES
    //if((surfTest_ = CSurface::OnLoad("img/yoshi.bmp")) == NULL) return false;
    //Anim_Yoshi_.setMaxFrames(8);
    //Anim_Yoshi_.setOscillate(true);
}
