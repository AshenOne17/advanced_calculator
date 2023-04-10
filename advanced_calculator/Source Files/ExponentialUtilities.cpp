#include "ExponentialUtilities.h"

#include <iostream>

/*
 * Source file for "ExponentialUtilities.h" header, containing functions definitions. See "ExponentialUtilities.h"
 * for further functions descriptions.
 */

int operation_input()
{
	int choice = 0;

	std::cout << "[1] Power raising\n[2] Root calculation\nChoose the exponential calculation type: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2)
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nChoose the exponential calculation type: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> choice;
	}

	return choice;
}

long int exponent_input(const long double base)
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

    long int exponent = 0.0;

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
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (base < 0 && (floor(exponent) != exponent || fmod(exponent, 2) == 0.0))
        {
            std::cout << "Invalid input. If the base is negative, the exponent must be an integer or a fraction with an odd denominator.\n";
            std::cout << "\nEnter the exponent: ";
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return base;
}

long int root_power_input()
{
	long int root_exponent = 0.0;

	std::cout << "\nEnter the root power: ";

	while (true)
	{
		if (!(std::cin >> root_exponent))
		{
			std::cout << "Invalid input. Try again.\n";
			std::cout << "Enter the root power: ";
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (root_exponent == 0.0)
		{
			std::cout << "\nError. Root exponent can't be 0.\n\n";
			std::cout << "Enter the root power: ";
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}

	return root_exponent;
}

long double radicand_input(const long int root_power)
{
	long double radicand = 0.0;

	std::cout << "Enter the radicand (number under square root): ";

	while (true)
	{
		if (!(std::cin >> radicand))
		{
			std::cout << "Invalid input. Try again.\n";
			std::cout << "\nEnter the radicand (number under square root): ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (radicand < 0)
		{
			std::cout << "\nError. Radicand can't be lower than 0. Try again.\n\n";
			std::cout << "Enter the radicand (number under square root): ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (root_power % 2 == 0 && radicand < 0)
		{
			std::cout << "\nError: a must be non-negative if n is even. Try again.\n\n";
			std::cout << "Enter the radicand (number under square root): ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}

	return radicand;
}