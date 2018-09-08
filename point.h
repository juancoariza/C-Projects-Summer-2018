/******************************************************************************
* File: point.h
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: Create a header file for other source files in the project
******************************************************************************/
#include <iostream>
#include <string>

#ifndef POINT_H		// used to avoid multiple definitios
#define POINT_H		// of a class with his name in the same project

class Point {
public:

	// Constructors
	/**
	* Default constructor
	*/
	Point();

	/**
	* Construct a Point object from X & Y coordinates provided
	* @param xpos - the X-coordinate
	* @param ypos - the Y-coordinate
	*/
	Point(float xpos, float ypos);

	// Accessor Methods

	/**
	* Get the X-ccordinate
	* @return float - the current X-coordinate value
	*/
	float getXCoordinate();

	/**
	* Set the X Coordinate
	* @param xpos - new X-coordinate value
	*/
	void setXCoordinate(float xpos);

	/**
	* Get the Y-ccordinate
	* @return float - the current X-coordinate value
	*/
	float getYCoordinate();

	/**
	* Set the Y Coordinate
	* @param ypos - new X-coordinate value
	*/
	void setYCoordinate(float ypos);

	// Helper methods

	/**
	* Return a string representation of the Point object
	* @return string - current point as a string
	*/
	std::string toString();		// requires the inclusion of <string>

private:
	// X & Y coordinates of the point
	float xCoord;
	float yCoord;
};					// ends Point class
#endif				// ends POINT_H