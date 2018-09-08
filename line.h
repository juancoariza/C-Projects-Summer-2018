/******************************************************************************
* File: line.h
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: create a header file  for all functions of a line using "point.h"
******************************************************************************/
#include "point.h"

#ifndef LINE_H		// avoids multiple definitions
#define LINE_H		// of a class with this name in the same project

class Line {
public:
	// Constructors

	/**
	* Default Construct
	*/
	Line();

	/**
	* Construct a Line object from two points provided
	* @param pone - the first line
	* @param ptwo - the second line
	*/
	Line(Point pone, Point ptwo);

	// Member methods

	/**
	* calculate the distance between two points that define a line
	* @return float - the slope
	*/
	float calcDistance();

	/**
	* calculate and return the slope of the line
	* @return float - the slope
	*/
	float calcSlope();

	/**
	* calculate and return the point where the line
	* intersects the Y axis
	* @return float - the Y-intercept
	*/
	float calcYIntercept();




	// Accessor Methods

	/**
	* Get the first point
	* @return Point - the first point object
	*/
	Point getPointOne();

	/**
	* Set the frist point
	* @param pone - a point object
	*/
	void setPointOne(Point pone);

	/**
	* Get the second point
	* @return Point - the second point object
	*/
	Point getPointTwo();

	/**
	* Set the second point
	* @param ptwo - a point object
	*/
	void setPointTwo(Point ptwo);

	// Helper methods

	/**
	* Return a string representtion of the Line object
	* @return string - current line as a string
	*/
	std::string toString();
private:
	// two points that define the line
	Point pointOne;
	Point pointTwo;
};

#endif				// LINE_H


