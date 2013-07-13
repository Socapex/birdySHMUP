//
//  CMainMenu.h
//  birdyShmup
//
//  Created by Benjamin Brodeur Mathieu on 2013-07-12.
//  Copyright (c) 2013 Groarke and co. All rights reserved.
//

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class CButton {
public:
	CButton();
	~CButton();
	bool onLoad(std::string filePath);
	void onDraw(SDL_Surface* dest,int x, int y);

private:
	SDL_Surface* surfButton_;
	SDL_Rect* rectButton_;
};