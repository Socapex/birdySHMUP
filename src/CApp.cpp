#include "CApp.h"

// Initialise SDL seperately so we can use SDL_GetTicks() inside constructors.
bool initSDL()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    // Init fonts
    if (TTF_Init() != 0)
    {
        fprintf(stderr, "Unable to initialize SDL_ttf: %s \n", TTF_GetError());
        return false;
    }

    //if( SDL_Init(SDL_INIT_AUDIO) < 0 ) return false;

    if (Mix_OpenAudio(44100,AUDIO_S16SYS,2,640) != 0)
    {
        fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
        return false;
    }

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
    currentLevel_ = 0;

    FilePaths Path;

    // JOUEUR
    Player = new CPlayer();
    Path.Files["player1Path"].c_str();
    Player->onLoad(Path.Files["player1Path"].c_str(), 128, 128, 0);
    CEntity::entityList.push_back(Player);


    // Centrer la camera sur le player (seulement pour le tutoriel)
    CCamera::CameraControl.targetMode = TARGET_MODE_NORMAL;
    //CCamera::CameraControl.setTarget(&Player.x_, &Player.y_);



    // SPLASHSCREEN
    splashScreen1_.onLoad(Path.Files["splash1Path"].c_str());

    // MAINMENU
    mainMenu1_.onLoad(Path.Files["main1Path"].c_str());

    gUI_ = new CGUI();
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
    // Initialise SDL outside CApp so objects can use SDL_GetTicks in constructors
    if(initSDL() == false) return -1;
    
    CApp theApp;

    return theApp.OnExecute();
}


CMainMenu* CApp::getMainMenu()
{
    return &mainMenu1_;
}