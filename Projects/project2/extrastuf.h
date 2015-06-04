/*
 * extrastuf.h
 *
 *  Created on: Jun 4, 2015
 *      Author: Owner
 */

#ifndef EXTRASTUF_H_
#define EXTRASTUF_H_
const char NAMESIZE = 30;
//class for monsters in game
class monster
{
private:
	int monshp;//health of monster
	int power;//power of monster
	int defnce; //armor of monster
	int xppoint;//experience point worth of monster
	char name[NAMESIZE];//name of monster
public:
	monster(int,int,int,int,char[NAMESIZE]);//constructor/set up monsters
	int getmhealth();//retrieves monster health
	int getmpow();//retrieves monster power
	int getmxp();//retrieves monster xp point worth
	char getmname();//retrieves monsters name
	int getmdef();//retrieves monsters armor
};

const char SPELSIZ = 30;
//spell class declaration
class spell
{
private:
	char name[SPELSIZ];   //name of spell
	int manaCost;  //cost to cast the spell
	int cost;      //cost to buy spell
	int damage;    //damage spell does
	bool equip; //boolean statement for if spell is equipped or not
public:
	spell(int,int,int,bool,char[SPELSIZ]); //constructor/set up spells
	void setspell(); //set up spells
    int getspellinfo();   //displays info about spell
    void Equip(); //equip or unequip spells

};

const char WEAPONSIZE = 30;
//weapon class declaration
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

#endif /* EXTRASTUF_H_ */
