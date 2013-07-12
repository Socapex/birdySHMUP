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

	player1Path.replace(0, std::string::npos, "../../img/cube.png");
    
    entity1Path.replace(0, std::string::npos, "../../img/yoshi.bmp");
    entity2Path.replace(0, std::string::npos, "../../img/yoshi.bmp");
    
    backgroundPath.replace(0, std::string::npos, "../../img/cloud-1.jpg");
	parallaxPath.replace(0, std::string::npos, "../../img/parallax.png");
    parallax2Path.replace(0, std::string::npos, "../../img/parallax.png");

    bullet1Path.replace(0, std::string::npos, "../../img/bullet.png");
    
	explosion1Path.replace(0, std::string::npos, "../../img/particles/explosion1.jpg");
    explosion2Path.replace(0, std::string::npos, "../../img/particles/explosion2.png");
    explosion3Path.replace(0, std::string::npos, "../../img/particles/explosion3.png");
    explosion4Path.replace(0, std::string::npos, "../../img/particles/explosion4.png");

    font1Path.replace(0, std::string::npos, "../../fonts/FixdStation.ttf");

    song1Path.replace(0, std::string::npos, "../../fonts/FixdStation.ttf");


#endif
}