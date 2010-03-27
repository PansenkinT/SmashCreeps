/*
 * geometrical_objects.cpp
 *
 *  Created on: 27.03.2010
 *      Author: PansenkinT
 */

#include "geometrical_objects.h"
#include <iostream>

using namespace std;

Linestrip::Linestrip(int n, point* ps) {
	length=n;

	points=new struct point[length];

	for (int i=0;i<length;i++) {
		points[i]=ps[i];
	}
}

struct point* Linestrip::getPoints() {
	return points;
}

int Linestrip::getLength() {
	return length;
}

Linestrip::~Linestrip() {
	cout << "Linestrip destruktor" << endl;
	delete[] points;
}
