/*
 * monster.h
 *
 *  Created on: May 27, 2015
 *      Author: Owner
 */
#ifndef MONSTER_H_
#define MONSTER_H_
const char NAMESIZE = 30;
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
	int getmonsinfo();//retrieves monster info

};



#endif /* MONSTER_H_ */
