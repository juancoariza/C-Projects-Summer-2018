/******************************************************************************
* File: point.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: create a point object by using the defined header file "point.h"
******************************************************************************/

#include "point.h"

	// Constructors
	/**
	* Default constructor
	*/
	Point::Point() {
		xCoord = 0.0;
		yCoord = 0.0;
	}

	/**
	* Construct a Point object from the X and Y coordinates provided
	* @param xpos - the X coordinate
	* @param ypos - the Y coordinate
	*/
	Point::Point(float xpos, float ypos) {
		xCoord = xpos;
		yCoord = ypos;
	}

	// Accessor Methods 
	/**
	* Get the X coordinate
	* @return float - the current X coordinate value
	*/
	float Point::getXCoordinate() {
		return xCoord;
	}

	/**
	* Set the X coordinate
	* @param xpos - new X coordinate value
	*/
	void Point::setXCoordinate(float xpos) {
		xCoord = xpos;
	}

	/**
	* Get the Y coordinate
	* @return float - the current Y coordinate value
	*/
	float Point::getYCoordinate() {
		return yCoord;
	}

	/**
	* Set the Y coordinate
	* @param ypos - new Y coordinate value
	*/
	void Point::setYCoordinate(float ypos) {
		yCoord = ypos;
	}

	/**
	* Return a string representation of the Point object
	* @return string - current point as a string
	*/
	std::string Point::toString() {
		return "Point(" + std::to_string(xCoord) + "," + std::to_string(yCoord) + ")";
	}
