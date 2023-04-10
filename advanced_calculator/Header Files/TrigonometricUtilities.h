#ifndef TRIGONOMETRIC_UTILITIES_H
#define TRIGONOMETRIC_UTILITIES_H

#pragma once

/*
 * Header file for functions declarations. Functions serve to encapsulate the main "CalculationTypes.cpp" file,
 * helping functioning the trigonometric calculations.
 */

// Radians/Degrees input unit choice
int input_unit_type();

// Trigonometric/Hyperbolic functions choice
int function_type();

// Trigonometric functions type choice
int trig_function_type();

// Hyperbolic functions type choice
int hyperbolic_function_type();

// Angle for calculating its trigonometry value (user input)
long double input_angle();

#endif // TRIGONOMETRIC_UTILITIES_H