//============================================================================
// Name        : Location.h
// Test File   : main.cpp
// Description : the header file for the Location class
// Author      : Tess Tucker
//============================================================================

#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>

using namespace std;

class Location
{
public:
	Location();             // default constructor
	Location(int, int);     // constructor
	void Print();           // prints "(x, y)"

private:
	int x;      // x-coordinate from graph perspective, or the int column from an array perspective
	int y;      // y-coordinate from graph perspective, or the int row from an array perspective
};

#endif // LOCATION_H
