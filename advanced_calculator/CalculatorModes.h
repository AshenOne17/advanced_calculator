#ifndef CALCULATOR_MODES_H
#define CALCULATOR_MODES_H

#pragma once

#include <cmath>

// Parent 'Calculator' class declaration
// -------------------------
template <typename Type>
class calculator
{
protected:
	Type m_l_value_ = 0;
	Type m_r_value_ = 0;
public:
	calculator() = default;

	void set_l_value(Type l_value);
	void set_r_value(Type r_value);
};
// -----------------------------


// Parent 'Calculator' class functions definitions
// ---------------------
template <typename Type>
void calculator<Type>::set_l_value(Type l_value)
{
	m_l_value_ = l_value;
}

template <typename Type>
void  calculator<Type>::set_r_value(Type r_value)
{
	m_r_value_ = r_value;
}
// -------------------------------------------


// Child 'ArithmeticCalc' class declaration
// ---------------------
template <typename Type>
class arithmetic_calc : public calculator<Type>
{
public:
	arithmetic_calc() = default;

	Type addition();

	Type substraction();

	Type multiplication();

	Type division();
};
// ----------------------


// Child 'ArithmeticCalc' class functions definitions
// ---------------------
template <typename Type>
Type arithmetic_calc<Type>::addition()
{
	return this->m_lValue + this->m_rValue;
}

template <typename Type>
Type arithmetic_calc<Type>::substraction()
{
	return this->m_lValue - this->m_rValue;
}

template <typename Type>
Type arithmetic_calc<Type>::multiplication()
{
	return static_cast<Type>(this->m_lValue * this->m_rValue);
}

template <typename Type>
Type arithmetic_calc<Type>::division()
{
	return static_cast<Type>(this->m_lValue / this->m_rValue);
}
// ----------------------------------


// Child 'TrigonometryCalc' class declaration
template <typename Type>
class trigonometry_calc : public calculator<Type>
{
protected:
	Type m_rad_value_ = 0;
public:
	trigonometry_calc() = default;

	void set_rad(Type deg_value);
	Type get_rad();

	Type sin_calc();
	Type cos_calc();
	Type tan_calc();
	Type arcsin_calc();
	Type arccos_calc();
	Type arctan_calc();
};
// ----------------


// Child 'TrigonometryCalc' class functions definition
template <typename Type>
void trigonometry_calc<Type>::set_rad(Type deg_value)
{
	m_rad_value_ = deg_value;
}

template <typename Type>
Type trigonometry_calc<Type>::get_rad()
{
	return m_rad_value_;
}

template <typename Type>
Type trigonometry_calc<Type>::sin_calc()
{
	return TYPE(std::sin(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::cos_calc()
{
	return TYPE(std::cos(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::tan_calc()
{
	return TYPE(std::tan(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::arcsin_calc()
{
	return TYPE(std::asin(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::arccos_calc()
{
	return TYPE(std::acos(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::arctan_calc()
{
	return TYPE(std::atan(m_rad_value_));
}
// -----------------------------------


// Child 'TrigonometryHyperbolicCalc' class declaration
template <typename Type>
class trigonometry_hyperbolic_calc : public trigonometry_calc<Type>
{
public:
	using trigonometry_calc<Type>::m_rad_value_;

	trigonometry_hyperbolic_calc() = default;

	Type sinh_calc();
	Type cosh_calc();
	Type tanh_calc();
	Type arcsinh_calc();
	Type arccosh_calc();
	Type arctanh_calc();
};
// ----------------


// Child 'TrigonometryHyperbolicCalc' class functions definition
template<typename Type>
Type trigonometry_hyperbolic_calc<Type>::sinh_calc()
{
	return Type(std::sinh(m_rad_value_));
}

template<typename Type>
Type trigonometry_hyperbolic_calc<Type>::cosh_calc()
{
	return Type(std::cosh(m_rad_value_));
}

template<typename Type>
Type trigonometry_hyperbolic_calc<Type>::tanh_calc()
{
	return Type(std::tanh(m_rad_value_));
}

template<typename Type>
Type trigonometry_hyperbolic_calc<Type>::arcsinh_calc()
{
	return Type(std::asinh(m_rad_value_));
}

template<typename Type>
Type trigonometry_hyperbolic_calc<Type>::arccosh_calc()
{
	return Type(std::acosh(m_rad_value_));
}

template<typename Type>
Type trigonometry_hyperbolic_calc<Type>::arctanh_calc()
{
	return Type(std::atanh(m_rad_value_));
}
// --------------------------------

#endif //CALCULATOR_MODES_H
