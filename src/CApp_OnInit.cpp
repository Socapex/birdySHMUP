#include "CApp.h"

bool CApp::OnInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

    int test = SDL_GetTicks();

    // TODO: Choisir notre hauteur + largeur
    if((surfDisplay_ = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE
                                        | SDL_DOUBLEBUF)) == NULL) return false;

    // PATHS:
    // JOUEUR
    std::string player1Path = "img/cube.png";

    // ENEMIES
    std::string entity1Path = "img/yoshi.png";
    std::string entity2Path = "img/yoshi.bmp";

    // BACKGROUND & MISC
    std::string backgroundPath = "img/cloud-1.jpg";

    // Platform specific:
#ifdef MACTERMINAL
    // Rien faire, on n'as pas besoin de changer le path lorsqu'on compile du
    // terminal sur mac.
#elif __APPLE__
    player1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    entity1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    entity2Path.insert(0, "birdyShmup.app/Contents/Resources/");
    backgroundPath.insert(0, "birdyShmup.app/Contents/Resources/");
#elif __WIN32__
	player1Path.replace(0, std::string::npos, "../Debug/img/cube.png");
    entity1Path.replace(0, std::string::npos, "../Debug/img/yoshi.bmp");
    entity2Path.replace(0, std::string::npos, "../Debug/img/yoshi.bmp");
    backgroundPath.replace(0, std::string::npos, "../Debug/img/cloud-1.jpg");
#endif

    // Load tous nos entites
    // JOUEUR
    if (Player.onLoad(player1Path.c_str(), 64, 64, 0) == false) return false;
    CEntity::entityList.push_back(&Player);

    // Centrer la camera sur le player (seulement pour le tutoriel)
    CCamera::CameraControl.targetMode = TARGET_MODE_NORMAL;
    //CCamera::CameraControl.setTarget(&Player.x_, &Player.y_);

    // ENEMIES
    if (entity1_.onLoad(entity1Path.c_str(), 64, 64, 8) == false) return false;
    entity1_.setY(200);
    entity1_.setType(ENTITY_TYPE_ENEMY1);
    CEntity::entityList.push_back(&entity1_);
    
    // BACKGROUND
    if ((background1_.onLoad(backgroundPath.c_str())) == false) return false;

    // TEST
    CParticles* explody = new CParticles(255, 255, 0, 400, 50, 5, 8, 0, 1000,
                                         100, 10, "fireworks");
//    CParticles* explody2 = new CParticles("explosion3", 400, 200, 1000, 10000,
//                                          10, 10);

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    return true;


}













    // EXEMPLES
    //if((surfTest_ = CSurface::onLoad("img/yoshi.bmp")) == NULL) return false;
    //Anim_Yoshi_.setMaxFrames(8);
    //Anim_Yoshi_.setOscillate(true);


    // if (entity1_.onLoad(entity1Path.c_str(), 64, 64, 8) == false) return false;
    // if (entity2_.onLoad(entity2Path.c_str(), 64, 64, 8) == false) return false;

    // entity2_.setX(100);

    // CEntity::entityList.push_back(&entity1_);
    // CEntity::entityList.push_back(&entity2_);
