/******************************************************************************
* File: conditions.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: Demonstrate the use of conditional and control statements in C++
******************************************************************************/

#include <iostream>
#include <string>

int main() {

	bool bTrue = true;
	bool bFalse = false;

	std::cout << "True = " << bTrue << std::endl;			//True = 1
	std::cout << "False = " << bFalse << std::endl;			// False = 0

	bool bGreater = 5 - 4;
	bool bEqual = 5 - 5;
	bool bLess = 4 - 5;

	std::cout << "Greater = " << bGreater << std::endl;		// Greater = 1
	std::cout << "Equal = " << bEqual << std::endl;			// Equal = 0
	std::cout << "Less = " << bLess << std::endl;			// Less = 1

	int nGreater = 5;
	int nLess = 4;

	bool isGreater = nGreater > nLess;
	bool isEqual = nGreater == nLess;
	bool isLessOrEqual = nLess <= nGreater;
	bool isNotEqual = nGreater != nLess;

	std::cout << "Greater = " << isGreater << std::endl;			// Greater = 1 
	std::cout << "Equal = " << isEqual << std::endl;				// Equal = 0
	std::cout << "LessOrEqual = " << isLessOrEqual << std::endl;	// LessOrEqual = 1
	std::cout << "NotEqual = " << isNotEqual << std::endl;			// NotEqual = 1

	bool multiExpr = 5 - 4 < 7 - 5;

	std::cout << "multiExpr = " << multiExpr << std::endl;			// multiExpr = 1

	bool bAnd = (15 == 5 + 10) && (5 - 2 < 4);
	bool bOr = (12 - 5 > 8) || (2 * 8 > 15); 
	bool bNot = (2 + 3 == 5) && !(7 < 9 - 4);

	std::cout << "bAnd = " << bAnd << std::endl;		// And = 1
	std::cout << "bOr = " << bOr << std::endl;			// Or = 1
	std::cout << "bNot = " << bNot << std::endl;		// Not = 1

	bool multiAnd = (5 > 2) && (3 < 7) && (2 == 3 - 1);
	bool multiOr = (4 > 8) || (5 - 3 != 2) || (9 > 7);
	bool multiMix = (13 < 7) && (11 > 9) || (6 <= 12 / 2);
	bool multiGroup = (13 < 7) && ((11 > 9) || (6 <= 12 / 2));

	std::cout << "And = " << multiAnd << std::endl;			// And = 1
	std::cout << "Or = " << multiOr << std::endl;			// Or = 1
	std::cout << "Mix = " << multiMix << std::endl;			// Mix = 1
	std::cout << "Group = " << multiGroup << std::endl;		// Group = 0 

	/* beginning of part 2 - conditional statements */

	int nValOne = 5;
	int nValTwo = 4;
	int nValThree = 7;

	if (nValOne < nValTwo) {
		std::cout << nValOne << " < " << nValTwo << std::endl; 
	}
	else if (nValOne > nValThree) {
		std::cout << nValOne << " > " << nValThree << std::endl;
	}
	else if (nValOne + nValTwo > nValThree) {
		int tmp = nValOne + nValTwo;
		std::cout << tmp << " > " << nValThree << std::endl;
	}
	else {
		std::cout << "All conditions failed" << std::endl; 
	}
	// the output for this if statement is "9 > 7"

	if (bAnd && bOr && bNot)
		std::cout << "All conditions were true!" << std::endl;
	// since bAnd, bOr, and bNot are true, the statement prints the string

	if (multiAnd) {

		if (multiGroup) {
			std::cout << "multi-and && multi-group" << std::endl;
		}
		else {
			std::cout << "multi-and && !multi-group" << std::endl;
		}
	}

	else {

		if (multiOr) {
			std::cout << "!multi-and && multi-or" << std::endl;
		}

		else {
			std::cout << "!multi-and && !multi-or" << std::endl;
		}

	}
	// the output of this if statement is "multi-and && !multi-group" 

	char choice = ' ';
	std::string output = "You chose menu: ";

	std::cout << "Choose from the following menu: \n"
		<< "\t[F]ile\n"
		<< "\t[E]dit\n"
		<< "\t[V]iew\n"
		<< "\t[H]elp: ";

	std::cin >> choice;

	switch (choice) {

	case 'F': case 'f':
		output += "File";
		break;

	case 'E': case 'e':
		output += "Edit";
		break;

	case 'V': case 'v':
		output += "View";
		break;

	case 'H': case 'h':
		output += "Help";
		break;

	default:
		output = "Invalid choice!";

	}

	std::cout << output << std::endl;

	return 0;

}