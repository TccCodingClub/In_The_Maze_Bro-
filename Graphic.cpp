//============================================================================
// Name        : Graphic.cpp
// Test File   : main.cpp
// Description : the implementation file for the Graphic class
// Author      : Tess Tucker
//============================================================================

#include "Graphic.h"

Graphic::Graphic(){
	// default constructor
}

Graphic::Graphic(int ascInt) {
    // constructor
    // given the ascInt, sets the corresponding private member variables for Graphic
	this->ascInt = ascInt;
	this->halfGraphic = (char)ascInt;
	graphic[0] = halfGraphic;
	graphic[1] = halfGraphic;
}

void Graphic::Print() {
    // Prints two rectangular extended ASCII graphics, forming a square
	cout << graphic[0] << graphic[1];
}
