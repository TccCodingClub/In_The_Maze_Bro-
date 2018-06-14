//============================================================================
// Name        : Space.cpp
// Test File   : main.cpp
// Description : the implementation file for the Space class
// Author      : Tess Tucker
//============================================================================

#include "Space.h"

Space::Space() {
    //default constructor
}

Space::Space(SpaceType type, int col, int row) {
    // Assigns the given parameters to the private members of a Space
	this->type = type;
	this->strID = StrSpaceID[type];
	this->charID = CharSpaceID[type];
	this->intID = IntSpaceID[type];
	this->graphic = Graphic(IntSpaceID[type]);
	Location newLoc(col, row);
	this->loc = newLoc;

}

void Space::Print() {
    // Prints two rectangular ASCII chars, forming a square
	this->graphic.Print();
}

void Space::PrintInfo() {
    // Prints a detailed overview of a Space's data to the console
	cout << "TYPE: " << StrSpaceID[this->type].c_str() << endl;
	cout << "CHAR: " << this->charID << endl;
	cout << "ASCI: " << this->intID << endl;
	cout << "GRAP: ";
	this->graphic.Print();
	cout << endl;
	cout << "LOCA: ";
	this->loc.Print();
	cout << endl;
}
