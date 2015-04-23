/****************************************************
 * AUTHOR        : Travis Forbes
 * PROJECT       : 250+ line project for csi 17a
 * CLASS         : csc17a
 * SECTION       : T Th 12:45 - 2:10
 * DUE Date      : 4/7/15
* **************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
//global constants
const int SIZE = 50;
//structures
struct player
{
	char name[SIZE];         // name of player
	int armor;               // defense of a player
	int health;              // health of a player
	int str;                 // strength of a player
	int dex;                 // dexterity of a player
	int con;                 // constitution of a player
	int intel;               // intelligence of a player
	int wis;                 // wisdom of a player
	int cha;                 // charisma of a player
};
struct monster
{
	char name[SIZE];         // name of creature
	int armor;               // natural defense of a creature
	int health;              // unmodified health of a creature
	int str;                 // unmodified strength of a creature
	int dex;                 // unmodified dexterity of a creature
	int con;                 // unmodified constitution of a creature
	int intel;               // unmodified intelligence of a creature
	int wis;                 // unmodified wisdom of a creature
	int cha;                 // unmodified charisma of a creature
};
//function prototypes
void intro(player &);
void firstC(player &);
void cliffall(player &);
void battle();
int main()
{
	player p1;               //Structure for payer
	intro(p1);
	firstC(p1);
	srand (time(0));

	return 0;
}
void intro(player & p1)
{
	cout << "what is your name ";
	cin.getline(p1.name, SIZE);
}
void firstC(player & p1)
{
	int choice;                   //Input for choices made in game
	int funstuf;                  //the thing that makes the game hard
	srand (time(0));

    //setting up the story

	cout << "you wake up in a ditch on the side of the road.\n";
	cout << "you don't remember how you got there\n";
	cout << "the name your mother gave you has also been forgotten\n";
	cout << "all you know is the sun is hot and you have a splitting headache\n";
	cout << "Their is a cheap sword next to you and a bow with a quiver of 10 arrows\n";

	//giving player there first choice

	do
	{
		cout << "you hear a rustling in the bushes behind you\n";
		cout << "what do you do?(type the number of your choice and then hit enter)\n";
		cout << "1: run for your life\n";
		cout << "2: pick up the weapons next to you and get ready to fight\n";
		cout << "3: pick up the bow and fire and arrow at where you heard the noise\n";
		cout << "4: play dead and hope whatever it is just passes by\n";
		cout << "5: grab the weapons and run\n";

		//get the players first choice

		cin>>choice;

		//input validation

		if(choice<1 || choice>5)
		{
			cout << "invalid choice pleas make a proper choice\n";
		}
	}while(choice<1 || choice>5);

		//different consequences for players first choice

	if(choice == 1)
		{
		//random options for choice one
			funstuf = rand()%21;
			if(funstuf<=5)
				{
					cout<<"you have no idea what you are running from but you know you did not want\n";
					cout<<"to stay and find out shure you forgot the weapons and are now defenseless\n";
					cout<<"but who knows you might get lucky and find a weapon before you get killed\n";
				}
			else if(funstuf>=6 && funstuf<=13)
				{
					cout<<"you bolt you take off running faster than you ever have all you know is you\n";
					cout<<"do not want to be there only problem is you forgot to grab the weapons and you are not\n";
					cout<<"looking ware you are going and run head long off a cliff.";
					cliffall(p1);
				}
			else if(funstuf>=14 && funstuf<=19)
				{
					cout<<"you bolt you take off running faster than you ever have all you know is you\n";
					cout<<"do not want to be there only problem is you forgot to grab the weapons and you are not\n";
					cout<<"looking ware you are going and run into a a man dressed in full armor Knocking him over\n";
					funstuf = rand()%11;
				if(funstuf<=4)
					{
						cout<<"and knocking him unconscious\n";
						//uconkni
					}
				else
					{
						cout<<"witch just makes him angry";
						//angrkni
					}
				}
			else
				{
					cout<<"you grab the weapons by your side and bolt your scared out of your mind\n";
					cout<<"but you are armed and ready to fight the next time you run into any monster or scary bushes\n";
				}
			}
		//random options for choice 2
		else if(choice == 2)
			{
				funstuf = rand()%20;
			if(funstuf<=10)
				{
					cout<<"you grab the weapons at your feet and take a stand\n";
					cout<<"ready for any thing that could possibly jump out of the bushes";
				if(funstuf<=4)
					{
						cout<<"and...\n a...\n bunny jumps out and runs past you\n";
					}
				else
					{
						funstuf =rand()%5;
					}
				}
			}
		//random options for choice 3
		else if(choice == 3)
			{
				funstuf = rand()%20;
			if(funstuf<=7)
				{
					cout<<"you hear the arrow clang off something hard\n";
					cout<<"a large shadow grows over you\n";
					cout<<"you look up to see a rather angry dragon\n";
				}
			else if(funstuf>7 && funstuf<=15)
				{
					cout<<"you hear the dull thud of the arrow driving in to a tree\n";
					cout<<"this either means you missed whatever made the noise\n";
					cout<<"you imagined the noise to begin with\n";
					cout<<"now what do you do\n";
					cout<<"1: pick up the arrow\n";
					cout<<"2: leave the arrow their and start down the road\n";
					cout<<"3: shoot another arrow just to be on the safe side\n";
					cin>>choice;
				}
			else
				{
				do
					{
						cout<<"you hear the thud of the arrow drive in to the flesh of some unseen animal\n";
						cout<<"witch you then hear run away\n";
						cout<<"do you attempt to chase it down/n 1: yes\n 2: no\n";
						cin>>choice;
					}while(choice <= 1 || choice >= 2);
				if(choice==1)
					{
					    cout<<"you chase after it hoping that it was a fatal wound"<<endl;
						cout<<"but because this is the beginning of your life as an adventurer"<<endl;
						cout<<"you trip over the first tree root you come across and bloody your"<<endl;
						cout<<"face on the rocky ground you get up and start to stumble down the road"<<endl;
				    }
				else
					{
						cout<<"you decide what ever it was you shot is not worth chasing after\n";
						cout<<"and head down the road";
					}
				}
			}
	    //random options for choice 4
		else if(choice == 4)
			{
				funstuf = rand()%20;
				if(funstuf <= 10)
				{
					cout<<"you lay back down as fast as you can and pretend to be dead\n";
					cout<<"(witch as the narator I would like to point out is just a stupid idea I mean\n";
					cout<<"who just lays down and plays dead well obviously you do but back to the story)\n";
					cout<<"you lay there paralyzed in fear but after 20 minutes without another noise in the bushes\n";
					cout<<"or any ware else you get up grab the weapons next to you and head down the road\n";
				}
				else if(funstuf==12)
				{
					cout<<"right as you are about to lay down the creature making the noise sees you and it a\n";
					cout<< 1 <<" witch looks very angry";

				}
				else
				{
					cout<<"you lay back down as fast as you can and pretend to be dead\n";
					cout<<"(witch as the narator I would like to point out is just a stupid idea I mean\n";
					cout<<"who just lays down and plays dead well obviously you do but back to the story)\n";
					cout<<"the rustling comes again closer this time\n then again even closer";
					if(funstuf<5)
					{
						cout<<"then you see it through your almost closed eyes a...\n bunny";
					}
				}
			}
		//option for choice 5
		else if(choice == 5)
			{
				cout<<"you grab the weapons by your side and bolt scared out of your mind\n";
				cout<<"but your armed and ready to fight the next time you run into any monster or scary bushes\n";
			}
}

// function when you fall off a cliff

void cliffall(player & p1)
{
	int choice;
	srand (time(0));
	int op;
	cout << "you tumble down the cliff gaining speed as you go\n";
	cout << "as you fall you notice a large branch approaching \n";
	do
	{
	cout << "do you try to avoid or try to grab the branch\n";
	cout << "1: try to avoid\n 2: try to grab";
	cin >> choice;
	}while(choice <= 1 || choice >= 2);
	//random options if try to avoid branch
	if(choice == 1)
	{
		op = rand()%7;
		if(op <= 3)
		{
			cout << "you try to avoid the branch\n but you are not fast enough to roll out of the way\n";
			cout << "and bash your skull against the branch witch knocks you unconscious\n";
			cout << "while you are unconscious you fall face down in a river\n";
			cout << "and drown and because there was no one there to save you your dead\n";
			cout << "thanks for playing\n";
		}
		else if(op >3 ||op <= 5)
		{
			cout << "you some how manage to avoid the branch but not with out a hiccup\n";
			cout << "the way you rolled to avoid the branch caused you to roll over a\n";
			cout << "a bee hive and because these are some sort of super bee\n";
			cout << "they injected more apitoxin than a normal bee\n";
			cout << "causing you to go in to anifilactic shock killing you\n";
			cout << "befor you hit the ground\n";
			cout << "thanks for playing\n";
		}
		else
		{
			cout << "you success fully dodge the root but not with out taking some\n";
			cout << "fall damage\n minus 15 damage";
			p1.health -= 20;

		}
	}
	//random options if try to grab branch
}

void battle()
{

}
