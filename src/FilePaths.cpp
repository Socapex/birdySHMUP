//
//  FilePaths.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights dataerved.
//

#include <SDL.h>
#include <string>

#include "FilePaths.h"

FilePaths::FilePaths()
{
    // JOUEUR
    Files["player1Path"] = "data/img/birdbody2.png";

    // ENEMIES
    Files["entity1Path"] = "data/img/yoshi.png";
    Files["entity2Path"] = "data/img/yoshi.bmp";

    // BACKGROUND & MISC
    Files["backgroundPath"] = "data/img/cloud-2.jpg";
	Files["parallaxPath"] = "data/img/parallaxTest.png";
    Files["parallax2Path"] = "data/img/parallaxTest2.png";

    // BULLETS
    Files["bullet1Path"] = "data/img/bullet.png";

    // PARTICLES
    Files["explosion1Path"] = "data/img/particles/explosion1.jpg";
    Files["explosion2Path"] = "data/img/particles/explosion2.png";
    Files["explosion3Path"] = "data/img/particles/explosion3.png";
    Files["explosion4Path"] = "data/img/particles/explosion4.png";

    // FONTS
    Files["font1Path"] = "data/fonts/FixdStation.ttf";

    // MUSIC
    Files["song1Path"] = "data/music/WelcomeToEurope.ogg";

    // SFX
    Files["sfxMedExplosion"] = "data/sfx/MedExplosion.wav";
    Files["sfxLaser1"] = "data/sfx/Laser1.wav";

    // SPLASHSCREEN
    Files["splash1Path"] = "data/img/Screens/SplashScreen/SuperSplash.png";

    // MainMenu
    Files["main1Path"] = "data/img/Screens/MainMenu/MainMenu.png";
    Files["playButton1Path"] = "data/img/Screens/MainMenu/Buttons/PlayButton.png";


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
