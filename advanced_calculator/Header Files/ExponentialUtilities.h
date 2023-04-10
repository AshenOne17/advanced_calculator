#ifndef EXPONENTIAL_UTILITIES_H
#define EXPONENTIAL_UTILITIES_H

#pragma once

/*
 * Header file for functions declarations. Functions serve to encapsulate the main "CalculationTypes.cpp" file,
 * helping functioning the exponential calculations.
 */

// Power raising/Root calculation choice
int operation_input();

// Exponent (power) user input
long int exponent_input(long double base);

// Base, raised to the power user input
long double base_input();

// Power of the root (square, cubic, etc.) user input
long int root_power_input();

// Number under the root user input
long double radicand_input(long int root_power);

#endif // EXPONENTIAL_UTILITIES_H