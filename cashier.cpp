/*************************************************************************
* File: cashier.cpp
* Author: Juan Ariza
* Class: COP 2001; 201805; 50135
* Purpose: simple cash register simulator
**************************************************************************/

#include <iostream>

const int TWENTY = 2000;
const int TEN = 1000;
const int FIVE = 500;
const int ONE = 100;
const int QUARTER = 25;
const int DIME = 10;
const int NICKLE = 5;
const int PENNY = 1;


int main() {

	float price = 0.0;
	float cash = 0.0;

	std::cout << "Enter sales price: ";
	std::cin >> price;

	std::cout << "Enter cash tendered: ";
	std::cin >> cash;

	int change = (cash - price) * ONE;

	std::cout << "Change returned: " << ((float)change / ONE) << std::endl;

	int twenties = change / TWENTY;
	change %= TWENTY;

	int tens = change / TEN;
	change %= TEN;

	int fives = change / FIVE;
	change %= FIVE;

	int ones = change / ONE;
	change %= ONE;

	int quarters = change / QUARTER;
	change %= QUARTER;

	int dimes = change / DIME;
	change %= DIME;

	int nickles = change / NICKLE;
	change %= NICKLE;

	int pennies = change;



	std::cout << "\tTwenties: " << twenties << std::endl << "\tTens: " << tens << std::endl << "\tFives: " << fives << std::endl << "\tOnes: " << ones << std::endl
		<< "\tQuarters: " << quarters << std::endl << "\tDimes: " << dimes << std::endl << "\tNickles: " << nickles << std::endl << "\tPennies: " << pennies << std::endl;


	return 0;

}
