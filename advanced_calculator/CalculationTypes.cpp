#include "CalculatorModes.h"
#include "CalculationTypes.h"
#include <iostream>

void printError()
{
	std::cout << "Invalid input. Try again.\n\n";
	std::cin.clear();  // clear the fail flag
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard the invalid input
}

void arithmetic_calculation() 
{
	ArithmeticCalc<long long> CALC;
	long long lValue = 0, rValue = 0;

	std::cout << "Enter the first value: ";
	while (!(std::cin >> lValue))
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Enter the first value: ";
		std::cin.clear();  // clear the fail flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard the invalid input
	}
	CALC.setLValue(lValue);

	char arithmetic = '.';
	std::cout << "\nEnter the desired operation(+, -, *, /): ";
	while (!(std::cin >> arithmetic) || (arithmetic != '+' && arithmetic != '-' && arithmetic != '*' && arithmetic != '/'))
	{
		std::cout << "Operation invalidation! Try again.\n";
		std::cout << "\nEnter the desired operation(+, -, *, /): ";
		std::cin.clear();  // clear the fail flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard the invalid input
	}

	std::cout << '\n';

	std::cout << "Enter the second value: ";
	while (!(std::cin >> rValue))
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Enter the second value: ";
		std::cin.clear();  // clear the fail flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard the invalid input
	}
	CALC.setRValue(rValue);

	std::cout << "--------\n" << "Output result: ";

	switch (arithmetic)
	{
	case '+':
	{
		std::cout << CALC.addition() << "\n\n";
		break;
	}
	case '-':
	{
		std::cout << CALC.substraction() << "\n\n";
		break;
	}
	case '*':
	{
		std::cout << CALC.multiplication() << "\n\n";
		break;
	}
	case '/':
	{
		std::cout << CALC.division() << "\n\n";
		break;
	}
	default:
	{
		std::cout << "Error. Input invalidation!\n";
	}
	}
}

void trigonometry_calculation()
{
}

void exponential_calculation()
{
}

void logarithmic_calculation()
{
}
