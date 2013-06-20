#ifndef CAPP_H
#define CAPP_H

#include "SDL/SDL.h"
#include <string>

#include "CSurface.h"
#include "CEvent.h"
#include "CAnimation.h"
#include "CEntity.h"
#include "Defines.h"
#include "CArea.h"
#include "CCamera.h"
#include "CPlayer.h"

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

    CPlayer player1_;
    CPlayer player2_;

    CEntity entity1_;
    CEntity entity2_;

    CAnimation Anim_Yoshi_;

    bool running_;

    // EXEMPLES
    //SDL_Surface* surfTest_;
};

#endif // CAPP_H
