/******************************************************************************
* File: loops.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: Demonstrate the use of conditional and control loops in C++
******************************************************************************/

#include <iostream>
#include <string>
#include <cctype> // included for Flag loop 

int main() {

	int number = 2;
	int exponent = 8;
	int result = 1;

	int counter = 0;
	while (counter < exponent) {

		result *= number;
		counter++;

	}

	std::cout << number << " ^ " << exponent << " = " << result << std::endl;
	std::cout << std::end << std::endl;
	
	// pauses program by prompting for input
	std::cout << "Enter any key to continue: ";
	char tmp;
	std::cin >> tmp;

	/* start of decrement loop */

	number = 5; // values are hardcoded to re-use the variable names
	result = 1;

	counter = 0;

	while (exponent > counter) {

		result = number;
		number -= 2;
		exponent--;

		std::cout << result << " - 2 = " << number << std::endl;
		// each time the loop runs, "result" will be subtracted by 2
		// "exponent" starts at 8, and is decremented with each run until it reaches 0
	}


	/* start of increment for loop */

	number = 2;
	exponent = 8;
	result = 1;

	for (int counter = 0; counter < exponent; counter++) {

		result *= number;

	}

	/* start of decrement for loop */

	number = 2;
	exponent = 8;
	result = 1;

	for (int counter = exponent; counter > 0; counter--) {

		result *= number;

	}

	/* start of Sentinel loop example */

	int decimal = 53;			// decimal value to convert
	int base = 2;				// base value converter (binary)
	std::string binary = "";	// shows binary digits as a string

	int quotient = decimal;		// initial quotient to decimal value

	// divides until the quotient is 0
	while (quotient > 0) {

		// int remainder is the next digit
		int digit = quotient % base;

		// adds digit to left of the current result
		binary = std::to_string(digit) + binary; 

		// calculates next quotient
		quotient /= base;

	}

	std::cout << "decimal: " << decimal << " = binary: " << binary << std::endl;

	/* start of Flag loop example */

	bool done = false; 

	// continue program while user is not done
	while (!done) {

		// execution statements

		std::cout << "Keep running (Y/N): ";
		char askDone;
		std::cin >> askDone;
		done = std::toupper(askDone) == 'Y';
	}

	/* start of Do While loop example */

	char choice = ' ';

	do {

		std::string output = "You chose menu: ";

		std::cout << "Choose from the following menu: \n"
			<< "\t[F]ile\n"
			<< "\t[E]dit\n"
			<< "\t[V]iew\n"
			<< "\t[H]elp\n"
			<< "\tE[x]it: ";

		std::cin >> choice;

		switch (choice) {

		case 'F': case 'f':
			std::cout << output << "File" << std::endl;
			break;

		case 'E': case 'e':
			std::cout << output << "Edit" << std::endl;
			break;

		case 'V': case 'v':
			std::cout << output << "View" << std::endl;
			break;

		case 'H': case 'h':
			std::cout << output << "Help" << std::endl;
			break;

		case 'X': case 'x':
			break;

		default:
			output = "Invalid choice!";

		}
	
	} while (choice != 'X' && choice != 'x');


	return 0;

}