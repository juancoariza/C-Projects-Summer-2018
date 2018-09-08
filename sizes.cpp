/*************************************************************************
* File: sizes.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: Demonstrate the data types and sizes of data types in C++
**************************************************************************/

#include <iostream>
#include <math.h>	//included for class sample

int main() {

	char vChar = 'A';					// size - 1 Byte
	char16_t vChar16 = 'B';				// size - 2 Bytes
	char32_t vChar32 = 'C';				// size - 4 Bytes			
	wchar_t vWChar = 'D';				// size - 2 Bytes

	short int vShort = 1;				// size - 2 Bytes
	int vInt = 2;						// size - 4 Bytes
	long vLong = 3;						// size - 4 Bytes
	long long vLLong = 4;				// size - 8 bytes

	unsigned char vUChar = 'E';			// size - 1 Byte
	unsigned short vUShort = 5;			// size - 2 Bytes
	unsigned int vUInt = 6;				// size - 4 Bytes
	unsigned long vULong = 7;			// size - 4 Bytes
	unsigned long long vULLong = 9;		// size - 8 BYtes

	float vFloat = 5.0;					// size - 4 Bytes
	double vDouble = 5.1;				// size - 8 Bytes
	long double vLDouble = 5.2;			// size - 16 BYtes

	bool vBool = true;					// size - 1 Byte

	std::string vString = "Size of ";	// size - 28 Bytes

	std::cout << "size of char = " << sizeof(vChar) << " Byte(s)" << std::endl;
	std::cout << "size of char16_t = " << sizeof(vChar16) << " Byte(s)" << std::endl;
	std::cout << "size of char32_t = " << sizeof(vChar32) << " Byte(s)" << std::endl;
	std::cout << "size of vWChar = " << sizeof(vWChar) << " Byte(s)" << std::endl;

	std::cout << "size of short = " << sizeof(vShort) << " Byte(s)" << std::endl;
	std::cout << "size of int = " << sizeof(vInt) << " Byte(s)" << std::endl;
	std::cout << "size of long = " << sizeof(vLong) << " Byte(s)" << std::endl;
	std::cout << "size of long long = " << sizeof(vLLong) << " Byte(s)" << std::endl;

	std::cout << "size of unsigned char = " << sizeof(vUChar) << " Byte(s)" << std::endl;
	std::cout << "size of unsigned short = " << sizeof(vUShort) << " Byte(s)" << std::endl;
	std::cout << "size of unsigned int = " << sizeof(vUInt) << " Byte(s)" << std::endl;
	std::cout << "size of unsigned long = " << sizeof(vULong) << " Byte(s)" << std::endl;
	std::cout << "size of unsigned long long = " << sizeof(vULLong) << " Byte(s)" << std::endl;

	std::cout << "size of float = " << sizeof(vFloat) << " Byte(s)" << std::endl;
	std::cout << "size of double = " << sizeof(vDouble) << " Byte(s)" << std::endl;
	std::cout << "size of long double = " << sizeof(vLDouble) << " Byte(s)" << std::endl;

	std::cout << "size of bool = " << sizeof(vBool) << " Byte(s)" << std::endl;

	std::cout << "size of string = " << sizeof(vString) << " Byte(s)" << std::endl;

	//below is the class sample 
	char sampChar = 127 ;
	std::cout << "Char size: " << int(sampChar) << std::endl;

	sampChar++;
	std::cout << "Char size: " << int(sampChar) << std::endl;

	sampChar++;
	std::cout << "Char size: " << int(sampChar) << std::endl;

	sampChar--;
	std::cout << "Char size: " << int(sampChar) << std::endl;

	sampChar--;
	std::cout << "Char size: " << int(sampChar) << std::endl;


	int sampInt = std::pow(2, 32) / 2 - 1;
	std::cout << "Int size: " << sampInt << std::endl;
	
	sampInt++;
	std::cout << "Int size: " << sampInt << std::endl;

	sampInt++;
	std::cout << "Int size: " << sampInt << std::endl;

	sampInt--;
	std::cout << "Int size: " << sampInt << std::endl;

	sampInt--;
	std::cout << "Int size: " << sampInt << std::endl;


	unsigned int sampUInt = std::pow(2, 32) - 1;
	std::cout << "Unsigned int size: " << sampUInt << std::endl;

	sampUInt++;
	std::cout << "Unsigned int size: " << sampUInt << std::endl;

	sampUInt++;
	std::cout << "Unsigned int size: " << sampUInt << std::endl;

	sampUInt--;
	std::cout << "Unsigned int size: " << sampUInt << std::endl;

	sampUInt--;
	std::cout << "Unsigned int size: " << sampUInt << std::endl;

	return 0;

}