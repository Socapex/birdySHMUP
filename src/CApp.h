#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <string>

#include "Defines.h"

#include "CSurface.h"
#include "CEvent.h"
#include "CEntity.h"
#include "CCamera.h"
#include "CPlayer.h"
#include "CFPS.h"
#include "CGUI.h"

class CApp : public CEvent {
public:
    CApp();

    int OnExecute();

    bool OnInit();
    void OnEvent(SDL_Event* event);
    void OnExit();
    void OnLoop();
    void OnRender();
    void OnCleanup();

    // BOUTONS
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

private:
    SDL_Surface* surfDisplay_;

    CPlayer Player;

    CEntity entity1_;
    CEntity entity2_;

    CAnimation Anim_Yoshi_;

    SDL_Surface* surfBackground_;

    bool running_;

    // EXEMPLES
    //SDL_Surface* surfTest_;
};

#endif // CAPP_H
