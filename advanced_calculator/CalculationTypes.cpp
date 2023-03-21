#include "CalculatorModes.h"
#include "CalculationTypes.h"
#include "ArithmeticUtilities.h"
#include "TrigonometricUtilities.h"
#include "ExponentialUtilities.h"

#include <iostream>

# define M_PIl 3.141592653589793238462643383279502884L

// *** Explicitly declaring template functions due to file management restrictions ***

// Function used to wrap the value regarding the fact that computer calculations with float values
// are most of the time not entirely correct

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
Type apply_tolerance(Type result, Type tolerance)
{
	if (std::abs(result) < tolerance) 
	{
		return 0.0;
	}
	else 
	{
		return result;
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
void exponential_output(exponential_calc<Type>& calc)
{
	auto result = calc.power();

	std::cout << "Number " << calc.get_base() << " raised to power of " << calc.get_exponent() << " equals to " << calc.power() << "\n\n";
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
	constexpr long long second_value = 0;
	calc.set_r_value(second_value);

	// Outputting the result of calculation
	arithmetic_output(arithmetic_operation, calc);
}

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
		// Creating hyperbolic calculator object which isn't the same as trigonometry one
		trigonometry_hyperbolic_calc<long double> trig_hyper_calc;

		// Setting the angle value using the already converted value from 
		trig_hyper_calc.set_rad(angle_value);

		const int hyperbolic_choice = hyperbolic_function_type();

		std::cout << "--------\n" << "Output result: ";
		hyperbolic_output(hyperbolic_choice, angle_value, trig_hyper_calc, tolerance);
	}
}


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

void exponential_calculation()
{
	const int choice = operation_input();

	if (choice == 1)
	{
		exponential_calc<long double> calc;

		const long double base = base_input();
		calc.set_base(base);

		const double exponent = exponent_input(base);
		calc.set_exponent(exponent);

		exponential_output(calc);
	}
	else if (choice == 2)
	{
		// To Do.
	}
}

void logarithmic_calculation()
{
	// To Do.
}
