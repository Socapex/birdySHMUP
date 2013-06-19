#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <string>

#include "CSurface.h"
#include "CEvent.h"
#include "CAnimation.h"
#include "CEntity.h"
#include "Defines.h"
#include "CArea.h"
#include "CCamera.h"

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
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

private:
    SDL_Surface* surfDisplay_;

    CEntity entity1_;
    CEntity entity2_;

    CAnimation Anim_Yoshi_;

    bool running_;

    // EXEMPLES
    //SDL_Surface* surfTest_;
};

#endif // CAPP_H
