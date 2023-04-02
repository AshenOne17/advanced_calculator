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

	std::cout << "Enter the logarithm base (positive number except for 1 and 0): ";

	while (true)
	{
		if (!(std::cin >> log_base))
		{
			std::cout << "Invalid input. Try again.\n";
            std::cout << "\nEnter the logarithm base (positive number except for 1): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (log_base < 2)
		{
			std::cout << "Error. Logarithm base can't be lower than 2. Try again.\n";
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

long int log_number_input()
{
	long int log_number = 0;

	std::cout << "Enter the logarithm number (positive number except for 0): ";
	std::cin >> log_number;

	while (true)
	{
		if (!(std::cin >> log_number))
		{
			std::cout << "Invalid input. Try again.\n";
            std::cout << "\nEnter the logarithm base (positive number except for 1): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (log_number < 1)
		{
			std::cout << "Error. Logarithm number can't be lower than 1. Try again.\n";
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