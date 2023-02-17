#include "CalculatorModes.h"
#include "CalculationTypes.h"
#include <iostream>

# define M_PIl 3.141592653589793238462643383279502884L
# define M_PIl_2 M_PIl / 2

void arithmetic_calculation() 
{
	ArithmeticCalc<long long> CALC;

	long long first_value = 0;

	// Entering the first (left operand) value
	std::cout << "Enter the first value: ";
	while (!(std::cin >> first_value))
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Enter the first value: ";
		std::cin.clear();  // clear the fail flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard the invalid input
	}
	CALC.setLValue(first_value);

	char arithmetic_operation = '.';

	// Enterting the operation type
	std::cout << "\nEnter the desired operation(+, -, *, /): ";
	while (!(std::cin >> arithmetic_operation) || 
		  (arithmetic_operation != '+' && arithmetic_operation != '-' 
		  && arithmetic_operation != '*' && arithmetic_operation != '/'))
	{
		std::cout << "Operation invalidation! Try again.\n";
		std::cout << "\nEnter the desired operation(+, -, *, /): ";
		std::cin.clear();  // clear the fail flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard the invalid input
	}

	long long second_value = 0;

	// Entering the second value;
	std::cout << "\nEnter the second value: ";
	while (!(std::cin >> second_value))
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Enter the second value: ";
		std::cin.clear();  // clear the fail flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard the invalid input
	}
	CALC.setRValue(second_value);

	std::cout << "--------\nOutput result: ";

	switch (arithmetic_operation)
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
	default: std::cout << "Error. Input invalidation!\n";
	}
}

void trigonometry_calculation()
{
	TrigonometryCalc<float> CALC;

	long double angle_value = 0.0;

	int measure_choice = 0;

	// Choosing the type of input value (degrees or radians)
	std::cout << "Types of input:\n[1]Degrees\n[2]Radians\n\n";
	std::cout << "Your choice: ";
	std::cin >> measure_choice;
	while (measure_choice != 1 && measure_choice != 2) 
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Your choice: ";
	}
	
	// Entering the angle value
	std::cout << "\nEnter the number: ";
	while (!(std::cin >> angle_value))
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Enter the number: ";

		// The purpose of std::cin.clear() and std::cin.ignore(std::numeric_limitsstd::streamsize::max(), '\n') 
		// is to clear the error state of the input stream and discard any extraneous input, respectively. 
		// If you expect only either 1 or 2 as the input, you can simply check the validity of the input 
		// using an if statement and ask the user to input again if it's invalid, without the need to use std::cin.

		// Clear the fail flag
		std::cin.clear();  

		// Discard the invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	int function_choice = 0;

	// Choosing the type of function (trigonometric or hyperbolic)
	std::cout << "\nTypes of functions:\n[1]Trigonometric\n[2]Hyperbolic\n\n";
	std::cout << "Your choice: ";
	std::cin >> function_choice;
	while (function_choice != 1 && function_choice != 2) 
	{
		std::cout << "Invalid input. Try again.\n\n";
		std::cout << "Your choice: ";
	}

	// Trigonometric types of functions
	if (function_choice == 1)
	{
		// If we chose degrees, convert them to radians since trigonometric functions accept values in radians
		// Convertation by formula:
		// (Degrees * Pi) / 180
		if (measure_choice == 1) 
		{
			if (angle_value < -180 || angle_value > 180) {
				angle_value = fmod(angle_value, 360);
				if (angle_value < 0) {
					angle_value += 360;
				}
			}
			CALC.setRad((angle_value * M_PIl) / 180);
		}
		else 
		{
			angle_value = fmod(angle_value, 2 * M_PIl);
			if (angle_value < 0) {
				angle_value += 2 * M_PIl;
			}
			CALC.setRad(angle_value);
		}

		int trigonometric_choice = 0;

		// Choosing the trigonometric function
		std::cout << "\nFunctions:\n[1]Sin\n[2]Cos\n[3]Tan\n[4]Arcsin\n[5]Arccos\n[6]Arctan\n";
		while (!(std::cin >> trigonometric_choice) || (trigonometric_choice < 1 || trigonometric_choice > 6))
		{
			std::cout << "Invalid input. Try again.\n\n";
			std::cout << "\nChoose the function: ";
			// Clear the fail flag
			std::cin.clear();

			// Discard the invalid input
			std::cin.ignore();
		}

		std::cout << "--------\nOutput result: ";

		switch (trigonometric_choice) 
		{
		case 1: 
		{
			std::cout << "Sin(" << angle_value << ") = " << CALC.sinCalc() << "\n\n";
			break;
		}
		case 2: 
		{
			if (measure_choice == 1)
			{
				if (angle_value <= -180 || angle_value >= 180)
				{
					std::cout << "Wrong angle for cosine. Out of interval [-180^; 180^].\n";
					break;
				}
			}
			else if (measure_choice == 2)
			{
				
			}
			std::cout << "Cos(" << angle_value << ") = " << CALC.cosCalc() << "\n\n";
			break;
		}
		case 3: 
		{
			std::cout << "Tan(" << angle_value << ") = " << CALC.tanCalc() << "\n\n";
			break;
		}
		case 4: 
		{
			std::cout << "Arcsin(" << angle_value << ") = " << CALC.arcsinCalc() << "\n\n";
			break;
		}
		case 5:
		{
			std::cout << "Arccos(" << angle_value << ") = " << CALC.arccosCalc() << "\n\n";
			break;
		}
		case 6: 
		{
			std::cout << "Arctan(" << angle_value << ") = " << CALC.arctanCalc() << "\n\n";
			break;
		}
		default: std::cout << "Input invalidation!\n\n";
		}
	}
	// Hyperbolic types of functions
	else  
	{
		// Creating hyperbolic calculator object
		TrigonometryHyperbolicCalc<float> TrigHyperCALC;

		// Setting the angle value using the already converted value
		TrigHyperCALC.setRad(CALC.getRad());

		int hyperbolic_choice = 0;

		// Choosing the hyperbolic function
		std::cout << "\nFunctions:\n[1]Sinh\n[2]Cosh\n[3]Tanh\n[4]Arcsinh\n[5]Arccosh\n[6]Arctanh\n";
		while (!(std::cin >> hyperbolic_choice) || (hyperbolic_choice < 1 || hyperbolic_choice > 6))
		{
			std::cout << "Invalid input. Try again.\n\n";
			std::cout << "\nChoose the function: ";

			// Clear the fail flag
			std::cin.clear();

			// Discard the invalid input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cout << "--------\n" << "Output result: ";

		switch (hyperbolic_choice)
		{
		case 1:
		{
			std::cout << "Sinh(" << angle_value << ") = " << TrigHyperCALC.sinhCalc() << "\n\n";
			break;
		}
		case 2:
		{
			std::cout << "Cosh(" << angle_value << ") = " << TrigHyperCALC.coshCalc() << "\n\n";
			break;
		}
		case 3:
		{
			std::cout << "Tanh(" << angle_value << ") = " << TrigHyperCALC.tanhCalc() << "\n\n";
			break;
		}
		case 4:
		{
			std::cout << "Arcsinh(" << angle_value << ") = " << TrigHyperCALC.arcsinhCalc() << "\n\n";
			break;
		}
		case 5:
		{
			std::cout << "Arccosh(" << angle_value << ") = " << TrigHyperCALC.arccoshCalc() << "\n\n";
			break;
		}
		case 6:
		{
			std::cout << "Arctanh(" << angle_value << ") = " << TrigHyperCALC.arctanhCalc() << "\n\n";
			break;
		}
		default: std::cout << "Input invalidation!\n\n";
		}
	}
}

void exponential_calculation()
{
}

void logarithmic_calculation()
{
}
