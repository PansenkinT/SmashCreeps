/*
 * Blueprint.cpp
 *
 *  Created on: 25.03.2010
 *      Author: keszocze
 */

#include "Blueprint.h"
#include "geometrical_objects.h"
#include <iostream>

using namespace std;

Blueprint::Blueprint() {
	nlines=-1;
	npoints=-1;
	npolylines=-1;
	lines=new struct line[0];
	points=new struct point[0];
	polylines=new Linestrip[0];

}

Blueprint::Blueprint(int npol, Linestrip* ls) {
	npolylines=npol;
	polylines = new Linestrip[npolylines];


	for (int i=0;i<npolylines;i++) {
		polylines[i]=ls[i];
	}


	nlines=1;
	lines= new struct line[nlines];

	npoints=1;
	points= new struct point[npoints];
}

Blueprint::~Blueprint() {
	cout << "Destruktor" << endl;
	delete[] lines;
	cout << "Lines weg" << endl;
	delete[] points;
	cout << "Points weg" << endl;
	delete[] polylines;
	cout << "Polylines weg" << endl;
}

int Blueprint::getNLines() {
	return nlines;
}

Linestrip* Blueprint::getPolylines() {
	return polylines;
}

float* Blueprint::getColor() {
	return color;
}

int Blueprint::getNPoints() {
	return npoints;
}

int Blueprint::getNPolylines() {
	return npolylines;
}

void Blueprint::dst(int x, int y) {
    x+=4;
    y+=2;
    glColor3f(0.0f,1.0f,0.0f);

    glBegin(GL_LINE_STRIP);
    glVertex2f(x+0, y+0);
    glVertex2f(x+16, y+1);
    glVertex2f(x+16, y+17);
    glVertex2f(x+0, y+17);
    glVertex2f(x+0, y+0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(x+4, y+4);
    glVertex2f(x+12, y+5);
    glVertex2f(x+12, y+13);
    glVertex2f(x+4, y+13);
    glVertex2f(x+4, y+4);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(x+6, y+6);
    glVertex2f(x+10, y+7);
    glVertex2f(x+10, y+11);
    glVertex2f(x+6, y+11);
    glVertex2f(x+6, y+6);
    glEnd();

    glBegin(GL_POINTS);
    glVertex2f(x+8, y+9);
    glEnd();
}
