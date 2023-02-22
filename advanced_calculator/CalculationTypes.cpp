#include "CalculatorModes.h"
#include "CalculationTypes.h"
#include "TrigonometricUtilities.h"

#include <iostream>

# define M_PIl 3.141592653589793238462643383279502884L

void arithmetic_calculation() 
{
	arithmetic_calc<long long> calc;

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
	calc.set_l_value(first_value);

	char arithmetic_operation = '.';

	// Entering the operation type
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
	calc.set_r_value(second_value);

	std::cout << "--------\nOutput result: ";

	switch (arithmetic_operation)
	{
	case '+':
	{
		std::cout << calc.addition() << "\n\n";
		break;
	}
	case '-':
	{
		std::cout << calc.substraction() << "\n\n";
		break;
	}
	case '*':
	{
		std::cout << calc.multiplication() << "\n\n";
		break;
	}
	case '/':
	{
		std::cout << calc.division() << "\n\n";
		break;
	}
	default: std::cout << "Error. Input invalidation!\n";
	}
}

// *** Explicitly declaring template functions due to file management restrictions ***

template <typename Type>
void trig_output(const int function_choice, const long double angle, trigonometry_calc<Type>& calc)
{
	switch (function_choice)
	{
	case 1:
	{
		std::cout << "Sin(" << angle << ") = " << calc.sin_calc() << "\n\n";
		break;
	}
	case 2:
	{
		std::cout << "Cos(" << angle << ") = " << calc.cos_calc() << "\n\n";
		break;
	}
	case 3:
	{
		std::cout << "Tan(" << angle << ") = " << calc.tan_calc() << "\n\n";
		break;
	}
	case 4:
	{
		std::cout << "Arcsin(" << angle << ") = " << calc.arcsin_calc() << "\n\n";
		break;
	}
	case 5:
	{
		std::cout << "Arccos(" << angle << ") = " << calc.arccos_calc() << "\n\n";
		break;
	}
	case 6:
	{
		std::cout << "Arctan(" << angle << ") = " << calc.arctan_calc() << "\n\n";
		break;
	}
	default: std::cout << "Input invalidation!\n\n";
	}
}

template <typename Type>
void hyperbolic_output(const int function_choice, const long double angle, trigonometry_hyperbolic_calc<Type>& calc)
{
	switch (function_choice)
	{
	case 1:
	{
		std::cout << "Sinh(" << angle << ") = " << calc.sinh_calc() << "\n\n";
		break;
	}
	case 2:
	{
		std::cout << "Cosh(" << angle << ") = " << calc.cosh_calc() << "\n\n";
		break;
	}
	case 3:
	{
		std::cout << "Tanh(" << angle << ") = " << calc.tanh_calc() << "\n\n";
		break;
	}
	case 4:
	{
		std::cout << "Arcsinh(" << angle << ") = " << calc.arcsinh_calc() << "\n\n";
		break;
	}
	case 5:
	{
		std::cout << "Arccosh(" << angle << ") = " << calc.arccosh_calc() << "\n\n";
		break;
	}
	case 6:
	{
		std::cout << "Arctanh(" << angle << ") = " << calc.arctanh_calc() << "\n\n";
		break;
	}
	default: std::cout << "Input invalidation!\n\n";
	}
}

// ************

void trigonometry_calculation()
{
	// Radians or degrees
	const int measure_choice = input_type();

	long double angle_value = input_angle();

	// Trigonometry or hyperbolic functions
	const int function_choice = trig_hyper_type();

	// If we have degrees, convert them to radians for simplicity
	if (measure_choice == 1)
	{
		long double degrees = 0.0;
		degrees = angle_value;
		angle_value = angle_value * M_PIl / 180;
	}

	angle_value = std::fmod(angle_value, 2 * M_PIl);

	if (angle_value < 0)
	{
		angle_value += 2 * M_PIl;
	}

	// Trigonometry types of functions
	if (function_choice == 1)
	{
		trigonometry_calc<long double> calc;

		calc.set_rad(angle_value);

		// Choosing trigonometry function (sine, cosine, etc.)
		const int trigonometric_choice = trig_function_type();

		std::cout << "--------\nOutput result: ";
		trig_output(trigonometric_choice, angle_value, calc);
	}
	// Hyperbolic types of functions
	else  
	{
		// Creating hyperbolic calculator object which isn't the same as trigonometry one
		trigonometry_hyperbolic_calc<long double> trig_hyper_calc;

		// Setting the angle value using the already converted value from 
		trig_hyper_calc.set_rad(angle_value);

		const int hyperbolic_choice = hyperbolic_function_type();

		std::cout << "--------\n" << "Output result: ";
		hyperbolic_output(hyperbolic_choice, angle_value, trig_hyper_calc);
	}
}

void exponential_calculation()
{
}

void logarithmic_calculation()
{
}
