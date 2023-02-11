#pragma once

#include "CalculationTypes.h"

// Parent 'Calculator' class declaration
// -------------------------
template <typename TYPE>
class Calculator
{
protected:
	TYPE m_lValue = 0;
	TYPE m_rValue = 0;
public:
	Calculator() {}

	void setLValue(TYPE lValue);
	void setRValue(TYPE rValue);
};
// -----------------------------


// Parent 'Calculator' class functions definitions
// ---------------------
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
// -------------------------------------------


// Child 'ArithmeticCalc' class declaration
// ---------------------
template <typename TYPE>
class ArithmeticCalc : public Calculator<TYPE>
{
public:
	ArithmeticCalc() {}

	TYPE addition();

	TYPE substraction();

	TYPE multiplication();

	TYPE division();
};
// ----------------------


// Child 'ArithmeticCalc' class functions definitions
// ---------------------
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
// ----------------------------------


// Child 'TrigonometryCalc' class declaration
template <typename TYPE>
class TrigonometryCalc : public Calculator<TYPE>
{
private:
	TYPE m_radValue;
public:
	TrigonometryCalc() {}

	void setNonRad(TYPE radValue);

	TYPE sinCalc();
};
// ----------------


// Child 'TrigonometryCalc' class functions definition
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
// -----------------------------------

