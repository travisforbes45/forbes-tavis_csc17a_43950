/*
 * spell.h
 *
 *  Created on: May 26, 2015
 *      Author: Owner
 */

#ifndef SPELL_H_
#define SPELL_H_
#include <iostream>
#include <string>
const char SPELSIZ = 30;
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


#endif /* SPELL_H_ */
