#ifndef ARITHMETIC_UTILITIES_H
#define ARITHMETIC_UTILITIES_H

#pragma once

/*
 * Header file for functions declarations. Functions serve to encapsulate the main "CalculationTypes.cpp" file,
 * helping functioning the arithmetic calculations.
 */

// Input for first value
long long l_value_input();

// Input for operation
char op_input();

// Input for second value
long long r_value_input(char op);

#endif // ARITHMETIC_UTILITIES_H