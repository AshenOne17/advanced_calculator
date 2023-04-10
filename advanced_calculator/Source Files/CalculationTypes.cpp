#include "CalculationTypes.h" // Calculation type modes' header

#include "CalculatorModes.h" // Encapsulated classes declarations' header

// Utility functions headers
#include "ArithmeticUtilities.h"
#include "TrigonometricUtilities.h"
#include "ExponentialUtilities.h"
#include "LogarithmicUtilities.h"

#include <iostream>

#define M_PIl 3.141592653589793238462643383279502884L

/*
 * Principal program file, containing all main calculator type modes. Deep encapsulation, achieved by files separation
 * and declarations/definitions principles, as well as classes encapsulation. See each header file for each mode's
 * utility functions and main program classes declarations header "CalculatorModes.h".
 */

// *** Explicitly declaring template functions due to file management restrictions ***

// Function used to wrap the value regarding the fact that computer calculations with float values
// are most of the time not entirely correct

template <typename Type>
Type apply_tolerance(Type result, Type tolerance)
{
	if (std::abs(result) < tolerance) 
	{
		return 0.0;
	}
	
	return result;
	
}

// Calculator type modes output

template <typename Type>
void arithmetic_output(const char operation, arithmetic_calc<Type>& calc)
{
	std::cout << "--------\nOutput result: ";

	switch (operation)
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

template <typename Type>
void trig_output(const int function_choice, const long double angle, trigonometry_calc<Type>& calc, Type tolerance)
{
	Type result;

	switch(function_choice)
	{
	case 1:
	{
		result = calc.sin_calc();
		std::cout << "Sin(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 2:
	{
		result = calc.cos_calc();
		std::cout << "Cos(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 3:
	{
		result = calc.tan_calc();
		std::cout << "Tan(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 4:
	{
		result = calc.arcsin_calc();
		std::cout << "Arcsin(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 5:
	{
		result = calc.arccos_calc();
		std::cout << "Arccos(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 6:
	{
		result = calc.arctan_calc();
		std::cout << "Arctan(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	default:
	{
		std::cout << "Input invalidation!\n\n";
		break;
	}
	}
}

template <typename Type>
void hyperbolic_output(const int function_choice, const long double angle, trigonometry_hyperbolic_calc<Type>& calc, Type tolerance)
{
	Type result;

	switch (function_choice)
	{
	case 1:
	{	
		result = calc.sinh_calc();
		std::cout << "Sinh(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 2:
	{
		result = calc.cosh_calc();
		std::cout << "Cosh(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 3:
	{
		result = calc.tanh_calc();
		std::cout << "Tanh(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 4:
	{
		result = calc.arcsinh_calc();
		std::cout << "Arcsinh(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 5:
	{
		result = calc.arccosh_calc();
		std::cout << "Arccosh(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	case 6:
	{
		result = calc.arctanh_calc();
		std::cout << "Arctanh(" << angle << ") = " << apply_tolerance(result, tolerance) << "\n\n";
		break;
	}
	default:
	{
		std::cout << "Input invalidation!\n\n";
		break;
	}
	}
}

template <typename Type>
void logarithmic_output(logarithmic_calc<Type>& calc, const int choice)
{
	if (choice == 1)
	{
		std::cout << "\nLogarithm of " << calc.get_log_number() << " to the base " << calc.get_log_base() << " is equal to " << calc.log_calculation() << ".\n\n";
	}
	else
	{
		std::cout << '\n' << calc.get_exp_base() << " to the power of " << calc.get_exp_exponent() << " is equal to " << calc.exp_calculation() << ".\n\n";
	}
}

template <typename Type>
void exponential_output(exponential_calc<Type>& calc, const int choice)
{
	if (choice == 1)
	{
		std::cout << "Number " << calc.get_base() << " raised to power of " << calc.get_exponent() << " equals to " << calc.power() << "\n\n";
	}
	else
	{
		std::cout << "Root of power " << calc.get_root_power() << " of the radicand " << calc.get_radicand() << " equals to " << calc.root_calculation() << "\n\n";
	}
}

// ************

void arithmetic_calculation() 
{
	arithmetic_calc<long long> calc;

	// Asking user to input and assign the first value
	const long long first_value = l_value_input();
	calc.set_l_value(first_value);

	// Asking user for operation type
	const char arithmetic_operation = op_input();

	// Asking user to input and assign the second value
	const long long second_value = r_value_input(arithmetic_operation);
	calc.set_r_value(second_value);

	// Outputting the result of calculation
	arithmetic_output(arithmetic_operation, calc);
}

void trigonometry_calculation()
{
	// Radians or degrees
	const int measure_choice = input_unit_type();

	long double angle_value = input_angle();

	// Trigonometry or hyperbolic functions
	const int function_choice = function_type();

	// If we have degrees, convert them to radians for simplicity
	if (measure_choice == 1)
	{
		long double degrees = 0.0;
		degrees = angle_value;
		angle_value = angle_value * M_PIl / 180;
	}

	// Applying periodicity
	angle_value = std::fmod(angle_value, 2 * M_PIl);

	if (angle_value < 0)
	{
		angle_value += 2 * M_PIl;
	}

	// Tolerance for float numbers inaccuracy
	constexpr long double tolerance = 1e-10;

	// Trigonometry types of functions
	if (function_choice == 1)
	{
		trigonometry_calc<long double> calc;

		calc.set_rad(angle_value);

		// Choosing trigonometry function (sine, cosine, etc.)
		const int trigonometric_choice = trig_function_type();

		std::cout << "--------\nOutput result: ";
		trig_output(trigonometric_choice, angle_value, calc, tolerance);
	}
	// Hyperbolic types of functions
	else  
	{
		// Creating hyperbolic calculator object which isn't the same as trigonometry one, see "HyperbolicCalc" class in
		// "CalculatorModes.h" for more info.
		trigonometry_hyperbolic_calc<long double> trig_hyper_calc;

		// Setting the angle value using the already converted value
		trig_hyper_calc.set_rad(angle_value);

		const int hyperbolic_choice = hyperbolic_function_type();

		std::cout << "--------\n" << "Output result: ";
		hyperbolic_output(hyperbolic_choice, angle_value, trig_hyper_calc, tolerance);
	}
}

void exponential_calculation()
{
	const int choice = operation_input();

	exponential_calc<long double> calc;

	// If we want to calculate power raising
	if (choice == 1)
	{
		const long double base = base_input();
		calc.set_base(base);

		const double exponent = exponent_input(base);
		calc.set_exponent(exponent);

		exponential_output(calc, choice);
	}
	// If we want to calculate square root (of different powers)
	else if (choice == 2)
	{
		// Newton - Raphson method (alt. called or also known as Newton method) is used to calculate the root;
		//
		// The Newton-Raphson method (also known as Newton's method) is a way to quickly find a good approximation
		// for the root of a real-valued function f(x) = 0. It uses the idea that a continuous and differentiable function
		// can be approximated by a straight line tangent to it.
		// Suppose you need to find the root of a continuous, differentiable function f(x), and you know the root
		// you are looking for is near the point x = x0. Then Newton's method tells us that a better approximation for the root is
		// x1 = x0 - ( f(x) / f'(x0) );
		// This process may be repeated as many times as necessary to get the desired accuracy. In general, for any x-value xn, the next value is given by:
		// xn+1 = xn - ( f(xn) / f'(xn) );

		const long int root_power = root_power_input();
		calc.set_root_power(root_power);

		const long double radicand = radicand_input(root_power);
		calc.set_radicand(radicand);

		exponential_output(calc, choice);
	}
}

void logarithmic_calculation()
{
	const int choice = log_calculation_type_input();

	logarithmic_calc<long double> calc;

	// If we want to calculate logarithmic function
	if (choice == 1)
	{
		const long int base = log_base_input();
		calc.set_log_base(base);

		const long double number = log_number_input();
		calc.set_log_number(number);

		logarithmic_output(calc, choice);
	}
	// If we want to calculate exponential function (similar to power raising, but not exactly)
	else
	{
		const long double exponent = exp_exponent_input();
		calc.set_exp_exponent(exponent);

		const long double base = exp_base_input(exponent);
		calc.set_exp_base(base);
		
		logarithmic_output(calc, choice);
	}
}