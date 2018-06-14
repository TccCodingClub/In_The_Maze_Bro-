//============================================================================
// Name        : Graphic.h
// Test File   : main.cpp
// Description : the header file for the Graphic class
// Author      : Tess Tucker
//============================================================================

#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <iostream>

using namespace std;

const int GRAPHIC_LENGTH = 2;       // sets the length of rectangular extended ASCII graphics to 2, creating a square

class Graphic
{
public:
    Graphic();                      // default constructor
	Graphic(int);                   // constructor
	void Print();                   // prints the Graphic, represented by 2 extended ASCII chars, forming a square

protected:

private:
    int ascInt;                     // the integer corresponding to the extended ASCII char used to print Graphic
	char halfGraphic;               // the extended ASCII char used to print Graphic object
	char graphic[GRAPHIC_LENGTH];   // an array of singular halfGraphic chars (2 of them creates a square)
};

#endif // GRAPHIC_H
