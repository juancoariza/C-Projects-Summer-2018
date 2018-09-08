#include <iostream>

//Juan Ariza
//COP 2001 Summer 2018
//Lab 2 - Variables
//5-17-2018

int main() {

	const int X_INTERCEPT = 2;

	int x, y;

	x = X_INTERCEPT;

	y = 3 * x - 5;

	std::cout << "y(" << y << ") = 3 * x(" << X_INTERCEPT << ") - 5" << std::endl; // also possible: << '\n' ;

	// below is an in-class example

	const float TAX_RATE = 0.06;

	float meal = 0;
	float tipPercent = 0.0;
	float subtotal = 0.0;
	float total = 0.0;

	std::cout << "Enter the meal price: ";
	std::cin >> meal;

	std::cout << "Enter the tip percentage: (20.00): ";
	std::cin >> tipPercent;

	tipPercent /= 100;

	subtotal = meal + (meal + TAX_RATE);

	total = subtotal + (subtotal * tipPercent);

	std::cout << "Meal: " << meal << std::endl;
	std::cout << "Subtotal: " << subtotal << std::endl;
	std::cout << "Total: " << total << std::endl;


	return 0;

}