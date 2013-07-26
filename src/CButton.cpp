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
	x_ = 0;
	y_ = 0;
}

CButton::~CButton()
{
	SDL_FreeSurface(surfButton_);
}

bool CButton::onLoad(const char* file)
{
	if ((surfButton_ = CSurface::onLoad(file)) == NULL) return false;

	return true;
}

void CButton::onRender(SDL_Surface* dest)
{
	CSurface::OnDraw(dest, surfButton_, x_, y_);
}

void CButton::setX(int x)
{
	x_ = x;
}

void CButton::setY(int y)
{
	y_ = y;
}

void CButton::setID(int iD)
{
	iD_ = iD;
}

int CButton::getX()
{
	return x_;
}

int CButton::getY()
{
	return y_;
}

int CButton::getWidth()
{
	return surfButton_->w;
}

int CButton::getHeight()
{
	return surfButton_->h;
}

int CButton::getID()
{
	return iD_;
}