#include "TrigonometricUtilities.h"

#include <iostream>

int input_unit_type()
{
	int choice = 0;

	// Choosing the type of input value (degrees or radians)
	std::cout << "Types of input:\n[1]Degrees\n[2]Radians\n\n";
	std::cout << "Your choice: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2)
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Your choice: ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> choice;
	}

	return choice;
}

int function_type()
{
	int choice = 0;

	// Choosing the type of function (trigonometric or hyperbolic)
	std::cout << "\nTypes of functions:\n[1]Trigonometric\n[2]Hyperbolic\n\n";
	std::cout << "Your choice: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2)
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Your choice: ";

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> choice;
	}

	return choice;
}

int trig_function_type()
{
	int choice = 0;

	// Choosing the trigonometric function
	std::cout << "\nFunctions:\n[1]Sin\n[2]Cos\n[3]Tan\n[4]Arcsin\n[5]Arccos\n[6]Arctan\n";
	std::cout << "\nChoose the function: ";
	while (!(std::cin >> choice) || (choice < 1 || choice > 6))
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nChoose the function: ";
		std::cin >> choice;
		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}

	return choice;
}

int hyperbolic_function_type()
{
	int choice = 0;

	// Choosing the hyperbolic function
	std::cout << "\nFunctions:\n[1]Sinh\n[2]Cosh\n[3]Tanh\n[4]Arcsinh\n[5]Arccosh\n[6]Arctanh\n";
	while (!(std::cin >> choice) || (choice < 1 || choice > 6))
	{
		std::cout << "Invalid input. Try again.\n";
		std::cout << "\nChoose the function: ";
		std::cin >> choice;
		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return choice;
}

long double input_angle()
{
	long double angle = 0;

	// Entering the angle value
	std::cout << "\nEnter the angle: ";

	while (!(std::cin >> angle))
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Enter the angle: ";

		// The purpose of std::cin.clear() and std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') 
		// is to clear the error state of the input stream and discard any extraneous input, respectively. 
		// If you expect only either 1 or 2 as the input, you can simply check the validity of the input 
		// using an if statement and ask the user to input again if it's invalid, without the need to use std::cin.

		// Clear the fail flag
		std::cin.clear();

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return angle;
}