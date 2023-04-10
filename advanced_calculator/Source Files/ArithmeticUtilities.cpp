#include "ArithmeticUtilities.h"

#include <iostream>

/*
 * Source file for "ArithmeticUtilities.h" header, containing functions definitions. See "ArithmeticUtilities.h"
 * for further functions descriptions.
 */

long long l_value_input()
{
	long long first_value = 0;

	// Entering the first (left operand) value
	std::cout << "Enter the first value: ";

	while (!(std::cin >> first_value))
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Enter the first value: ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
	}

	return first_value;
}

char op_input()
{
	char op = '.';

	// Entering the operation type
	std::cout << "\nEnter the desired operation(+, -, *, /): ";

	while (!(std::cin >> op) || (op != '+' && op != '-' && op != '*' && op != '/'))
	{
		std::cout << "Operation invalidation! Try again.\n";
		std::cout << "\nEnter the desired operation(+, -, *, /): ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
	}

	return op;
}

long long r_value_input(const char op)
{
	long long second_value = 0;

	// Entering the second value;
	std::cout << "\nEnter the second value: ";

	while (true)
	{
		if (!(std::cin >> second_value))
		{
			std::cout << "Invalid input. Try again.\n\n";
			std::cout << "Enter the second value: ";
			
			// Clear the fail flag
			std::cin.clear();

			// Discard the invalid input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (op == '/')
		{
			if (second_value == 0)
			{
				std::cout << "Invalid input. You can't divide by zero! Try again.\n\n";
				std::cout << "Enter the second value: ";

				// Clear the fail flag
				std::cin.clear();

				// Discard the invalid input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		else
		{
			break;
		}
		
	}

	return second_value;
}