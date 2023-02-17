#pragma once

#include "CalculationTypes.h"
#include <cmath>

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
protected:
	TYPE m_radValue = 0;
public:
	TrigonometryCalc() {}

	void setRad(TYPE degValue);
	TYPE getRad();

	TYPE sinCalc();
	TYPE cosCalc();
	TYPE tanCalc();
	TYPE arcsinCalc();
	TYPE arccosCalc();
	TYPE arctanCalc();
};
// ----------------


// Child 'TrigonometryCalc' class functions definition
template <typename TYPE>
void TrigonometryCalc<TYPE>::setRad(TYPE degValue)
{
	m_radValue = degValue;
}

template <typename TYPE>
TYPE TrigonometryCalc<TYPE>::getRad() 
{
	return m_radValue;
}

template <typename TYPE>
TYPE TrigonometryCalc<TYPE>::sinCalc()
{
	return TYPE(std::sin(m_radValue));
}

template <typename TYPE>
TYPE TrigonometryCalc<TYPE>::cosCalc()
{
	return TYPE(std::cos(m_radValue));
}

template <typename TYPE>
TYPE TrigonometryCalc<TYPE>::tanCalc()
{
	return TYPE(std::tan(m_radValue));
}

template <typename TYPE>
TYPE TrigonometryCalc<TYPE>::arcsinCalc()
{
	return TYPE(std::asin(m_radValue));
}

template <typename TYPE>
TYPE TrigonometryCalc<TYPE>::arccosCalc()
{
	return TYPE(std::acos(m_radValue));
}

template <typename TYPE>
TYPE TrigonometryCalc<TYPE>::arctanCalc()
{
	return TYPE(std::atan(m_radValue));
}
// -----------------------------------


// Child 'TrigonometryHyperbolicCalc' class declaration
template <typename TYPE>
class TrigonometryHyperbolicCalc : public TrigonometryCalc<TYPE>
{
public:
	using TrigonometryCalc<TYPE>::m_radValue;

	TrigonometryHyperbolicCalc() {}

	TYPE sinhCalc();
	TYPE coshCalc();
	TYPE tanhCalc();
	TYPE arcsinhCalc();
	TYPE arccoshCalc();
	TYPE arctanhCalc();
};
// ----------------


// Child 'TrigonometryHyperbolicCalc' class functions definition
template<typename TYPE>
TYPE TrigonometryHyperbolicCalc<TYPE>::sinhCalc()
{
	return TYPE(std::sinh(m_radValue));
}

template<typename TYPE>
TYPE TrigonometryHyperbolicCalc<TYPE>::coshCalc()
{
	return TYPE(std::cosh(m_radValue));
}

template<typename TYPE>
TYPE TrigonometryHyperbolicCalc<TYPE>::tanhCalc()
{
	return TYPE(std::tanh(m_radValue));
}

template<typename TYPE>
TYPE TrigonometryHyperbolicCalc<TYPE>::arcsinhCalc()
{
	return TYPE(std::asinh(m_radValue));
}

template<typename TYPE>
TYPE TrigonometryHyperbolicCalc<TYPE>::arccoshCalc()
{
	return TYPE(std::acosh(m_radValue));
}

template<typename TYPE>
TYPE TrigonometryHyperbolicCalc<TYPE>::arctanhCalc()
{
	return TYPE(std::atanh(m_radValue));
}
// --------------------------------