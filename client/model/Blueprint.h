/*
 * Blueprint.h
 *
 *  Created on: 25.03.2010
 *      Author: PansenkinT
 */

#ifndef BLUEPRINT_H_
#define BLUEPRINT_H_

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>

#include "geometrical_objects.h"

class Blueprint {
private:
	float color[3];
	int nlines;
	int npoints;
	int npolylines;
	struct line* lines;
	struct point* points;
	Linestrip* polylines;
public:
	int getNLines();
	int getNPoints();
	int getNPolylines();
	Linestrip* getPolylines();
	float* getColor();
	Blueprint();
	virtual ~Blueprint();
	void dst(int x, int y);
	Blueprint(int npol, Linestrip* ps);
};

#endif /* BLUEPRINT_H_ */
