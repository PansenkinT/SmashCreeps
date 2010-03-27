/*
 * Drawer.h
 *
 *  Created on: 26.03.2010
 *      Author: PansenkinT
 */

// TODO vermutlich muss das überhaupt keine Klasse sein
#ifndef DRAWER_H_
#define DRAWER_H_

#include "../model/Blueprint.h"
#include "../model/geometrical_objects.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
#include <iostream>

class Drawer {

public:
	void drawLinestrip(Linestrip* pl,int xoffset=0, int yoffset=0);
	void drawBlueprint(Blueprint bp,int xoffset=0, int yoffset=0);
	Drawer();
	virtual ~Drawer();
};

#endif /* DRAWER_H_ */
