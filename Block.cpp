//============================================================================
// Name        : Block.cpp
// Test File   : main.cpp
// Description : the implementation file for the Block class
// Author      : Tess Tucker
//============================================================================

#include "Block.h"

Block::Block()
{
    // default constructor
}

Block::Block(SpaceType type)
{
    // In the cast of a wall, path, room, entrance, or exit, print the 3x3 spaces according to type
    /* Ex.      W W W
                W W W
                W W W
    */
	if (type == WALL || type == PATH || type == ROOM || type == ENTRANCE || type == EXIT) {
		for (int x = 0; x < BLOCK_ROWS; x++)
			for (int y = 0; y < BLOCK_COLS; y++)
				block[y][x] = Space(type, y, x);
	}
	// In the case of a horizontal door, print a path row, a door row, and then another path row
	/* Ex.      P P P
                D D D
                P P P
    */
	else if (type == HDOOR) {
		for (int x = 0; x < BLOCK_ROWS; x++) {
			for (int y = 0; y < BLOCK_COLS; y++) {
				if (y == BLOCK_COLS / 2)
					block[y][x] = Space(type, y, x);
				else
					block[y][x] = Space(PATH, y, x);
			}
		}
	}
	// In the case of a vertical door, print 3 rows of the pattern: path, door, path
	/* Ex.      P D P
                P D P
                P D P
    */
	else if (type == VDOOR) {
		for (int x = 0; x < BLOCK_ROWS; x++) {
			for (int y = 0; y < BLOCK_COLS; y++) {
				if (x == BLOCK_ROWS / 2)
					block[y][x] = Space(type, y, x);
				else
					block[y][x] = Space(PATH, y, x);
			}
		}
	}
	// In the case of a chest, print a 3x3 path, except the center Space is of the type Chest
	/* Ex.      P P P
                P C P
                P P P
    */
	else if (type == CHEST) {
		for (int x = 0; x < BLOCK_ROWS; x++) {
			for (int y = 0; y < BLOCK_COLS; y++) {
				if (y == BLOCK_COLS / 2 && x == BLOCK_ROWS / 2)
					block[y][x] = Space(type, y, x);
				else
					block[y][x] = Space(PATH, y, x);
			}
		}
	}

    // In the case of a Block that cannot be occupied by the Player (or other occupants we may create later)
	if (type == WALL) {
		canOccupy = false;
	}
	// In the case of a Block that a Player can occupy (everything except for Blocks of type WALL)
	else {
		canOccupy = true;
	}
}

// Must be used in parts when printing side-by-side Blocks, one for each row
void Block::Print(int col) {
	for (int x = 0; x < BLOCK_COLS; x++)
		(this->block[col][x]).Print();
}

// Prints a 3x3 Block, used mostly for testing, as Blocks must be printed row-by-row for the maze
void Block::PrintFull() {
	for (int x = 0; x < BLOCK_ROWS; x++) {
		for (int y = 0; y < BLOCK_COLS; y++) {
			this->block[y][x].Print();
		}
		cout << endl;
	}
}
