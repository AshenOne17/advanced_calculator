#include "ExponentialUtilities.h"

#include <iostream>

int operation_input()
{
	int choice = 0;

	std::cout << "Choose the exponential calculation type: \n[1] Power raising\n[2] Square root\n\n";
	while (!(std::cin >> choice) || (choice != 1 && choice != 2))
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nEnter the exponent: ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}

	return choice;
}

double exponent_input()
{
	double exponent = 0.0;

	std::cout << "Enter the exponent: ";
	
	while (!(std::cin >> exponent))
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nEnter the exponent: ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}

	return exponent;
}

long double base_input()
{
	long double base = 0.0;

	std::cout << "Enter the base: ";
	
	while (!(std::cin >> base))
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nEnter the base: ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}

	return base;
}

long double radicand_input()
{
	long double radicand = 0.0;

	std::cout << "Enter the radicand (number under square root): ";
	
	while (!(std::cin >> radicand) || radicand < 0)
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nEnter the radicand (number under square root): ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}

	return radicand;
}
