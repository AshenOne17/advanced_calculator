#ifndef LOGARITHMIC_UTILITIES_H
#define LOGARITHMIC_UTILITIES_H

#pragma once

/*
 * Header file for functions declarations. Functions serve to encapsulate the main "CalculationTypes.cpp" file,
 * helping functioning the logarithmic calculations and exponential calculations of logarithmic calculator sub-mode.
 */

// Logarithmic function/Exponential function choice
int log_calculation_type_input();

// Logarithm base user input
long int log_base_input();

// Logarithm number user input
long double log_number_input();

// Exponential function base user input
long double exp_base_input(long double exponent);

// Exponential function exponent user input
long double exp_exponent_input();

#endif // LOGARITHMIC_UTILITIES_H