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
    if(OnInit() == false) return -1;

    SDL_Event event;

    while(running_)
    {
        while(SDL_PollEvent(&event)) OnEvent(&event);
        OnLoop();
        OnRender();
    }

    OnCleanup();
    return 0;
}

void CApp::OnExit()
{
    running_ = false;
}

int main(int argc, char *argv[])
{
    CApp theApp;

    return theApp.OnExecute();
}
