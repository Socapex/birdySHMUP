#include "CApp.h"

// Initialise SDL seperately so we can use SDL_GetTicks() inside constructors.
bool CApp::initSDL()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

    // Init fonts
    if (TTF_Init() < 0)
    {
        printf("Unable to initialize SDL_ttf: %s \n", TTF_GetError());
        return false;
    }

    if( SDL_Init(SDL_INIT_AUDIO) < 0 ) return false;

    Mix_OpenAudio(44100,AUDIO_S16SYS,2,640);

    // TODO: Choisir notre hauteur + largeur
    if((surfDisplay_ = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE
                                        | SDL_DOUBLEBUF)) == NULL) return false;

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    return true;
}

bool CApp::onInit()
{


    FilePaths Path;

    // Load tous nos entites
    // JOUEUR
    if (Player.onLoad(Path.player1Path.c_str(), 128, 128, 0) == false) return false;
    CEntity::entityList.push_back(&Player);


    // Centrer la camera sur le player (seulement pour le tutoriel)
    CCamera::CameraControl.targetMode = TARGET_MODE_NORMAL;
    //CCamera::CameraControl.setTarget(&Player.x_, &Player.y_);


    // ENEMIES
    enemySpawner_.onLoad();


    // BACKGROUND
    if ((background1_.onLoad(Path.backgroundPath.c_str())) == false) return false;
	if ((parallax1_.onLoad(Path.parallaxPath.c_str())) == false) return false;
	else parallax1_.setBackgroundLevel(BACKGROUND_SCROLL_SPEED_LEVEL_4);

    if ((parallax2_.onLoad(Path.parallax2Path.c_str())) == false) return false;
    else parallax2_.setBackgroundLevel(BACKGROUND_SCROLL_SPEED_LEVEL_2);

    CGUI::gUI.onLoad();
    CGUI::gUI.getReady();


    // MUSIC
    music_.onLoad();
    music_.play();


    // TEST
    CParticles* explody = new CParticles(255, 255, 0, 400, 50, 5, 8, 0, 1000,
                                         100, 10, "fireworks");

    explody->play(400, 50);
//    CParticles* explody2 = new CParticles("explosion3", 400, 200, 1000, 10000,
//                                          10, 10);



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
