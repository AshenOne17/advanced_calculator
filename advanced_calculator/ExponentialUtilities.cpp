#include "ExponentialUtilities.h"

#include <iostream>

int operation_input()
{
	int choice = 0;

	std::cout << "[1] Power raising\n[2] Square root\nChoose the exponential calculation type: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2)
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nChoose the exponential calculation type: ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> choice;
	}

	return choice;
}

double exponent_input(const long double base)
{
	/*
	The exponent must be a real number. This means that it can be a positive number, a negative number, zero, or a fraction.
	However, it cannot be an imaginary number, such as the square root of -1.
	
	If the base is a positive number, the exponent can be any real number.
	For example, 2 raised to the power of pi is a valid expression.
	
	If the base is negative, the exponent must be an integer or a fraction with an odd denominator.
	For example, (-2) raised to the power of 3 is a valid expression, but (-2) raised to the power of 1/2 is not.
	
	If the base is zero, the exponent must be positive.
	For example, 0 raised to the power of 5 is equal to 0, but 0 raised to the power of -2 is undefined.
	
	If the exponent is zero, the result is always 1, regardless of the value of the base.
	
	If the exponent is negative, the expression can be rewritten as a fraction with a positive exponent by using the reciprocal of the base.
	For example, 2 raised to the power of -3 is the same as 1 over 2 raised to the power of 3, which is equal to 1/8.
	*/

    double exponent = 0.0;

    std::cout << "Enter the exponent: ";

    while (true)
    {
        if (!(std::cin >> exponent))
        {
            std::cout << "Invalid input. Try again.\n";
            std::cout << "\nEnter the exponent: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (base == 0.0 & exponent <= 0)
        {
            std::cout << "Invalid input. If the base is zero, the exponent must be positive.\n";
            std::cout << "\nEnter the exponent: ";
        }
        else if (base < 0 && (floor(exponent) != exponent || fmod(exponent, 2) == 0.0))
        {
            std::cout << "Invalid input. If the base is negative, the exponent must be an integer or a fraction with an odd denominator.\n";
            std::cout << "\nEnter the exponent: ";
        }
        else
        {
            break;
        }
    }

    return exponent;
}

long double base_input()
{
	long double base = 0.0;

	std::cout << "\nEnter the base: ";
	
	while (!(std::cin >> base))
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nEnter the base: ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return radicand;
}
