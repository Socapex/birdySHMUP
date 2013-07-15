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
    Files["player1Path"] = "img/birdbody2.png";

    // ENEMIES
    Files["entity1Path"] = "img/yoshi.png";
    Files["entity2Path"] = "img/yoshi.bmp";

    // BACKGROUND & MISC
    Files["backgroundPath"] = "img/cloud-2.jpg";
	Files["parallaxPath"] = "img/parallaxTest.png";
    Files["parallax2Path"] = "img/parallaxTest2.png";

    // BULLETS
    Files["bullet1Path"] = "img/bullet.png";

    // PARTICLES
    Files["explosion1Path"] = "img/particles/explosion1.jpg";
    Files["explosion2Path"] = "img/particles/explosion2.png";
    Files["explosion3Path"] = "img/particles/explosion3.png";
    Files["explosion4Path"] = "img/particles/explosion4.png";

    // FONTS
    Files["font1Path"] = "fonts/FixdStation.ttf";

    // MUSIC
    Files["song1Path"] = "music/WelcomeToEurope.ogg";

    // SFX
    Files["sfxMedExplosion"] = "sfx/MedExplosion.wav";
    Files["sfxLaser1"] = "sfx/Laser1.wav";

    // SPLASHSCREEN
    Files["splash1Path"] = "img/Screens/SplashScreen/SuperSplash.png";

    // MainMenu
    Files["main1Path"] = "img/Screens/MainMenu/MainMenu.png";
    Files["playButton1Path"] = "img/Screens/MainMenu/Buttons/PlayButton.png";


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
