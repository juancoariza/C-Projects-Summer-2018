/******************************************************************************
* File: line.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: create a line algorithm by using the defined header file "line.h"
******************************************************************************/
#include <string>
#include <math.h>
#include "line.h"

using namespace std;

// Constructors

/**
* Default Construct
*/
Line::Line() {}

/**
* Construct a Line object from two points provided
* @param pone - the first point
* @param ptwo - the second point
*/
Line::Line(Point pone, Point ptwo) {
	pointOne = pone;
	pointTwo = ptwo;
}

// Member methods 

/**
* Calculate the distance between two points of a line
* @return float - the slope
*/
float Line::calcDistance() {
	float xDiff = pointTwo.getXCoordinate() - pointOne.getXCoordinate();
	float yDiff = pointTwo.getYCoordinate() - pointOne.getYCoordinate();

	return sqrt(pow(xDiff, 2) + pow(yDiff, 2));
}

/**
* Calculate and return the slope of the line
* @return float - the slope
*/
float Line::calcSlope() {
	float slope = 0;

	float xDiff = pointTwo.getXCoordinate() - pointOne.getXCoordinate();
	float yDiff = pointTwo.getYCoordinate() - pointOne.getYCoordinate();

	// make sure there is no division by 0
	if (xDiff != 0) {
		slope = yDiff / xDiff;
	}
	return slope;
}

/**
* Calculate and return the point where the line
* intersects the Y-axis
* @return float - the Y-intercept
*/
float Line::calcYIntercept() {
	float yIntcpt = 0;

	float slope = calcSlope();
	if (slope != 0) {
		// use the first point in the calculation
		yIntcpt = slope * pointOne.getXCoordinate() + pointOne.getYCoordinate();
	}

	return yIntcpt;
}



// Accessor Methods

/**
* Get the first point
* @return Point - the first point object
*/
Point Line::getPointOne() {
	return pointOne;
}

/**
* Set the first point
* @param pone - a point object
*/
void Line::setPointOne(Point pone) {
	pointOne = pone;
}

/**
* Get the second point
* @return Point - the second point object
*/
Point Line::getPointTwo() {
	return pointTwo;
}

/**
* Set the second point
* @param ptwo - a point object
*/
void Line::setPointTwo(Point ptwo) {
	pointTwo = ptwo;
}

// Helper Methods

/**
* Return a string representation of the Line object
* @return string - current line as a string
*/
string Line::toString() {
	return "Line intersecting: " + pointOne.toString() + " - " + pointTwo.toString();
}