//
//  CGUI.cpp
//  birdyShmup
//
//  Created by Philippe Groarke on 2013-06-23.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CGUI.h"

CGUI CGUI::gUI;

CGUI::CGUI()
{
    healthBarBackground_.x = 10;
    healthBarBackground_.y = 10;
    healthBarBackground_.w = 104;
    healthBarBackground_.h = 14;
    healthBar_.x = 12;
    healthBar_.y = 12;
    healthBar_.w = 100;
    healthBar_.h = 10;

    black = {0, 0, 0, 0};

}

CGUI::~CGUI()
{}

void CGUI::onLoad()
{
    FilePaths Path;

    mainFont_ = TTF_OpenFont(Path.font1Path.c_str(), 16);

    if (mainFont_ == NULL)
    {
        printf("Unable to load font: %s %s \n", mainFont_, TTF_GetError());
    }

    TTF_SetFontStyle(mainFont_, TTF_STYLE_BOLD);
}

void CGUI::onLoop(CPlayer* player)
{
    // Check player life
    healthBar_.w = player->getLife() / PLAYER_LIFE * 100;

    pointText_ = std::to_string(player->getPlayerPoints());

    points_ = TTF_RenderText_Solid(mainFont_, pointText_.c_str(), black);

}

void CGUI::onRender(SDL_Surface* surfDisplay)
{
    SDL_FillRect(surfDisplay, &healthBarBackground_,
                 SDL_MapRGB(surfDisplay->format, 0, 0, 0));
    SDL_FillRect(surfDisplay, &healthBar_,
                 SDL_MapRGB(surfDisplay->format, 255, 255, 0));


    CSurface::OnDraw(surfDisplay, points_, WWIDTH / 2 - points_->w, 10);

    

}

void CGUI::onCleanup()
{
    TTF_CloseFont(mainFont_);
}