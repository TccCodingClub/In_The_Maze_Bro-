//============================================================================
// Name        : Maze.cpp
// Test File   : (this)
// Description : the implementation file for a Maze project
// Author      : Tess Tucker & Coding Club
//============================================================================



//-----------------------------------FILE HOLDING FUNCTIONS, CONSTANTS, ETC.-//

#include "mazeFunctions.h"

//-----------------------------------------------------------------NAMESPACE-//

using namespace std;


//-----------------------------------------------------------GLOBAL VARIABLES-//

ifstream inData("maze.txt");

//-------------------------------------------------------------------------------------MAIN-//

int main() {
	Maze maze;              // Creates the Maze, defined in a typedef as Block[][] array
	GetMaze(inData, maze);  // Fills the Maze based on format given by the "maze.txt" file
	PrintMaze(maze);        // Prints the created Maze to the console

	cout << endl << "Goodbye!" << endl << endl;

	return 0;
}

//--------------------------------------------------------------------------------FUNCTIONS-//


void GetMaze(ifstream &inData, Maze maze) {
	SpaceType newType;  // allocates memory to hold new SpaceTypes
	string str;         // allocates memory to hold an individual line from the file
	char ch;            // allocates memory to hold a char from the file
	int y = 0;          // starts the y/row value at 0
	int x = 0;          // starts the x/column value at 0

	// while the file has not entered fail state:
	while (inData) {
		getline(inData, str);   // stores the next line in the file to str
		stringstream ss(str);   // creates a stream from str
		ss >> ch;               // stores the next char of the stream ss

		y = 0;                  // resets the y/row value at the start of a new row

		//while we are still parsing through this line of the file:
		while (inData && ss) {
		    // creates a Block from the SpaceType indicated by ch, the current char,
		    // and stores into the current maze slot defined by [x][y]
			maze[y][x] = Block(CharToSpaceType(ch));
			ss >> ch;           // stores the next char of the string
			y++;                // increments y, moves to the next row
		}
		x++;                    //increments x, moves to the next column
	}

	inData.clear();             // clears the file's fail state
	inData.seekg(0);            // resets the file read marker to the start of file
}

void PrintMaze(Maze maze) {
	Block tempBlock;            // allocates memory for a temporary Block

	// for the length of the maze rows:
	for (int row = 0; row < MAP_SIZE; row++) {
        // for the length of the block rows:
		for (int blockRow = 0; blockRow < BLOCK_ROWS; blockRow++) {
		    // for the length of the maze columns:
			for (int col = 0; col < MAP_SIZE; col++) {
				tempBlock = maze[col][row];     // assigns the Block contained at maze[col][row] to tempBlock
				tempBlock.Print(blockRow);      // prints tempBlock's current row (2 extended ASCII chars per Space)
			}
			cout << endl;
		}
	}
	cout << endl;
}

string SpaceTypeToString(SpaceType type) {
	return StrSpaceID[type];    // returns the string representation of a SpaceType
}


char SpaceTypeToChar(SpaceType type) {
	return CharSpaceID[type];   // returns the char representation of a SpaceType
}

SpaceType StringToSpaceType(string strID) {
	NormalizeString(strID);     // reformats strID to all capital letters

	// for the number of possible StrSpaceIDs:
	for (int i = 0; i < sizeof(StrSpaceID); i++)
		if (strID == StrSpaceID[i]) // if the strID is equivalent to the this predefined string representation of a Space
			return (SpaceType)i;    // return the SpaceType that corresponds to index i
}


SpaceType CharToSpaceType(char charID) {
	charID = toupper(charID);   //capitalize char for comparison

	// for the number of possible CharSpaceIDs:
	for (int i = 0; i < sizeof(CharSpaceID); i++)
		if (charID == CharSpaceID[i])   // if the charID is equivalent to this predefined char representation of a Space
			return (SpaceType)i;        // return the SpaceType that corresponds to index i
}

void NormalizeString(string &str) {
    // replaces each char in str with a capital letter
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str.at(i));
}

string GetNormalizedString(string str) {
	string newStr;  // allocates memory for a string

	// parsing through each char in str, adds its capital equivalent one-by-one to newStr
	for (int i = 0; i < str.length(); i++)
		newStr += toupper(str.at(i));

	return newStr;  //returns str's all-capital equivalent
}
