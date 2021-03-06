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

     //initialisation des vies
    unsigned int nbLives = NB_STARTING_LIVES;
    unsigned int livesSize = 10;

    for(unsigned int i = 0 ; i < nbLives; ++i)
    {
        SDL_Rect life;
        life.h = life.w = livesSize;
        life.x = 12 + 22*i;
        life.y = 32;
        vLives_.push_back(life);
    }


    getReadyPlaying = false;
    getReadyTime = 3500;
    getReadyCounter = 3;


    points_ = NULL;
    fps_ = NULL;
    getReadySurface_ = NULL;
    pointFont_ = NULL;
    getReadyFont_ = NULL;

    getReadyFont_ = TTF_OpenFont(Path.Files["font1Path"].c_str(), 2);
    pointFont_ = TTF_OpenFont(Path.Files["font1Path"].c_str(), 26);

    if (pointFont_ == NULL)
    {
        printf("Unable to load font: %s %s \n", pointFont_, TTF_GetError());
    }

    TTF_SetFontStyle(pointFont_, TTF_STYLE_BOLD);

}

CGUI::~CGUI()
{
    SDL_FreeSurface(points_);
    SDL_FreeSurface(fps_);
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
    // Check player health
    healthBar_.w = static_cast<int>(player->getHealth() / PLAYER_LIFE * 100 + 0.5);

    // Check player life
    int playerLives = player->getLife();
    int guiLives = vLives_.size();
    if (playerLives != guiLives)
    {
        if (playerLives < guiLives)
            vLives_.pop_back();
        else
            while (playerLives > guiLives++)
                vLives_.push_back(vLives_.front()); //toute les vies sont pareils, on peut
        //donc pusher une deja dans le vector
    }

    // Get player points
    std::stringstream ss;
    ss << player->getPlayerPoints();
    pointText_ = ss.str();
    points_ = TTF_RenderText_Blended(pointFont_, pointText_.c_str(), white);

    // Get fps
    std::stringstream ssfps;
    ssfps << "FPS: " << CFPS::FPSControl.getFPS();
    fps_ = TTF_RenderText_Blended(pointFont_, ssfps.str().c_str(), white);

}

void CGUI::onRender(SDL_Surface* surfDisplay)
{
    SDL_FillRect(surfDisplay, &healthBarBackground_,
                 SDL_MapRGB(surfDisplay->format, 0, 0, 0));
    SDL_FillRect(surfDisplay, &healthBar_,
                 SDL_MapRGB(surfDisplay->format, 255, 255, 0));

    //Vies
    for(unsigned int i = 0; i < vLives_.size(); ++i)
    {
        SDL_FillRect(surfDisplay, &vLives_.at(i), SDL_MapRGB(surfDisplay->format,
                                                             255, 255, 0));
    }

    // Points
    CSurface::OnDraw(surfDisplay, points_, WWIDTH / 2.0f - points_->w, 10.0f);

    // FPS
    CSurface::OnDraw(surfDisplay, fps_, WWIDTH - fps_->w - 10.0f, 10.0f);

    if (getReadyPlaying)
    {
        getReadyFont_ = TTF_OpenFont(Path.Files["font1Path"].c_str(), getReadyCounter);

        getReadySurface_ = TTF_RenderText_Blended(getReadyFont_, "Get Ready!",
                                                  white);
        TTF_SetFontStyle(getReadyFont_, TTF_STYLE_BOLD);

        getReadyCounter += 4;

        if (getReadyCounter >= 64) getReadyCounter = 64;

        CSurface::OnDraw(surfDisplay, getReadySurface_,
                         (WWIDTH / 2) - (getReadySurface_->w / 2.0f),
                         (WHEIGHT / 3) - (getReadySurface_->h / 2.0f));

        if (SDL_GetTicks() > getReadyTime) getReadyPlaying = false;
        
    }

}