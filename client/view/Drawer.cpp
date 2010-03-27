/*
 * Drawer.cpp
 *
 *  Created on: 26.03.2010
 *      Author: keszocze
 */

#include "Drawer.h"
#include "../model/Blueprint.h"
#include "../model/geometrical_objects.h"
#include <iostream>

using namespace std;

Drawer::Drawer() {
	// TODO Auto-generated constructor stub

}

Drawer::~Drawer() {
	// TODO Auto-generated destructor stub
}

void Drawer::drawLinestrip(Linestrip* pl, int xoffset, int yoffset) {

	int n = pl->getLength();
	struct point* points = pl->getPoints();

	glBegin( GL_LINE_STRIP);
	for (int i = 0; i < n; i++) {
		struct point point = points[i];
		glVertex2f(point.x + xoffset, point.y + yoffset);

	}
	glEnd();
}

void Drawer::drawBlueprint(Blueprint bp, int xoffset, int yoffset) {
	int n = bp.getNPolylines();

	float* color = bp.getColor();

	glColor3f(color[0], color[1], color[2]);

	cout <<endl << "Test" << n << endl;
//	Linestrip* lines = bp.getPolylines();
//
//	for (int i = 0; i < n; i++) {
//		drawLinestrip(&lines[i], xoffset, yoffset);
//	}

}
