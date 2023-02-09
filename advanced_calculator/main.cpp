#include <iostream>
#include <string>

using std::cout; using std::cin;

template <typename TYPE>
class Calculator {
private:
	TYPE lValue;
	TYPE rValue;
public:
	double addition(TYPE m_lValue = 0; TYPE m_rValue = 0) 
	: lValue(m_lValue), rValue(m_rValue) {
		return lValue + rValue;
	}

	double substraction(TYPE m_lValue = 0; TYPE m_rValue = 0)
		: lValue(m_lValue), rValue(m_rValue) {
		return lValue - rValue;
	}
};

int main(void) 
{
	std::cout << "Welcome to the advanced (scientific) calculator.\n" 
	<< "Types of operations: \n" 
	<< "[1] Arithmetic (+, -, *, %)\n" 
	<< "[2] Trigonometrical (sin, cos, tg, etc.)\n" 
	<< "[3] Exponential (power(), root, etc.)\n"
	<< "[4] Logarithmic (log(), ln(), etc.)\n";

	char continue_decision = 'Y';
	int choice = 0;

	while (continue_decision == 'Y') {
		std::cout << "Your choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1: {

		}
		case 2: {

		}
		case 3: {

		}
		case 4: {

		}
		default: {

		}
		}
	}
}