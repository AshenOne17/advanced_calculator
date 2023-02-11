#include "CalculatorModes.h"
#include "CalculationTypes.h"

// Parent "Calculator" Class
template <typename TYPE>
void Calculator<TYPE>::setLValue(TYPE lValue)
{
	m_lValue = lValue;
}

template <typename TYPE>
void  Calculator<TYPE>::setRValue(TYPE rValue)
{
	m_rValue = rValue;
}
// ----------------------
// ----------------------
// ----------------------

// Child "Arithmetical Calculator" Class
template <typename TYPE>
TYPE ArithmeticCalc<TYPE>::addition()
{
	return this->m_lValue + this->m_rValue;
}

template <typename TYPE>
TYPE ArithmeticCalc<TYPE>::substraction()
{
	return this->m_lValue - this->m_rValue;
}

template <typename TYPE>
TYPE ArithmeticCalc<TYPE>::multiplication()
{
	return (TYPE)(this->m_lValue * this->m_rValue);
}

template <typename TYPE>
TYPE ArithmeticCalc<TYPE>::division()
{
	return (TYPE)(this->m_lValue / this->m_rValue);
}
// ----------------------
// ----------------------
// ----------------------

// Child "Trigonometry Calculator" Class
template <typename TYPE>
void TrigonometryCalc<TYPE>::setNonRad(TYPE radValue)
{
	m_radValue = radValue;
}

template <typename TYPE>
TYPE TrigonometryCalc<TYPE>::sinCalc()
{
	return sin(m_radValue);
}