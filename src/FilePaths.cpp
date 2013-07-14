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
    player1Path = "img/birdbody2.png";

    // ENEMIES
    entity1Path = "img/yoshi.png";
    entity2Path = "img/yoshi.bmp";

    // BACKGROUND & MISC
    backgroundPath = "img/cloud-2.jpg";
	parallaxPath = "img/parallaxTest.png";
    parallax2Path = "img/parallaxTest2.png";

    // BULLETS
    bullet1Path = "img/bullet.png";

    // PARTICLES
    explosion1Path = "img/particles/explosion1.jpg";
    explosion2Path = "img/particles/explosion2.png";
    explosion3Path = "img/particles/explosion3.png";
    explosion4Path = "img/particles/explosion4.png";

    // FONTS
    font1Path = "fonts/FixdStation.ttf";

    // MUSIC
    song1Path = "music/WelcomeToEurope.ogg";

    // SPLASHSCREEN
    splash1Path = "img/Screens/SplashScreen/SuperSplash.png";

    // MainMenu
    main1Path = "img/Screens/MainMenu/MainMenu.png";







    // Platform specific:
#ifdef MACTERMINAL
    // Rien faire, on n'as pas besoin de changer le path lorsqu'on compile du
    // terminal sur mac.
    
#elif __APPLE__
    player1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    
    entity1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    entity2Path.insert(0, "birdyShmup.app/Contents/Resources/");
    
    backgroundPath.insert(0, "birdyShmup.app/Contents/Resources/");
	parallaxPath.insert(0, "birdyShmup.app/Contents/Resources/");
    parallax2Path.insert(0, "birdyShmup.app/Contents/Resources/");
    
    bullet1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    
    explosion1Path.insert(0, "birdyShmup.app/Contents/Resources/");
    explosion2Path.insert(0, "birdyShmup.app/Contents/Resources/");
    explosion3Path.insert(0, "birdyShmup.app/Contents/Resources/");
    explosion4Path.insert(0, "birdyShmup.app/Contents/Resources/");

    font1Path.insert(0, "birdyShmup.app/Contents/Resources/");

    song1Path.insert(0, "birdyShmup.app/Contents/Resources/");

#elif __WIN32__

	player1Path.insert(0, "../../");
    
    entity1Path.insert(0, "../../");
    entity2Path.insert(0, "../../");
    
    backgroundPath.insert(0, "../../");
	parallaxPath.insert(0, "../../");
    parallax2Path.insert(0, "../../");

    bullet1Path.insert(0, "../../");
    
	explosion1Path.insert(0, "../../");
    explosion2Path.insert(0, "../../");
    explosion3Path.insert(0, "../../");
    explosion4Path.insert(0, "../../");

    font1Path.insert(0, "../../");

    song1Path.insert(0, "../../");


#endif
}