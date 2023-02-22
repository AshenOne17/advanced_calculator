#include "CalculationTypes.h"
#include <iostream>
#include <cstdlib>

int main()
{
	constexpr char continue_decision = 'Y';
	int choice = 0;

	while (continue_decision == 'Y') 
	{
		std::cout << "Welcome to the advanced (scientific) calculator.\n"
			<< "Types of operations: \n"
			<< "[1] Arithmetic (+, -, *, /)\n"
			<< "[2] Trigonometry (sin, cos, tg, etc.)\n"
			<< "[3] Exponential (power(), root, etc.)\n"
			<< "[4] Logarithmic (log(), ln(), etc.)\n"
			<< "To close the calculator enter '0'.\n\n"
			<< "Your choice: ";

		std::cin >> choice;

		system("cls");

		switch (choice) 
		{
		case 1: 
		{
			arithmetic_calculation();
			break;
		}
		case 2: 
		{
			trigonometry_calculation();
			break;
		}
		case 3: 
		{
			exponential_calculation();
			break;
		}
		case 4: 
		{
			logarithmic_calculation();
			break;
		}
		case 0: 
		{
			exit(1);
		}
		default: 
		{

		}
		}
	}
}