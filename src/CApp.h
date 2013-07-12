#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>

#include "Defines.h"
#include "FilePaths.h"

#include "CLevel.h"
#include "CEvent.h"
#include "CCamera.h"
#include "CPlayer.h"
#include "CFPS.h"
#include "CGUI.h"
#include "CSplashScreen.h"
#include "CMainMenu.h"

class CApp : public CEvent {
public:
    CApp();

    int OnExecute();

    bool initSDL();
    bool onInit();
    void onEvent(SDL_Event* event);
    void onExit();
    void onLoop();
    void onRender();
    void onCleanup();

    // BOUTONS
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

private:
    SDL_Surface* surfDisplay_;

    CPlayer* Player;

    CLevel* level1_;
    bool loadLevel1_;

    // Les Menu
    CSplashScreen splashScreen1_;

    CMainMenu mainMenu1_;

    int currentLevel_;

    bool running_;

    // EXEMPLES
    //SDL_Surface* surfTest_;
};

#endif // CAPP_H
