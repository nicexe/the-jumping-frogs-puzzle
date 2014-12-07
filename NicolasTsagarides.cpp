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

validation valid(lily[], int);
bool lakesEqual(lily[], lily[]);

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

int main (int argc, char const *argv[])
{
    lily startingState[] = {GREEN, GREEN, GREEN, EMPTY, BROWN, BROWN, BROWN}; // This is the starting state
    lily acceptedState[] = {BROWN, BROWN, BROWN, EMPTY, GREEN, GREEN ,GREEN}; // This is the goal
    
    stack <State> open; // OPEN stack
    stack <State> close; // CLOSE stack
    
    open.push(State(startingState, NULL)); // push the starting state to the OPEN stack
    
    State* ParentNode;
    
    lily currentState[7];
    
    while (open.empty())
    {
        copy(begin(open.top().lake), end(open.top().lake), begin(currentState)); // get the current state
        ParentNode = open.top().parent; // saving the parent of the state to be pusdhed into the CLOSE stack later
        
        open.pop(); // pop the current state from the OPEN stack
        
        if (lakesEqual(currentState, acceptedState))
        {
            // TODO: print the result
            break;
        }
        else
        {
            close.push(State(currentState, ParentNode)); // push the current state into the CLOSE stack
            for (int i=0; i<7; i++)
            {
                validation action = valid(currentState, i); // checking which action is valid if any
                
                switch(action) // performs the valid action if any
                {
                    case TWOLEFT:
                        currentState[i]=EMPTY; // frog jumps
                        currentState[i-2]=BROWN; // frog lands 2 spots to the left
                        open.push(State(currentState, ParentNode)); // add the current state to the OPEN stack
                        break;
                    case ONELEFT:
                        currentState[i]=EMPTY;
                        currentState[i-2]=BROWN;
                        open.push(State(currentState, ParentNode));
                        break;
                    case ONERIGHT:
                        currentState[i]=EMPTY;
                        currentState[i+1]=GREEN;
                        open.push(State(currentState, ParentNode));
                        break;
                    case TWORIGHT:
                        currentState[i]=EMPTY;
                        currentState[i+2]=GREEN;
                        open.push(State(currentState, ParentNode));
                        break;
                    case INVALID:
                        break;
                    default:
                        break;
                }
                
                
            }
        }
    }
    
    return 0;
}

State::State (lily la[], State* p)
{
    State::childOf(this, p);
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

validation valid (lily lake[], int i)
{
    if (lake[i]==GREEN) // check in the frog on i is green
    {
        if (i<6) // check if the frog goes out of bounds
        {
            if ( (lake[i+1]) == EMPTY) // check if there is an empty spot
            {
                return (ONERIGHT);
            }
        }
        else if (i<5)
        {
            if ( (lake[i+2]) == EMPTY)
            {
                return (TWORIGHT);
            }
        }
    }
    else if (lake[i]==BROWN)
    {
        if (i>0)
        {
            if (lake[i-1]==EMPTY)
            {
                return (ONELEFT);
            }
        }
        else if (i>1)
        {
            if (lake[i-2]==EMPTY)
            {
                return (ONERIGHT);
            }
        }
    }
    
    return (INVALID);
}

bool lakesEqual(lily a[], lily b[])
{
    bool equality = true;
    for (int i=0; i<6; i++)
    {
        if (a[i]!=b[i])
        {
            equality=false;
        }
    }
    
    return (equality);
}
