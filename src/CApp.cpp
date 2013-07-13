#include "CApp.h"

// Initialise SDL seperately so we can use SDL_GetTicks() inside constructors.
bool initSDL()
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


    return true;
}

// INITIALIZE
CApp::CApp()
{
    running_ = true;

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    surfDisplay_ = NULL;
    surfDisplay_ = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE
                                    | SDL_DOUBLEBUF);


    level1_ = NULL;
    currentLevel_ = 1;

    FilePaths Path;

    // JOUEUR
    Player = new CPlayer();
    Player->onLoad(Path.player1Path.c_str(), 128, 128, 0);
    CEntity::entityList.push_back(Player);


    // Centrer la camera sur le player (seulement pour le tutoriel)
    CCamera::CameraControl.targetMode = TARGET_MODE_NORMAL;
    //CCamera::CameraControl.setTarget(&Player.x_, &Player.y_);



    // SPLASHSCREEN
    splashScreen1_.onLoad(Path.splash1Path.c_str());

    // MAINMENU
    mainMenu1_.onLoad(Path.main1Path.c_str());

    gUI_ = new CGUI();
    gUI_->getReady();
}

CApp::~CApp()
{
    delete Player;
    delete gUI_;
    delete level1_;

    SDL_FreeSurface(surfDisplay_);

    TTF_Quit();
    SDL_Quit();
}













int CApp::OnExecute()
{
    SDL_Event event;

    while(running_)
    {
        while(SDL_PollEvent(&event)) onEvent(&event);
        onLoop();
        onRender();
    }

    return 0;
}

void CApp::onExit()
{
    running_ = false;
}

int main(int argc, char *argv[])
{
    if(initSDL() == false) return -1;
    
    CApp theApp;

    return theApp.OnExecute();
}
