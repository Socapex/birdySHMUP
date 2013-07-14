//
//  CButton.cpp
//  birdyShmup
//
//  Created by Benjamin Brodeur Mathieu on 2013-07-13.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include "CButton.h"

CButton::CButton()
{
	rectButton_ = new SDL_Rect();
}

CButton::~CButton()
{
	delete rectButton_;
	rectButton_ = NULL;
}

bool CButton::onLoad(std::string filePath)
{
	return ((surfButton_ = IMG_Load(filePath.c_str())) != NULL);
}

void CButton::onDraw(SDL_Surface* dest,int x, int y)
{
	rectButton_->x = x;
    rectButton_->y = y;
    rectButton_->h = surfButton_->h;
    rectButton_->w = surfButton_->w;
	SDL_BlitSurface(surfButton_, NULL, dest, rectButton_);
}