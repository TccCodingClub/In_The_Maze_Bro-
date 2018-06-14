//============================================================================
// Name        : Location.cpp
// Test File   : main.cpp
// Description : the implementation file for the Location class
// Author      : Tess Tucker
//============================================================================

#include "Location.h"

Location::Location() {
	//default constructor
}

Location::Location(int xCoordinate, int yCoordinate) {
	// Defines the private int members of Location, x and t
	x = xCoordinate;
	y = yCoordinate;
}

void Location::Print() {
    // Prints Location in a graph format: "(x, y)"
	cout << "(" << this->x << "," << this->y << ")";
}
