//
//  Level1.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "Level1.h"

Level1::Level1()
{
    FilePaths Path;

    // ENEMIES
    enemySpawner_ = new CEnemySpawner();


    // BACKGROUND
    background1_ = new CBackground(Path.Files["backgroundPath"].c_str());
	parallax1_ = new CBackground(Path.Files["parallaxPath"].c_str());
	parallax1_->setBackgroundLevel(BACKGROUND_SCROLL_SPEED_LEVEL_4);

    parallax2_ = new CBackground(Path.Files["parallax2Path"].c_str());
    parallax2_->setBackgroundLevel(BACKGROUND_SCROLL_SPEED_LEVEL_2);


    // MUSIC
    music_ = new CMusic(Path.Files["song1Path"].c_str());
    music_->play();


    // TEST
    CParticles* explody = new CParticles(255, 255, 0, 400, 50, 5, 8, 0, 1000,
                                         100, 10, "fireworks");

    explody->play(400, 50);
    //    CParticles* explody2 = new CParticles("explosion3", 400, 200, 1000, 10000,
    //                                      10, 10);
}

Level1::~Level1()
{

}

void Level1::onLoop(CPlayer *Player)
{
    CLevel::onLoop(Player);
}

void Level1::onRender(SDL_Surface *surfDisplay_)
{
    CLevel::onRender(surfDisplay_);
}