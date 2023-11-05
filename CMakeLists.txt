cmake_minimum_required(VERSION 3.26)
project(advanced_calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories("advanced_calculator/Header Files")

add_executable(advanced_calculator
        "advanced_calculator/Header Files/ArithmeticUtilities.h"
        "advanced_calculator/Header Files/CalculationTypes.h"
        "advanced_calculator/Header Files/CalculatorModes.h"
        "advanced_calculator/Header Files/ExponentialUtilities.h"
        "advanced_calculator/Header Files/LogarithmicUtilities.h"
        "advanced_calculator/Header Files/TrigonometricUtilities.h"
        "advanced_calculator/Source Files/ArithmeticUtilities.cpp"
        "advanced_calculator/Source Files/CalculationTypes.cpp"
        "advanced_calculator/Source Files/ExponentialUtilities.cpp"
        "advanced_calculator/Source Files/LogarithmicUtilities.cpp"
        "advanced_calculator/Source Files/main.cpp"
        "advanced_calculator/Source Files/TrigonometricUtilities.cpp")
