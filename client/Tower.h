/*
 * Tower.h
 *
 *  Created on: 24.03.2010
 *      Author: PansenkinT
 */

#ifndef TOWER_H_
#define TOWER_H_

#include <string>
using namespace std;

class Tower {
private:
	short* price;
	short* sellPrice;
	short* damage;
	short nUpdates;
	short level;
	string name;

public:
	Tower();
	Tower(short* p,short* sellp, short* d,short nup,string n);
	virtual ~Tower();
	short getPrice();
	short getSellPrice();
	short getDamage();
	short getLevel();
	short getNUpdates();
	string getName();
};

#endif /* TOWER_H_ */
