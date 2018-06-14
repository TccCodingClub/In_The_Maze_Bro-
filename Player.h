//============================================================================
// Name        : Player.h
// Test File   : main.cpp
// Description : the header file for the Player class
// Author      : Tess Tucker
//============================================================================

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Location.h"
#include "Graphic.h"
#include "Space.h"

using namespace std;

enum MoveKey { W, A, S, D, N };
//string StrKeyID[] = { "UP",  "LEFT",     "DOWN",     "RIGHT",    "INVALID" };

class Player: public Space
{
public:
	Player();                       // default constructor
	Player(string, Location);       // constructor
	void Move(char, MoveKey &);     // modifies the Player's loc depending on the keyboard key (char) given

protected:

private:
	string name;                    // the name of the Player object

//// /*Inherited from Space*/ ////
//      public:
//	        Space();
//	        Space(SpaceType, int, int);
//	        void Print();
//	        void PrintInfo();
//      protected:
//	        SpaceType type;
//	        string strID;
//	        char charID;
//	        int intID;
//	        Graphic graphic;
//	        Location loc;
};

#endif // PLAYER_H
