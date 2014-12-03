// Nicolas Tsagarides
// 29/11/2014
// The jumping frogs puzzle
// 
// Operations:
// Green jumps one spot
// Green jumps two spots
// Brown jumps one spot
// Brown jumps two spots
// Simplified into one operation:
// Frog on place x jumps to the empty spot
// frogJumps(x)
// The priority is from x = 0 to x = 6

#include <iostream>
#include <vector>
using namespace std;

enum lily {EMPTY, GREEN, BROWN};
enum validation {INVALID, TWOLEFT, ONELEFT, TWORIGHT, ONERIGHT};

namespace game
{
	lily stage[] ={GREEN, GREEN, GREEN, EMPTY, BROWN, BROWN, BROWN};
}

void printStage();
void frogJumps(int);
bool validFor1(int);
bool validFor2(int);
validation validForJump(int);

int main (int argc, char const *argv[])
{
	printStage();
	frogJumps(1);
	printStage();
	
	return 0;
}

void printStage()
{
	string color = "";
	cout << "\n====STAGE====\n==Left Side==\n\n";
	for (int i=0; i<7; i++)
	{
		if (game::stage[i]==GREEN) {color = "Green";}
		else if (game::stage[i]==BROWN) {color = "Brown";}
		else {color = "Empty";}
		cout << "Spot " << i << ": " << color << endl;
	}
	cout << "\n==Right Side=\n====STAGE====\n\n";
}

void frogJumps(int frog)
{
	if (game::stage[frog]==GREEN)
	{
		if ((game::stage[frog+1])==EMPTY)
		{
			game::stage[frog]=EMPTY; // the frog jumps from the pad
			game::stage[frog+1]=GREEN; // the frog lands one spot to the right
			
		}
		else if ((game::stage[frog+2])==EMPTY)
		{
			game::stage[frog]=EMPTY; // the frog jumps from the pad
			game::stage[frog+2]=GREEN; // the frog lands thw spots to the right
		}
		else
		{
			cout << "ERROR: Green frogs can only jump one or two spots to the right only if the spot is empty\n";
		}
	}
	else if (game::stage[frog]==BROWN)
 	{
 		if ((game::stage[frog-1])==EMPTY)
 		{
 			game::stage[frog]=EMPTY; // the frog jumps from the pad
 			game::stage[frog-1]=BROWN; // the frog lands one spot to the left
 		}
 		else if ((game::stage[frog-2])==EMPTY)
 		{
 			game::stage[frog]=EMPTY; // the frog jumps from the pad
 			game::stage[frog-2]=BROWN; // the frog lands thw spots to the left
 		}
 		else
 		{
 			cout << "ERROR: Brown frogs can only jump one or two spots to the left only if the spot is empty\n";
 		}
 	}
 	else
 	{
	 	cout << "ERROR: Lily pad is empty. This function should only be called on a spot with a frog\n";
 	}
}

bool validFor1(int frog)
{
	if ( ( (game::stage[frog]==GREEN) && (frog <=5) ) || ( (game::stage[frog]==BROWN) && (frog >=1) ) ) // making sure the frog will not move out of bounds
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool validFor2(int frog)
{
	if ( ( (game::stage[frog]==GREEN) && (frog <=4) ) || ( (game::stage[frog]==BROWN) && (frog >=2) ) ) // making sure the frog will not move out of bounds
	{
		return true;
	}
	else
	{
		return false;
	}
}

validation validForJump(int frog)
{
	if ( (game::stage[frog]==GREEN) && (validFor1(frog)==true) )
	{
		return (INVALID);
	}
	return (INVALID);
}
