//
//  FilePaths.h
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-08.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#ifndef __birdyShmup__FilePaths__
#define __birdyShmup__FilePaths__

#include <string>

class FilePaths {
public:
    FilePaths();

    // Player
    std::string player1Path;

    // Ennemies
    std::string entity1Path;
    std::string entity2Path;

    // Background
    std::string backgroundPath;

    // Bullets
    std::string bullet1Path;

    // Particles
    std::string explosion1Path;
    std::string explosion2Path;
    std::string explosion3Path;
    std::string explosion4Path;

};

#endif /* defined(__birdyShmup__FilePaths__) */