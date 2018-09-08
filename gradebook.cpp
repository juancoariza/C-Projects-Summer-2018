/******************************************************************************
* File: gradebook.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: Create a gradebook program using data structures and enumerators
******************************************************************************/

#include <iostream>		// console I/O
#include <cstdlib>		// random-number generator
#include <ctime>		// random number seed
#include <math.h>		// ceiling function
#include <string>		// getLine function

using namespace std;

const int SCORES_MAX = 5;	// caps the maximum scores to 5
const int STUDENTS_MAX = 6;	// caps the maximum students to 6

// menu setup
enum MENU { EXIT, ENTER_STUDENTS, UPLOAD_GRADES, PRINT_GRADES };

// stores letter grades by factors of 10
enum LETTER_GRADE { F = 0, D = 6, C = 7, B = 8, A = 9 };

// stucture for analyzing letter grades from scores
struct Grade {
	int score;
	LETTER_GRADE letter;
};

// structure for assigning a student with a letter grade
struct Student {
	string stuName;
	Grade grades[SCORES_MAX];
};

/* function declarations */
int  getStudents(Student students[]);				// collects names of students
int  getScores(Student students[], int count);		// creates grades for students
char printLetter(LETTER_GRADE letter);				// prints corresponding letter to the student
LETTER_GRADE getLetter(float score);				// calculates the numeric grade values
void printGrades(Student students[], int count);	// prints all the above content

int main() {

	/* initialize the RNG with current time and seed */
	srand(time(NULL));

	int numStudents = 0;
	int scoresLoaded = 0;

	// creates a structure for 6 students at once
	Student gradebook[STUDENTS_MAX];

	MENU choice;

	do {

		cout << "Auto Gradebook:" << endl
			 << "\t(1) Enter students" << endl
			 << "\t(2) Upload grades" << endl
			 << "\t(3) Print grades" << endl
			 << "\t(0) Exit" << endl
			 << "> ";

		int ask;
		cin >> ask;

		choice = MENU(ask);

		switch (choice) {

			case ENTER_STUDENTS:
				cin.ignore();	// removes any end-line characters on input 
								// stream left behind by "cin" if using 
								// "getLine()" in "getStudents()"
				numStudents = getStudents(gradebook);

				break;

			case UPLOAD_GRADES:
				if (numStudents == 0) {
					cout << "Enter students first!";
				}
				else {
					scoresLoaded = getScores(gradebook, numStudents);
					cout << numStudents * 5 << " scores uploaded.";
				}
				break;

			case PRINT_GRADES:
				if (numStudents == 0)
					cout << "Enter students first!";
				else
					printGrades(gradebook, numStudents);
				break;

			default:
				cout << "Invalid choice!";
			}

		cout << endl << endl;

	} while (choice != EXIT);

	return 0;
}	// ends main


/* DIY functions */

/**
* Collects how many students will be analyzed
* @param students[] - gradebook
* @return int - correct number of students
* DIY
*/
int getStudents(Student students[]) {
	int stuCount = 0;

	string nameIn = "";
	string flags = "Xx"; 	// used to compare the input to our exit flags
							// the function will use the String.compare methods
							// to compare user input to the given flags

	cout << "Enter grades for each student number (X to quit)\n";

	do {
		cout << "\tStudent name (" << stuCount << "): ";
		cin >> nameIn;

		// checks if the name input is one letter, then checks for the flags
		if (nameIn.length() == 1) {

			if (nameIn.compare(0, 1, flags) != 0 || nameIn.compare(1, 1, flags) != 0) {
				return stuCount;	// if the first character of flags, "X"
									// or the second character of flags, "x"
									// is found at "nameIn", the function ends
			}

		} // closes outer if statement 

		else {
			students[stuCount].stuName = nameIn;
			// saves correct name into the "students"
			// structure for the gradebook

			stuCount++;

		}

	} while (stuCount <= 5); // once the index passes 5, it has collected all 6 students

	return stuCount;
}



/**
* Prints the corresponding letter grade 
* @param LETTER_GRADE - gradebook
* @return char - correct letter grade for the student
* DIY
*/
char printLetter(LETTER_GRADE letter) {
	char letterGiven = ' ';

	switch (letter) {
		// According to the enum used above,
		// F = 0, D = 6, C = 7, B = 8, A = 9
		case 6:
			letterGiven = 'D';
		break; 

		case 7:
			letterGiven = 'C';
		break;

		case 8:
			letterGiven = 'B';
		break;

		case 9: 
			letterGiven = 'A';
		break;

		default:
			letterGiven = 'F';
	} // ends switch statement 

	return letterGiven;
}



/**
* Finds the average of grades for students, then prints 
* the results with letter grades and student names
* @param students[] - gradebook
* @return void
* DIY
*/
void printGrades(Student students[], int count) {
	
	/* Similar to the "getScores" function, the run will create
	* N amount of M procedures. So if the user enters two students, it will create
	* 2 sets of 5 grades, and print out their numeric value, letter values, and average */


	for (int stu = 0; stu < count; stu++) {

		float avgStore = 0.0;					// used to store the sums of the grades
		cout << students[stu].stuName << endl;	// will print student name 
												// separately from the grades printing algorithm
		for (int grade = 0; grade < SCORES_MAX; grade++) {

			avgStore += students[stu].grades[grade].score;	// adds the scores together
			cout << "\t" << printLetter(students[stu].grades[grade].letter);	// prints equivalent letter 
			cout << "\t" << students[stu].grades[grade].score << endl;			// prints number grade
			
		}	// closes inner for loop

		cout << "\tAVG: " << avgStore / SCORES_MAX << endl << endl;

	} // closes outer for loop

} 



/* Given functions */

/**
* Generate random test score for all the students
* entered into the gradebook
* @param students - gradebook
* @param count - number of students in the gradebook
* @return int - the number of scores generated
*/
int getScores(Student students[], int count) {
	int scores = 0;

	for (int stu = 0; stu < count; stu++) {

		for (int grade = 0; grade < SCORES_MAX; grade++) {

			int tens = rand() % 6;	// covers 0 to 5
			int ones = rand() % 10; // covers 0 to 9
			int score = (tens + 4) * 10 + ones; // creates 40 to 99

			students[stu].grades[grade].score = score;
			students[stu].grades[grade].letter = getLetter(score);

			score++;
		}	// closes inner for loop

	} // closes outer for loop

	return scores;

} // ends getScores


/**
* Convert a numeric score into a letter grade
* @param score - the exam score
* @return LETTER_GRADE - the appropiate letter grade
*/
LETTER_GRADE getLetter(float score) {
	LETTER_GRADE grade = F;		// by default, anything below 60 is an F

	/* check if the rounded score is at least integer 59
	   ceiling will round and truncate into int datatype */
	if (ceil(score) >= 59) {

		/* Round the score and add 1 as the random 
		   functions values were 0.. desired range - 1
		   the see how many 10's would go into that score */
		int nScore = (ceil(score) + 1) / 10;	// integer division by 10

		/* cast the tens digit of the score
		   to an enum based on ordinal value */
		grade = LETTER_GRADE(nScore);
	}

	return grade;
} // ends getLetter

