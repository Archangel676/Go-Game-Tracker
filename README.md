## C++ Go Game Recursive Group/Liberty Counter

# Context

Go is a game where players place black and white tiles and attempt to capture as much of a square board as possible. The size of the board can vary from 9x9 to 19x19 – these measurements refer to the number of intersections in the grid lines – stones are placed on those intersections.

Important terms in Go are "groups" and "liberties". 
- A group is a set of tiles, all of the same color, that are connected either horizontally or vertically. 
- A group’s liberties are the number of moves that can extend the group to a new open location. 

If a group has 0 liberties, it is captured and removed from the board.

# Assignment

The program should read in a row and column from the console indicating a starting location. 
It should print out: 
- The board, with the squares that are in the group made uppercase and the liberties for the group marked as *'s; 
- The number of pieces in the group based at the starting location; 
- How many liberties there are. If the row, col the user enters does not have a piece in it (is a - instead of w or b), print an error message.

The program should make use of recursion for determining the size of the group and number of liberties.
- Using recursion for determining the number of liberties is still a work in progress.

Parameters must be used to pass information from one recursive call to another. No global variables allowed (constants are OK). The program can not make a class that contains your functions.

# Goal

Ability to use and implement recursion, loops, and parameters together cohesively and properly.

## Attribution

The boilerplate starter code (Makefile, .vscode, .clang-format, and .gitignore) are from the VSCodeTemplates repository templates.
