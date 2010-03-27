/*
 * Tower.cpp
 *
 *  Created on: 24.03.2010
 *      Author: PansenkinT
 */

#include "Tower.h"


Tower::Tower(short* p,short* sellp, short* d,short* r,short nup,string n) {
	price = new short[nup];
	sellPrice=new short[nup];
	damage=new short[nup];
	range=new short[nup];
	// TODO check wether allocation worked?


	for (short i=0;i<nup;i++) {
		price[i]=p[i];
		sellPrice[i]=sellp[i];
		damage[i]=d[i];
		range[i]=r[i];
	}
	level=0;
	name=n;
}


Tower::Tower() {
	price=new short[1];
	sellPrice=new short[1];
	damage=new short[1];
	price[0]=-1;
	sellPrice[0]=-1;
	damage[0]=-1;
	nUpdates=-1;
	level=-1;

	name="unknown tower";

}

Tower::~Tower() {
	delete[] sellPrice;
	delete[] damage;
	delete[] price;
}

short Tower::getPrice() {
	return price[level];
}

short Tower::getRange() {
	return range[level];
}

short Tower::getSellPrice() {
	return sellPrice[level];
}
short Tower::getDamage() {
	return damage[level];
}

short Tower::getLevel() {
	return level;
}

short Tower::getNUpdates() {
	return nUpdates;
}
string Tower::getName() {
	return name;
}
