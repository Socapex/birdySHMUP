//
//  FilePaths.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include <SDL.h>
#include <string>

#include "FilePaths.h"

FilePaths::FilePaths()
{
    // JOUEUR
    Files["player1Path"] = "res/img/birdbody2.png";

    // ENEMIES
    Files["entity1Path"] = "res/img/yoshi.png";
    Files["entity2Path"] = "res/img/yoshi.bmp";

    // BACKGROUND & MISC
    Files["backgroundPath"] = "res/img/cloud-2.jpg";
	Files["parallaxPath"] = "res/img/parallaxTest.png";
    Files["parallax2Path"] = "res/img/parallaxTest2.png";

    // BULLETS
    Files["bullet1Path"] = "res/img/bullet.png";

    // PARTICLES
    Files["explosion1Path"] = "res/img/particles/explosion1.jpg";
    Files["explosion2Path"] = "res/img/particles/explosion2.png";
    Files["explosion3Path"] = "res/img/particles/explosion3.png";
    Files["explosion4Path"] = "res/img/particles/explosion4.png";

    // FONTS
    Files["font1Path"] = "res/fonts/FixdStation.ttf";

    // MUSIC
    Files["song1Path"] = "res/music/WelcomeToEurope.ogg";

    // SFX
    Files["sfxMedExplosion"] = "res/sfx/MedExplosion.wav";
    Files["sfxLaser1"] = "res/sfx/Laser1.wav";

    // SPLASHSCREEN
    Files["splash1Path"] = "res/img/Screens/SplashScreen/SuperSplash.png";

    // MainMenu
    Files["main1Path"] = "res/img/Screens/MainMenu/MainMenu.png";
    Files["playButton1Path"] = "res/img/Screens/MainMenu/Buttons/PlayButton.png";


    std::map<std::string, std::string>::iterator iter;
    
    // Platform specific:
#ifdef MACTERMINAL
    // Rien faire, on n'as pas besoin de changer le path lorsqu'on compile du
    // terminal sur mac.

#elif __APPLE__

    for (iter = Files.begin(); iter != Files.end(); ++iter)
    {
        iter->second.insert(0, "birdyShmup.app/Contents/Resources/");
    }

#elif __WIN32__

    for (iter = Files.begin(); iter != Files.end(); ++iter)
    {
        iter->second.insert(0, "../../");
    }

#endif
}
