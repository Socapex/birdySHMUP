//
//  CGUI.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-23.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CGUI.h"


CGUI::CGUI()
{
    // Barre de vie
    healthBarBackground_.x = 10;
    healthBarBackground_.y = 10;
    healthBarBackground_.w = 104;
    healthBarBackground_.h = 14;
    healthBar_.x = 12;
    healthBar_.y = 12;
    healthBar_.w = 100;
    healthBar_.h = 10;
	
	//Louche, lorsqu'on initialise toute la structure en meme temps,
	//VS n'aime pas ca... Comme au-dessus, je vais initialiser chaque
	//champ un par un.
	/*
    black = {0, 0, 0, 0};
    white = {255, 255, 255, 0};
	*/

	black.r = 0;
	black.g = 0;
	black.b = 0;
	black.unused = 0;

	white.r = 255;
	white.g = 255;
	white.b = 255;
	white.unused = 0;


    getReadyPlaying = false;
    getReadyTime = 3500;
    getReadyCounter = 3;


    points_ = NULL;
    getReadySurface_ = NULL;
    pointFont_ = NULL;
    getReadyFont_ = NULL;

    getReadyFont_ = TTF_OpenFont(Path.font1Path.c_str(), 2);
    pointFont_ = TTF_OpenFont(Path.font1Path.c_str(), 26);

    if (pointFont_ == NULL)
    {
        printf("Unable to load font: %s %s \n", pointFont_, TTF_GetError());
    }

    TTF_SetFontStyle(pointFont_, TTF_STYLE_BOLD);

}

CGUI::~CGUI()
{
    SDL_FreeSurface(points_);
    SDL_FreeSurface(getReadySurface_);
    
    TTF_CloseFont(pointFont_);
    TTF_CloseFont(getReadyFont_);
}












void CGUI::getReady()
{
    getReadySurface_ = TTF_RenderText_Blended(getReadyFont_, "Get Ready!", white);
    TTF_SetFontStyle(getReadyFont_, TTF_STYLE_BOLD);
    getReadyPlaying = true;
    
}

void CGUI::onLoop(CPlayer* player)
{
    // Check player life
    healthBar_.w = player->getLife() / PLAYER_LIFE * 100;

    /******************* POUR BEN :D**********************/

    std::stringstream ss;

    ss << player->getPlayerPoints();


    pointText_ = ss.str();

    points_ = TTF_RenderText_Blended(pointFont_, pointText_.c_str(), white);

}

void CGUI::onRender(SDL_Surface* surfDisplay)
{
    SDL_FillRect(surfDisplay, &healthBarBackground_,
                 SDL_MapRGB(surfDisplay->format, 0, 0, 0));
    SDL_FillRect(surfDisplay, &healthBar_,
                 SDL_MapRGB(surfDisplay->format, 255, 255, 0));


    CSurface::OnDraw(surfDisplay, points_, WWIDTH / 2 - points_->w, 10);

    if (getReadyPlaying)
    {
        getReadyFont_ = TTF_OpenFont(Path.font1Path.c_str(), getReadyCounter);

        getReadySurface_ = TTF_RenderText_Blended(getReadyFont_, "Get Ready!",
                                                  white);
        TTF_SetFontStyle(getReadyFont_, TTF_STYLE_BOLD);

        getReadyCounter += 4;

        if (getReadyCounter >= 64) getReadyCounter = 64;

        CSurface::OnDraw(surfDisplay, getReadySurface_,
                         (WWIDTH / 2) - (getReadySurface_->w / 2),
                         WHEIGHT / 3) - (getReadySurface_->h / 2);

        if (SDL_GetTicks() > getReadyTime) getReadyPlaying = false;
        
    }

}