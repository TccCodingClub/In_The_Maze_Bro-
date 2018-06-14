//============================================================================
// Name        : Block.h
// Test File   : main.cpp
// Description : the header file for the Block class
// Author      : Tess Tucker
//============================================================================

#ifndef BLOCK_H
#define BLOCK_H

#include "Space.h"
#include "Player.h"

const int BLOCK_COLS = 3;   // number of individual Space objects per Block column
const int BLOCK_ROWS = 3;   // number of individual Space objects per Block row

class Block
{
public:
    Block();                // default constructor
	Block(SpaceType);       // constructor
	void Print(int);        // prints a the parameter-given column of the 3x3 Block
	void PrintFull();       // prints the 3x3 block (NOTE: Blocks printed side-by-side must be printed row-by-row)

protected:

private:
    SpaceType type;                         // enumerated type representing the type of Space objects making up the Block
	Space block[BLOCK_COLS][BLOCK_ROWS];    // an array holding the 3x3 of Spaces that makes up a Block
	Space center;                           // the Space in the Block that can be occupied by a single-Space occupant, such as a Player object
	bool canOccupy;                         // true if the Block can be occupied by a single-Space occupant, such as a Player object
};

#endif // BLOCK_H
