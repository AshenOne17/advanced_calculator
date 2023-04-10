#include "LogarithmicUtilities.h"

#include <iostream>

/*
 * Source file for "LogarithmicUtilities.h" header, containing functions definitions. See "LogarithmicUtilities.h"
 * for further functions descriptions.
 */

int log_calculation_type_input()
{
	int choice = 0;

	std::cout << "[1] Logarithmic function\n[2] Exponential function\nChoose the function calculation type: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2)
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nChoose the function calculation type: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> choice;
	}

	return choice;
}

long int log_base_input()
{
	long int log_base = 0;

	std::cout << "\nEnter the logarithm base (positive number except for 1 and 0): ";

	while (true)
	{
		if (!(std::cin >> log_base))
		{
			std::cout << "Invalid input. Try again.\n";
            std::cout << "\nEnter the logarithm base (positive number except for 1): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (log_base <= 0 || log_base == 1)
		{
			std::cout << "Error. Logarithm base can't be lower or equal to 0 or equal to 1. Try again.\n";
			std::cout << "\nEnter the logarithm base (positive number except for 1): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}

	return log_base;
}

long double log_number_input()
{
	long double log_number = 0;

	std::cout << "\nEnter the logarithm number (positive number except for 0): ";

	while (true)
	{
		if (!(std::cin >> log_number))
		{
			std::cout << "Invalid input. Try again.\n";
            std::cout << "\nEnter the logarithm number (positive number except for 1): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (log_number <= 0)
		{
			std::cout << "Error. Logarithm number can't be lower or equal to 0. Try again.\n";
            std::cout << "\nEnter the logarithm base (positive number except for 1): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}

	return log_number;
}

long double exp_base_input(const long double exponent)
{
    long double base = 0;

    std::cout << "\n(If the exponent is 0, base can be any non-zero number.)\n"
              "Enter the base for exponential function (positive number): ";

    while (true)
    {
        if (!(std::cin >> base))
        {
            std::cout << "Invalid input. Try again.\n";
            std::cout << "\nEnter the base for exponential function: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (base <= 0)
        {
            if (exponent >= 0.0 && base == 0.0)
            {
                std::cout << "Invalid input. Base can't be zero when the exponent is positive. Try again.\n";
            }
            else if (exponent != std::floor(exponent) && base < 0)
            {
                std::cout << "Invalid input. Raising a negative number to a non-integer exponent results in a complex number. Try again.\n";
            }
            else
            {
                std::cout << "Invalid input. Base should be a positive number. Try again.\n";
            }

            std::cout << "\nEnter the base for exponential function: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    return base;
}

long double exp_exponent_input()
{
	long double exponent = 0;

	std::cout << "\nEnter the exponent for exponential function: ";

	while (!(std::cin >> exponent))
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nEnter the exponent for exponential function: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return exponent;
}