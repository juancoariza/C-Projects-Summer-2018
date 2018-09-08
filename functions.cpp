/******************************************************************************
* File: functions.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: Demonstrate user-defined functions in C++
******************************************************************************/


#include <iostream>
#include <string>

using namespace std;

const unsigned char UPPERCASE = 0xDF;	// hex equivalent to 1101 1111
const int MAX_BITS = 8;					// max size of binary number

void getBinaryStr(int maxBits, string& binStr, int& binLen); // get a binary string from the user
int power(int base, int exponent);

/* the only difference between a lowercase and uppercase letter
   is that a lowercase code has the 5th bit activated, i.e: 
	A = 65 = 0100 0001
	a = 97 = 0110 0001 */

int main() {

	string binaryIn = "";		// string of binary bits
	int decimal = 0;			// decimal value of binary string
	bool done = false;			// try-again flag

	while (!done) {

		// get binary number from user
		cout << "Enter a binary value: ";
		cin >> binaryIn;

		// calculate its decimal value
		decimal = 0;	// resets decimal to zero

		// get a binary number from the user
		string binaryIn = "";
		int binaryLen = 0;
		getBinaryStr(MAX_BITS, binaryIn, binaryLen);

		// pos - positional value of bit within the binary string
		for (int pos = 0; pos < binaryIn.length(); pos++) {

			/* get the bits working from end of the string (right) 
			   to the front of the string (left) */

			int bit = binaryIn[binaryIn.length() - 1 - pos] - '0';	// -1 for a zero-based array
																	// - '0' to convert character to value
			decimal += bit * power(2, pos);
		}

		cout << binaryIn << " = " << decimal << " in decimal " << endl;
		cout << endl; // spacer

		// ask if user is done converting binary values
		cout << "Exit (Y/N): ";
		char tmp;
		cin >> tmp;

		//set done to true if user enters capital 'Y'
		tmp &= UPPERCASE;		// turns off the 5th bit in the character
		done = tmp == 'Y';

		cout << endl;
	} // ends while loop 

	return 0;
}


/**
* Raises a base value to an exponent
* @param base - the base value to raise
* @param exponent - the power to raise the value to
* @return int - the product of the exponent (1 if exponent is zero)
*/
int power(int base, int exponent) {

	int product = 1; //returns 1 if exponent is 0

					// loop n - 1 times if non-zero
	while (exponent > 0) {

		product *= base;	// multiply product by base
		exponent--;			// decrement the exponent

	}

	return product;

} // end power

/**
* Get a binary string from the user
* @param maxBits - the maximum number of bits the binary number can have
* @param binStr OUT - the binary number as a string 
* @param binLen OUT - the length of the bianry string
*/
void getBinaryStr(int maxBits, string& binStr, int& binLen) {

	string sBin = "";

	while (sBin.length() == 0 || sBin.length() > maxBits) {

		// get a binary number from user
		cout << "Enter a binary value up to " << maxBits << " bits: ";
		cin >> sBin;	// requires #include <string>

		// check for zero-length string 
		if (sBin.length() == 0)
			cout << "You did not enter a Binary number, try again." << endl;

		// check for length greater than max 
		if (sBin.length() > maxBits)
			cout << "Binary value larger than max, try again." << endl;
	}

	binStr = sBin;				// return the binary string
	binLen = sBin.length();		// return length of the binary string


} // end getBinaryStr