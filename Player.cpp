//============================================================================
// Name        : Space.cpp
// Test File   : main.cpp
// Description : the implementation file for the Player class
// Author      : Tess Tucker
//============================================================================

#include "Player.h"

Player::Player()
{
    // default constructor
    // defines default parameters for the Player object
	name = "Player";
	Space::type = PLAYER;
	Space::strID = StrSpaceID[type];
	Space::charID = CharSpaceID[type];
	Space::intID = IntSpaceID[type];
	Space::graphic = Graphic(intID);
	Space::loc; //!// There might be a problem here //!//
}

Player::Player(string n, Location l) {
    // constructor
    // Initializes the private members to assigned (name, loc) and default settings
	name = n;
	Space::type = PLAYER;
	Space::strID = StrSpaceID[type];
	Space::charID = CharSpaceID[type];
	Space::intID = IntSpaceID[type];
	Space::graphic = Graphic(intID);
	Space::loc = l;
}

void Player::Move(char ch, MoveKey &key) {
	switch (toupper(ch)) {
	case 'W':   key = W;    // used to move the Player up
	case 'A':   key = A;    // used to move the Player left
	case 'S':   key = S;    // used to move the Player down
	case 'D':   key = D;    // used to move the Player right
	}
}
