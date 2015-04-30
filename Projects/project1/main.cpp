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
#include <fstream>
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
	int xp;					 // experience points of player
	int maxh;                // max health of player
};
struct monster
{
	char name[SIZE];         // name of creature
	int armor;               // natural defense of a creature
	int health;              // unmodified health of a creature
	int str;                 // unmodified strength of a creature
	int xp;					 // experience points gained when defeated
};
struct nonplayer
{
	char name[SIZE];         // name of npc
	int armor;               // natural defense of a npc
	int health;              // unmodified health of a npc
	int str;                 // unmodified strength of a npc
	int xp;					 // experience point gained when defeated
};
//function prototypes
void intro(player &);                   // introduction of game function
void firstC(player &);                  // first choice in game
void cliffall(player &);                // fall from cliff function
void battle(player &);       // battle sequence
void shack(player &);                   // come across a shack function
void path(player &);                    // travel function
void cblater(player&);                  // save function
void pit(player&);						// if path covers a pit
void inn(player&);						// come across an inn
void town(player&);						// when come to a town
int startmen();							// start menu function
void load(player&);                     // load player data function

int main()
{
	player p1;               //Structure for payer
	srand (time(0));
	int schoice;             // start menu choice
	do
	{
	// run start menu
	schoice = startmen();
	// new game
	if(schoice == 1)
	{
	intro(p1);
	firstC(p1);
	}
	// continue game
	else if(schoice == 2)
	{
		load(p1);
		path(p1);
	}
	// quit game
	else
	{
		cout << "thanks for playing hope to see you back soon";
	}
	}while(schoice != 3);
	return 0;
}

int startmen()
{
	int choice;
	cout << "type number of your choice and then press enter\n";
	cout << "1: new game\n";
	cout << "2: continue game\n";
	cout << "3: quit game\n";
	cin >> choice;
	return choice;
}

void intro(player & p1)
{
	//giving basic game info
	cout << "this is a text based adventure game with you\n";
	cout << "as the hero\n";
	cout << "when a choice is offered to you\n";
	cout << "type the number that corresponds with your\n";
	cout << "choice then press enter\n";
	//getting players name
	cout << "what is your name (enter your name then press enter)";
	cin.ignore(1);
	cin.getline(p1.name, SIZE);
	//Setting base status for player
	p1.armor = 17;
	p1.health = 100;
	p1.str = 15;
	p1.xp = 0;
	p1.maxh = 100;

	cout << "your adventure begins now\n";
}
void firstC(player & p1)
{
	int choice;                   //Input for choices made in game
	int funstuf;                  //the thing that makes the game hard
	srand (time(0));

    //setting up the story

	cout << "you wake up in a ditch on the side of the road.\n";
	cout << "you don't remember how you got there\n";
	cout << "all you know is the sun is hot and you have a splitting headache\n";
	cout << "Their is a cheap sword next to you and a bow with a quiver of 10 arrows\n";

	//giving player there first choice

	do
	{
		cout << "you hear a rustling in the bushes behind you\n";
		cout << "what do you do?\n";
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
					path(p1);
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
						cout<<"you are not sure if you should run before he wakes up\n";
						cout << "or try and grab what you can then run\n";
						do
						{
						cout << "1: run\n2: pillage\n";
						cin >> choice;
						if(choice < 1 || choice > 2)
							{
								cout << "invalid input try again";
							}
						}while(choice < 1 || choice > 2);
						if(choice == 1)
						{
							cout << "you decide that there is to big a risk\n";
							cout << "in trying to take any thing from him\n";
							cout << "and just start running down the road hoping\n";
							cout << "that he does not see your face\n";
							path(p1);
						}
						else
						{
							cout << "you try to see what you can get\n";
							cout << "off of him before he wakes up but\n";
							cout << "all his equipment is to heavy for you\n";
							cout << "to carry as you realize there is nothing\n";
							cout << "for you to steal he wakes up\n";
							cout << "he grabs you by the throat and starts\n";
							cout << "to squeeze the life out of you you try to\n";
							cout << "pull his hand of but he is to strong\n";
							cout << "and after a few minutes of struggling you die\n";
							cout << "thanks for playing\n";
						}
					}
				else
					{
						cout<<"witch just makes him angry\n";
						cout << "you hear him scream profanitys as you run away\n";
						cout << "all you know is you hope he never finds you\n";
						path(p1);
					}
				}
			else
				{
					cout<<"you grab the weapons by your side and bolt your scared out of your mind\n";
					cout<<"but you are armed and ready to fight the next time you run into any monster or scary bushes\n";
					path(p1);
				}
			}
		//random options for choice 2
		else if(choice == 2)
			{
				funstuf = rand()%20;
					cout<<"you grab the weapons at your feet and take a stand\n";
					cout<<"ready for any thing that could possibly jump out of the bushes";
				if(funstuf<=4)
					{
						cout<<"and...\n a...\n bunny jumps out and runs past you\n";
						path(p1);
					}
				else
				    {
						battle(p1);
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
					cout << "he opens his jaws you see the orange glow\n";
					cout << "in the back of its throat and next thing you know\n";
					cout << "your dead\n";
					cout << "thanks for playing\n";
				}
			else if(funstuf>7 && funstuf<=15)
				{
					cout<<"you hear the dull thud of the arrow driving in to a tree\n";
					cout<<"this either means you missed whatever made the noise\n";
					cout<<"you imagined the noise to begin with\n";
					cout<<"and not wanting to find out witch option\n";
					cout << "is right you take off down the road\n";
					path(p1);
				}
			else
				{
				do
					{
						cout<<"you hear the thud of the arrow drive in to the flesh of some unseen animal\n";
						cout<<"witch you then hear run away\n";
						cout<<"do you attempt to chase it down/n 1: yes\n 2: no\n";
						cin>>choice;
						if(choice < 1 || choice > 2)
						{
							cout << "invalid input try again";
						}
					}while(choice <= 1 || choice >= 2);
				if(choice==1)
					{
					    cout<<"you chase after it hoping that it was a fatal wound"<<endl;
						cout<<"but because this is the beginning of your life as an adventurer"<<endl;
						cout<<"you trip over the first tree root you come across and bloody your"<<endl;
						cout<<"face on the rocky ground you get up and start to stumble down the road"<<endl;
						path(p1);
					}
				else
					{
						cout<<"you decide what ever it was you shot is not worth chasing after\n";
						cout<<"and head down the road";
						path(p1);
					}
				}
			}
	    //random options for choice 4
		else if(choice == 4)
			{
				funstuf = rand()%20;
				if(funstuf <= 7)
				{
					cout<<"you lay back down as fast as you can and pretend to be dead\n";
					cout<<"(witch as the narator I would like to point out is just a stupid idea I mean\n";
					cout<<"who just lays down and plays dead well obviously you do but back to the story)\n";
					cout<<"you lay there paralyzed in fear but after 20 minutes without another noise in the bushes\n";
					cout<<"or any ware else you get up grab the weapons next to you and head down the road\n";
					path(p1);
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
						cout << "you feel stupid and head down the road\n";
						path(p1);
					}
					else
					{
						cout << "you hope what ever was out there just leaves you alone\n";
						cout << "but your not that lucky after a few minutes of laying on\n";
						cout << "the ground not hearing anything you think your safe and stand up\n";
						cout << "you hear the twang of a bow string releasing\n";
						cout << "then a sharp pain spreads through your chest you look\n";
						cout << "down and see the sorse of the pain the end of an arrow \n";
						cout << "is sticking out of your gut you start to feel like you are going to\n";
						cout << "faint but while your still conchus you have one choice to make\n";
						do
						{
							cout << "do you\n" << "1: pull the arrow out\n2: leave the arrow in\n";
							cin >> choice;
							if(choice < 1 || choice > 2)
							{
								cout << "invalid choice\n";
							}
						}while(choice < 1 || choice > 2);
						if(choice == 1)
						{
							cout << "you rip the arrow free not thinking if it has a\n";
							cout << "barbed head or not as you pull it free you notice\n";
							cout << "some thing your guts are coming out attached to the end\n";
							cout << "of the arrow with your last breath you curse the idiot\n";
							cout << "who shot you and your self for pulling it out\n";
							cout << "thanks for playing\n";
						}
						else
						{
							cout << "you decide it is to great a risk to pull the arrow out\n";
							cout << "not knowing if is barbed or not as your consus fades\n";
							cout << "you realize that you are having trouble breathing\n";
							cout << "and slowly realize that the arrow was poisend\n";
							cout << "you pass out and shortly after die\n";
							cout << "thanks for playing";
						}
					}
				}
			}
		//option for choice 5
		else if(choice == 5)
			{
				cout<<"you grab the weapons by your side and bolt scared out of your mind\n";
				cout<<"but your armed and ready to fight the next time you run into any monster or scary bushes\n";
				path(p1);
			}
}

// function when you fall off a cliff

void cliffall(player & p1)
{
	int choice;
	srand (time(0));
	int op;
	cout << "you tumble down the cliff gaining speed as you go\n";
	cout << "as you fall you notice a large root approaching \n";
	do
	{
	cout << "do you try to avoid or try to grab the root\n";
	cout << "1: try to avoid\n2: try to grab";
	cin >> choice;
	if(choice < 1 || choice > 2)
		{
			cout << "invalid input try again";
		}
	}while(choice < 1 || choice > 2);
	//random options if try to avoid root
	if(choice == 1)
	{
		op = rand()%7;
		if(op <= 3)
		{
			cout << "you try to avoid the root\n"<<"but you are not fast enough to roll out of the way\n";
			cout << "and bash your skull against the branch witch knocks you unconscious\n";
			cout << "while you are unconscious you fall face down in a river\n";
			cout << "and drown and because there was no one there to save you your dead\n";
			cout << "thanks for playing\n";
		}
		else if(op >3 ||op <= 5)
		{
			cout << "you some how manage to avoid the root but not with out a hiccup\n";
			cout << "the way you rolled to avoid the root caused you to roll over a\n";
			cout << "a bee hive and because these are some sort of super bee\n";
			cout << "they injected more apitoxin than a normal bee\n";
			cout << "causing you to go in to anifilactic shock killing you\n";
			cout << "before you hit the ground\n";
			cout << "thanks for playing\n";
		}
		else
		{
			cout << "you success fully dodge the root and\n";
			cout << "land on the ground but not with out taking some\n";
			cout << "fall damage minus 15 damage\n";
			cout << "after deciding it is better to limp down the road\n";
			cout << "then siting there crying like a girl\n";
			cout << "you start down the path\n";
			p1.health -= 20;
			path(p1);
		}
	}
	//random options if try to grab the root
	else
	{
		op = rand()%7;
		if(op <= 3)
		{
			cout << "you reach for the branch and grab hold\n";
			cout << "but it is not strong enough to hold your fat but\n";
			cout << "so all you did was slow your fall\n";
			if(op < 5)
			{
				cout << "sadly for you it is not enough for you\n";
				cout << "you look down to see that the valley is filled\n";
				cout << "with large rather sharp looking rocks\n";
				cout << "you curse your self for running in the first place\n";
				cout << "before you have time to see your life flash before\n";
				cout << "your eyes you are impaled by the rocks and die\n";
				cout << "thanks for playing\n";
			}
			else
			{
				cout << "and lucky for you there is flat ground at the bottom\n";
				cout << "land on the ground but not with out taking some\n";
				cout << "fall damage minus 15 damage\n";
				cout << "after deciding it is better to limp down the road\n";
				cout << "then siting there crying like a girl\n";
				cout << "you start down the path\n";
				p1.health -= 20;
				path(p1);
			}
		}
		else if(op >3 || op < 5)
		{
			cout << "you attempt to reach for the root but were to slow and\n";
			cout << "fell right past it\n";
			cout << "as you fall you contemplate the futility of life\n";
			cout << "and why you did not listen to your mothers advice\n";
			cout << "and been a butcher instead of a adventurer\n";
			cout << "when you finally hit the ground you hit with such force that\n";
			cout << "it liquefies your insides and you become a soup bag\n";
			cout << "yes that means your are dead\n";
			cout << "thanks for playing;";
		}
		else
		{
			cout << "sweet man you actshuly grabbed the root\n";
			cout << "i'm surprised you actuly did it\n";
			do
			{
			cout << "now do you try to climb up or drop down\n";
			cout << "1: climb up\n2: drop down";
			cin >> choice;
			if(choice < 1 || choice > 2)
			{
				cout << "invalid input try again";
			}
			}while(choice < 1 || choice > 2);
			if(choice == 1)
			{
				cout << "you start to climb\n";
				if(op < 5)
				{
					cout << "as you climb you get tiered\n";
					cout << "and the top is so far off\n";
					cout << "you reach with you wearied hand for a hand hold\n";
					cout << "you miss the hand hold and fall\n";
					cout << "this time to tired to reach for the root\n";
					cout << "and fall to your death\n";
					cout << "thanks for playing\n";
				}
				else
				{
					cout << "you make it to the top\n";
					cout << "catch your breath and head down the road\n";
					path(p1);
				}
			}
			else
			{
				cout << "you look down and see a river\n";
				cout << "you drop knowing you are to tired to climb up\n";
				cout << "but to your surprise the river was not very deep\n";
				cout << "your legs lock and shove strait up through your shoulders\n";
				cout << "I am not sure if you died from the pain the blood loss\n";
				cout << "or the fact that your leg bones are not where they should be\n";
				cout << "thanks for playing\n";
			}
		}
	}
}

void battle(player & p1)
{
	monster monst;
	int choice;
	int modi;
	int attack;
	int deffend;
	monst.armor = 12;
	monst.health = 100;
	monst.str = 20;
	monst.xp = 100;
	cout << "a " << "monster" << " attacks\n";
	while(p1.health > 0 && monst.health > 0)
	{
		cout << left <<setw(20) << "your health: " << p1.health <<endl;
		cout << setw(20) << "monsters health: " << monst.health << endl;
		cout << "what do you do\n";
		cout << "1: attack\n2: defend\n";
		cin >> choice;
		if(choice == 1)
		{
			modi = rand()%20;
			attack = p1.str + modi;
			attack = attack - monst.armor;
			cout << "you did " << attack << " damage\n";
			monst.health = monst.health - attack;
			deffend = p1.armor;
		}
		else
		{
			modi = rand()%25;
			deffend = p1.armor + modi;
		}
		if(monst.health <= 0)
		{
			cout << "wow you killed it you get " << monst.xp << "xp points\n";
			p1.xp = p1.xp + monst.xp;
		}
		if(monst.health > 0)
		{
		modi = rand()%10;
		attack = monst.str + modi;
		attack = attack - deffend;
		if(attack > 0)
		{
		p1.health = p1.health - attack;
		cout << attack << " damage is dealt to you\n";
		}
		else
		{
			cout << "miss\n";
		}
		}
	}
	if(p1.health >= 0)
	{
		path(p1);
	}
	else
	{
		cout << "it was a valiant effort but you were defeated\n";
	}
}

void path(player & p1)
{
	int save;
	int op;
	do
	{
		cout << "do you want to save your progress\n";
		cout << "1: save\n2: don't save\n";
		cin >> save;
		if(save < 1 || save > 2)
			{
				cout << "invalid choice";
			}
	}while(save < 1 || save > 2);
	if(save == 1)
	{
	cblater(p1);
	}
	op  = rand()%100;
	if(op >= 1 && op<50)
	{
		battle(p1);
	}
	else if(op > 49 && op < 70)
	{
		shack(p1);
	}
	else if(op >69 && op < 80)
	{
		cliffall(p1);
	}
	else if(op > 79 && op < 85)
	{
		inn(p1);
	}
	else if(op > 84 && op < 90)
	{
		pit(p1);
	}
	else
	{
		town(p1);
	}
}

void shack(player & p1)
{
	int op;
	int choice;
	cout << "you come to a ";
	op=rand()%100;
	if(op <= 30)
	{
		cout << "shack\n";
		cout << "you approach the door\n";
		cout << "do you\n1: open the door\n2:leave";
		cin >> choice;
		if(choice == 2)
		{
			cout << "you decide not to investigate and head down the road";
			path(p1);
		}
		else
		{
			cout << "you open the door and step in side\n";
			cout << "Theirs a flash of light and a blast of heat\n";
			cout << "you just walked over a trip wire bomb don't you\n";
			cout << "fell smart at least you wont make that mistake again\n";
			cout << "because your dead thanks for playing\n";
		}
	}
	else if(op == 31)
	{
		cout << "shack\n";
		cout << "you approach the door\n";
		cout << "do you\n1: open the door\n2:leave";
		cin >> choice;
		if(choice == 2)
		{
			cout << "you decide not to investigate and head down the road";
			path(p1);
		}
		else
		{
			cout << "you open the door and step inside\n";
			cout << "you do a double take as you notice\n";
			cout << "that the inside is bigger than the outside\n";
			cout << "the door slams shut behind you\n";
			cout << "you hear a strange unnatural sound\n";
			cout << "the whole thing starts to shake\n";
			cout << "some thing hits you over the head knocking you unconscious\n";
			firstC(p1);
		}

	}
	else if(op > 31 || op<45)
	{
		cout << "shack\n";
		cout << "you approach the door\n";
		cout << "do you\n1: open the door\n2:leave";
		cin >> choice;
		if(choice == 2)
		{
			cout << "you decide not to investigate and head down the road";
			path(p1);
		}
		else
		{
			cout << "you open the door and step inside\n";
			cout << "to find it is abandond with nothing for you to take\n";
			cout << "so you turn around and head down the road\n";
			path(p1);
		}
	}
	else if(op > 44 && op < 70)
	{
		cout << "shack\n";
		cout << "you approach the door\n";
		cout << "do you\n1: open the door\n2:leave";
		cin >> choice;
		if(choice == 2)
		{
			cout << "you decide not to investigate and head down the road";
			path(p1);
		}
		else
		{
			cout << "you open the door and step inside\n";
			cout << "but you don't relay step you more or less fall\n";
			cout << "and continue to fall for a very long time\n";
			cout << "when you see the bottom you know your going to die\n";
			cout << "when you hit thanks for playing\n";
		}
	}
	else if(op > 69 && op < 90)
	{
		cout << "shack\n";
		cout << "you approach the door\n";
		cout << "do you\n1: open the door\n2:leave";
		cin >> choice;
		if(choice == 2)
		{
			cout << "you decide not to investigate and head down the road";
			path(p1);
		}
		else
		{
			cout << "you open the door and step inside\n";
			cout << "then comes the scream of a psychopath\n";
			cout << "and fell the blade as it cuts through your \n";
			cout << "thanks for playing\n";
		}
	}
	else
	{
		cout << "shack\n";
		cout << "you approach the door\n";
		cout << "do you\n1: open the door\n2:leave";
		cin >> choice;
		if(choice == 2)
		{
			cout << "you decide not to investigate and head down the road";
			path(p1);
		}
		else
		{
			cout << "you open the door and step inside\n";
			cout << "the faint sound of snoring reaches your ears\n";
			cout << "you realize the house is occupied and not wanting\n";
			cout << "to wake the people sleeping up you leave\n";
		}
	}
}

void cblater(player & p1)
{
	fstream playerdat("save.dat", ios::out | ios::binary);
	playerdat.write(reinterpret_cast<char *>(&p1),sizeof(p1));
	cout << "name " << p1.name << endl << "health " << p1.health << endl;
	cout << "xp " << p1.xp << endl << "strength " << p1.str << endl << "armor " << p1.armor << endl;
}

void load(player & p1)
{
	fstream file;
	file.open("save.dat", ios::in | ios::out | ios::binary);

	if (file.fail())
	{
	    cout << "ERROR: Cannot open the file..." << endl;
	}
	else
	{
	/*file.read(p1.name, sizeof(p1.name));
	file.read(reinterpret_cast<char *>(&p1.armor), sizeof(p1.armor));
	file.read(reinterpret_cast<char *>(&p1.health), sizeof(p1.health));
	file.read(reinterpret_cast<char *>(&p1.str), sizeof(p1.str));
	file.read(reinterpret_cast<char *>(&p1.xp), sizeof(p1.xp));
	*/
		//fstream file;
		//file.open("monster.dat", ios::in | ios::out | ios::binary);

		if (file.fail())
		{
		    cout << "ERROR: Cannot open the file..." << endl;

		}
		int rec = 1;
		long posistion=(rec-1)*sizeof(monster);

		file.seekg(posistion,ios::beg);
			//long posistion=(rec-1)*sizeof(monster);
			file.seekg(posistion,ios::beg);
			file.read(reinterpret_cast<char *>(&p1),sizeof(player));
	}
	cout << "name " << p1.name << endl << "health " << p1.health << endl;
	cout << "xp " << p1.xp << endl << "strength " << p1.str << endl << "armor " << p1.armor << endl;
}

void town(player & p1)
{
	cout << "a town sprawls out before your eyes\n";
	cout << "but as you approach all the shops and houses\n";
	cout << "start running and closing their doors before you\n";
	cout << "can talk to them so you decide it is better just to leave\n";
	cout << "than fight so you head on down the road\n";
	path(p1);
}

void pit(player & p1)
{
	cout << "there is a pit trap in the road\n";
	cout << "you just fell into and to top it off\n";
	cout << "there were poison tipped spikes in the bottom of\n";
	cout << "you die from the poised thanks for playing\n";
}

void inn(player & p1)
{
	cout << "you come to an inn with a very nice in keeper\n";
	cout << "offers you a room to sleep and heal for free\n";
	cout << "health restored\n";
	p1.health = p1.maxh;
	path(p1);
}
