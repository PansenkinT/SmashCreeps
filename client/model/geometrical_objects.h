/*
 * geometrical_objects.h
 *
 *  Created on: 26.03.2010
 *      Author: PansenkinT
 */

#ifndef GEOMETRICAL_OBJECTS_H_
#define GEOMETRICAL_OBJECTS_H_
struct line {
	int startx;
	int starty;
	int endx;
	int endy;
};

struct point {
	int x,y;
};


class Linestrip {
private:
	int length;
	struct point* points;
public:
	Linestrip(int n=0,struct point* ps=0);
	virtual ~Linestrip();
	struct point* getPoints();
	int getLength();
};



#endif /* GEOMETRICAL_OBJECTS_H_ */
