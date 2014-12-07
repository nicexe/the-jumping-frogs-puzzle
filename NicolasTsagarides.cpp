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
};

namespace game
{
	lily startingState[] = {GREEN, GREEN, GREEN, EMPTY, BROWN, BROWN, BROWN}; // This is the starting state
	
	stack <State> open; // OPEN stack
	stack <State> close; // CLOSE stack
	
	State *Root = new State;
}

void childOf(State*, State*);

int main (int argc, char const *argv[])
{
	game::Root->parent=NULL; // the root node has no parent
	copy(begin(game::startingState), end(game::startingState), begin(game::Root->lake)); // Root node is now the starting state
	
	return 0;
}


void childOf(State*A, State*B)
{
	A->parent=B;
}
