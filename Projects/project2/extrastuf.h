
#ifndef EXTRASTUF_H_
#define EXTRASTUF_H_
#include "string"
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
#endif /* EXTRASTUF_H_ */
