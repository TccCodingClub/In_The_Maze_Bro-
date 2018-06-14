//============================================================================
// Name        : functions.h
// Test File   : main.cpp
// Description : the header file holding libraries & constants for main.cpp
// Author      : Tess Tucker
//============================================================================



//-----------------------------------------------------------------LIBRARIES-//
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include "Space.cpp"
#include "Location.cpp"
#include "Block.cpp"
#include "Player.cpp"
#include "Graphic.cpp"

//-----------------------------------------------------------------NAMESPACE-//

using namespace std;

//-----------------------------------------------------------------CONSTANTS-//

const int MAP_SIZE = 20;

//---------------------------------------------------------STRUCTS & TYPEDEFS-//

typedef Block Maze[MAP_SIZE][MAP_SIZE];
typedef Block *BlockPtr;

//-------------------------------------------------------------FUNCTION DECS-//

//Generates up a maze based on a file
//PRE: inData has been opened with the proper file
//POST: Maze is filled and returned by reference
void GetMaze(ifstream&, Maze);

//Prints the maze
//PRE: Maze has been created
//POST: prints maze to the console
void PrintMaze(Maze);

//Gets the corresponding string representation of a SpaceType
//PRE: SpaceType is valid member of the enumerated type
//POST: returns a string
string SpaceTypeToString(SpaceType);

//Gets the corresponding char representation of a SpaceType
//PRE: SpaceType is a valid member of the enumerated type
//POST: returns a char
char SpaceTypeToChar(SpaceType);

//Gets the corresponding SpaceType from the string that is used to represent it
//PRE: N/A
//POST: returns a SpaceType
SpaceType StringToSpaceType(string);

//Gets the corresponding SpaceType from the char that is used to represent it in a file
//PRE: N/A
//POST: returns a SpaceType
SpaceType CharToSpaceType(char);

//Capitalizes all characters in a string
//PRE: string points to a valid string variable
//POST: string is modified at original address
void NormalizeString(string&);

//Capitalizes all characters in a string and returns a modified new string
//PRE: none
//POST: returns capitalized string
string GetNormalizedString(string);

//Keeps prompting the user for a valid file name until file is open
//PRE: ifstream variable points to valid ifstream
//POST: passes a successfully opened file through reference
void GetFileInfo(ifstream&);

//Attempts to open a file given its string name
//PRE: File exists, string is file name, ifstream& points to valid stream
//POST: Reference-returns opened file
void GetFileInfo(ifstream&, string);

//-----------------------------------------------------------GLOBAL VARIABLES-//

#endif  //FUNCTIONS_H
