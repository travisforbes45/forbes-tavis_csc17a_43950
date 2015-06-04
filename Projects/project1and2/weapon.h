/*
 * weapon.h
 *
 *  Created on: May 26, 2015
 *      Author: Owner
 */

#ifndef WEAPON_H_
#define WEAPON_H_
const char WEAPONSIZE = 30;
class weapon
{
private:
	int power; //damage of weapon
	int cost;// cost of weapon
	char name[WEAPONSIZE];//name of weapon
	bool equip;//if weapon is equipped
public:
	weapon(int,int,char[WEAPONSIZE],bool);//constructor/set up weapons
	int getwepinfo();//retrieves weapon info
	bool equipweapon();//equip or unequip weapon
};




#endif /* WEAPON_H_ */
