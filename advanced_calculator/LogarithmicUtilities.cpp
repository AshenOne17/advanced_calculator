#include "LogarithmicUtilities.h"

#include <iostream>

int log_calculation_type_input()
{
	int choice = 0;

	std::cout << "[1] Logarithmic function\n[2] Exponential function\nChoose the function calculation type: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2)
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nChoose the function calculation type: ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
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

// To Do.