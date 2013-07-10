#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

#include "Defines.h"
#include "FilePaths.h"

#include "CSurface.h"
#include "CEvent.h"
#include "CEntity.h"
#include "CCamera.h"
#include "CPlayer.h"
#include "CFPS.h"
#include "CGUI.h"
#include "CParticles.h"
#include "CBackground.h"
#include "CEnemy.h"
#include "CEnemySpawner.h"

class CApp : public CEvent {
public:
    CApp();

    int OnExecute();

    bool OnInit();
    void OnEvent(SDL_Event* event);
    void OnExit();
    void onLoop();
    void onRender();
    void onCleanup();

    // BOUTONS
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

private:
    SDL_Surface* surfDisplay_;

    CPlayer Player;

    CEnemySpawner enemySpawner_;

    CEnemy entity1_;
    CEntity entity2_;

    CBackground background1_;
	CBackground parallax1_;

    CAnimation Anim_Yoshi_;

    SDL_Surface* surfBackground_;

    bool running_;

    // EXEMPLES
    //SDL_Surface* surfTest_;
};

#endif // CAPP_H
