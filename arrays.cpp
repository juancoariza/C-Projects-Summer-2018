/*************************************************************************
* File: arrays.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: Demonstrate the usage of arrays in C++ with a GPA program
**************************************************************************/

#include <iostream>
#include <string>

const int SCORES_MAX = 5; 
// limits the number of score entries to 5

int main() {

	std::string stuFName = "Joe";
	std::string stuLName = "Scholar";

	int grades[SCORES_MAX] = { 93, 72, 84, 42, 97 };
	// assigned student grades


	float GPA = grades[0];
	// stores GPA calculations

	GPA = GPA + grades[1];
	GPA += grades[2];
	GPA += grades[3] + grades[4];
	// adds the values within the array 

	GPA /= SCORES_MAX;
	/* divide the total score by number of scores to get the GPA */

	std::cout << GPA << std::endl;

	std::string stuFullName = stuFName + " " + stuLName;
	// concatenates the first and last name into "Joe Scholar"

	std::cout << stuFullName << ": " << GPA << std::endl;

	return 0;

}