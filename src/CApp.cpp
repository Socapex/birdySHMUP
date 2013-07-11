#include "CApp.h"

CApp::CApp()
{
    surfDisplay_ = NULL;
    running_ = true;

    // EXEMPLES
    //surfTest_ = NULL;
}

int CApp::OnExecute()
{
    if(initSDL() == false) return -1;
    if(onInit() == false) return -1;

    SDL_Event event;

    while(running_)
    {
        while(SDL_PollEvent(&event)) onEvent(&event);
        onLoop();
        onRender();
    }

    onCleanup();
    return 0;
}

void CApp::onExit()
{
    running_ = false;
}

int main(int argc, char *argv[])
{
    CApp theApp;

    return theApp.OnExecute();
}
