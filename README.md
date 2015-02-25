# The Jumping Frogs Puzzle
This project is an assignment for an Artificial Intelligence course that I took

The jumping frogs puzzle is as follows. 7 lily-pads are in a series on a lake. On the first 3 pads (starting from the left) are sitting **3 brown frogs** (facing right). Then there is an **empty** pad. The last 3 pads have **3 green frogs** on them (facing left).  
The configuration can be depicted as such:  
`| B | B | B | E | G | G | G |`  
The frogs can only jump to an empty lily-pad to the direction they are facing. The frogs can also jump up to 2 lily-pads away.  
In the end, the frogs must come to this configuration:  
`| G | G | G | E | B | B | B |`

This project performs DFS to find and display the steps needed for the frogs to perform in order to reach the final configuration. There are DFS tree graphs showing the tree that the program is producing while it runs and a proper documentation that shows the open and close lists on every step.
