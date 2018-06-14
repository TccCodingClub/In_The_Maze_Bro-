//============================================================================
// Name        : Space.h
// Test File   : main.cpp
// Description : the header file for the Space class
// Author      : Tess Tucker
//============================================================================

#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include "Location.h"
#include "Graphic.h"

using namespace std;

enum SpaceType { WALL, PATH, ENTRANCE, EXIT, VDOOR, HDOOR, ROOM, CHEST, PLAYER };
//Add ROOMs, ENTRANCE becomes DOOR and EXIT becomes STAIRS, maybe multi-level, or exit at the end

//The following all correspond with the indexes of SpaceType
const string StrSpaceID[] = { "WALL", "PATH", "ENTRANCE", "EXIT", "VDOOR", "HDOOR", "ROOM", "CHEST", "PLAYER" };
const char CharSpaceID[] = { 'X',    '|',    'S',        'F',     'V',      'H',    'R',    'C',    'P' };
const int IntSpaceID[] = { 177,    219,    219,        219,     197,      197,    219,    220,    175 };

class Space
{
public:
	Space();                        // default constructor
	Space(SpaceType, int, int);     // constructor
	void Print();                   // prints the Space's graphic to the console
	void PrintInfo();               // prints the info of a Space object

protected:
	SpaceType type;         // enumerated type representing the type of Space object
	string strID;           // string representation of a Space object
	char charID;            // a single-character ID for each type of space, used in reading maze format from file
	int intID;              // the integer corresponding to the extended ASCII char that will make up Space's graphic
	Graphic graphic;        // the pair of ASCII chars that create a square representation of a Space object
	Location loc;           // holds an x and y value used to reference column and row, or the location in an array
};

#endif // SPACE_H
