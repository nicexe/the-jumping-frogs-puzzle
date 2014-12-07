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
#include <stack>
using namespace std;

enum lily {EMPTY, GREEN, BROWN};
enum validation {INVALID, TWOLEFT, ONELEFT, TWORIGHT, ONERIGHT};

class State
{
public:
	lily lake[7];
	int operation;
	State* parent;

	State(lily[], State*);
	State(State*);
	static void childOf(State*, State*);
};

State::State (lily la[], State* p)
{
	State::childOf(parent, p);
	for (int i=0; i<7; i++)
	{
		this->lake[i]=la[i];
	}
}

State::State (State* p)
{
	State::childOf(parent, p);
}

void State::childOf(State* c, State* p)
{
	c->parent=p;
}

int main (int argc, char const *argv[])
{
	lily startingState[] = {GREEN, GREEN, GREEN, EMPTY, BROWN, BROWN, BROWN}; // This is the starting state
	
	stack <State> open; // OPEN stack
	stack <State> close; // CLOSE stack

	State* Root = new State(startingState, NULL);
	open.push(Root); delete Root;

//	while (open.empty())
//	{
//		
//	}
	
	return 0;
}
