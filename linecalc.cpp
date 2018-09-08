/******************************************************************************
* File: linecalc.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: Demonstrate user-defined classes and headers in C++
******************************************************************************/

#include <iostream>
#include <string>
#include "line.h"
#include "point.h"

using namespace std;

Point getPoint();

enum MENU { EXIT, ENTER_POINTS, CALC_DISTANCE, CALC_SLOPE, CALC_Y_INTERCEPT };

int main() {
	Line theLine;
	Point pOne, pTwo;

	MENU choice = EXIT;
	cout << "Welcome to the Line Calculator...\n\n";

	do {

		float distance = 0.0;	// for calcDistance()
		float slope = 0.0;		// for calcSlope()
		float intercept = 0.0;	// for calcYIntercept()

		cout << "Select a Line Function: \n"
			<< "\t(1) Enter Points for the Line\n"
			<< "\t(2) Calculate Line Distance\n"
			<< "\t(3) Calculate Slope of the Line\n"
			<< "\t(4) Calculate Y-Intercept of the Line\n"
			<< "\t(0) Exit\n"
			<< "> ";

		int ask;
		cin >> ask;
		choice = MENU(ask);

		cout << "\n\n";

		switch (choice) {
		case ENTER_POINTS:
			cout << "Enter point one: ";
			pOne = getPoint();
			theLine.setPointOne(pOne);

			cout << "\n";

			cout << "Enter point two: ";
			pTwo = getPoint();
			theLine.setPointTwo(pTwo);
			break;

		case CALC_DISTANCE:
			distance = theLine.calcDistance();
			cout << theLine.toString() << " has a length of " << distance << "\n\n";
			break;

		case CALC_SLOPE:
			slope = theLine.calcSlope();
			cout << theLine.toString() << " has a slope of " << slope << "\n\n";
			break;

		case CALC_Y_INTERCEPT:
			intercept = theLine.calcYIntercept();
			cout << theLine.toString() << " intercept the Y-axis at " << intercept << "\n\n";
			break;

		default:
			cout << "Invalid choice!";
		} // ends menu switch

		cout << "\n\n";

	} while (choice != EXIT);

	return 0;
}



/***
* Prompt user to enter (X,Y) coordinates and instantiate
* a Point object
* @return Point - point object for the coordinates entered
*/
Point getPoint() {
	Point pIn;

	float xpos, ypos;

	cout << "Enter X/Y coordinates separated by a space: ";
	cin >> xpos >> ypos;

	pIn.setXCoordinate(xpos);
	pIn.setYCoordinate(ypos);

	return pIn;
}