//
//  CButton.h
//  birdyShmup
//
//  Created by Benjamin Brodeur Mathieu on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//
#ifndef __birdyShmup__CButton__
#define __birdyShmup__CButton__

#include <SDL.h>
#include <SDL_image.h>
#include "CSurface.h"

class CButton {
public:
	CButton();
	~CButton();
	bool onLoad(const char* file);
	void onRender(SDL_Surface* dest);
	void setX(int x);
	void setY(int y);
	void setID(int iD);
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int getID();


private:
	SDL_Surface* surfButton_;
	int x_;
	int y_;
	int iD_;
};
#endif /* defined(__birdyShmup__CButton__) */