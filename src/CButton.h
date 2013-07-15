//
//  CButton.h
//  birdyShmup
//
//  Created by Benjamin Brodeur Mathieu on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include <SDL.h>
#include <SDL_image.h>
#include "CSurface.h"

class CButton {
public:
	CButton();
	~CButton();
	bool onLoad(const char* file);
	void onDraw(SDL_Surface* dest);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getWidth();
	int getHeight();

private:
	SDL_Surface* surfButton_;
	int x_;
	int y_;
};