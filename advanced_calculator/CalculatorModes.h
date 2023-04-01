#ifndef CALCULATOR_MODES_H
#define CALCULATOR_MODES_H

#pragma once

#include <cmath>
#include <algorithm>

// Parent 'Calculator' class declaration
// ---------------------
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
// --------------------------------


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
// ----------------------------------------------


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
	return this->m_l_value_ + this->m_r_value_;
}

template <typename Type>
Type arithmetic_calc<Type>::substraction()
{
	return this->m_l_value_ - this->m_r_value_;
}

template <typename Type>
Type arithmetic_calc<Type>::multiplication()
{
	return static_cast<Type>(this->m_l_value_ * this->m_r_value_);
}

template <typename Type>
Type arithmetic_calc<Type>::division()
{
	return static_cast<Type>(this->m_l_value_ / this->m_r_value_);
}
// ---------------------------------------------------------------


// Child 'TrigonometryCalc' class declaration
// ---------------------
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
// --------------------


// Child 'TrigonometryCalc' class functions definition
// ---------------------
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
	return Type(std::sin(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::cos_calc()
{
	return Type(std::cos(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::tan_calc()
{
	return Type(std::tan(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::arcsin_calc()
{
	return Type(std::asin(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::arccos_calc()
{
	return Type(std::acos(m_rad_value_));
}

template <typename Type>
Type trigonometry_calc<Type>::arctan_calc()
{
	return Type(std::atan(m_rad_value_));
}
// ----------------------------------------


// Child 'TrigonometryHyperbolicCalc' class declaration
// ---------------------
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
// ---------------------


// Child 'TrigonometryHyperbolicCalc' class functions definition
// --------------------
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
// ----------------------------------------------------


// Child 'ExponentialCalc' class declaration
// --------------------
template<typename Type>
class exponential_calc: public calculator<Type>
{
protected:
	Type m_exponent_ = 0;
	Type m_base_ = 0;
	Type m_radicand_ = 0;
	Type m_root_exponent_ = 0;
public:
	exponential_calc() = default;

	void set_exponent(Type exponent);

	void set_base(Type base);

	void set_radicand(Type radicand);

	void set_root_power(Type root_exponent);

	Type get_exponent();

	Type get_base();

	Type get_radicand();

	Type get_root_power();

	Type power();

	Type root_calculation();
};
// --------------------------------------


// Child 'ExponentialCalc' class functions declarations
// ---------------------
template <typename Type>
void exponential_calc<Type>::set_exponent(Type exponent)
{
	m_exponent_ = exponent;
}

template <typename Type>
void exponential_calc<Type>::set_base(Type base)
{
	m_base_ = base;
}

template <typename Type>
void exponential_calc<Type>::set_radicand(Type radicand)
{
	m_radicand_ = radicand;
}

template <typename Type>
void exponential_calc<Type>::set_root_power(Type root_exponent)
{
	m_root_exponent_ = root_exponent;
}

template <typename Type>
Type exponential_calc<Type>::get_base()
{
	return m_base_;
}

template <typename Type>
Type exponential_calc<Type>::get_exponent()
{
	return m_exponent_;
}

template <typename Type>
Type exponential_calc<Type>::get_radicand()
{
	return m_radicand_;
}

template <typename Type>
Type exponential_calc<Type>::get_root_power()
{
	return m_root_exponent_;
}

template <typename Type>
Type exponential_calc<Type>::power()
{
	return Type(pow(m_base_, m_exponent_));
}

template <typename Type>
Type exponential_calc<Type>::root_calculation()
{
	// Set the lower and upper bounds of the interval
    long double x_low = 0;
    long double x_high = std::max<Type>(Type(1), m_radicand_);

    // Desired level of accuracy
	constexpr long double epsilon = 0.00001;

    // Iterate until the difference between upper and lower bounds is less than epsilon
    while (x_high - x_low > epsilon)
    {
        // Calculate the midpoint of the interval
        long double x_mid = (x_low + x_high) / 2;

        // Calculate the value of the function at the midpoint
        const long double fx = pow(x_mid, m_root_exponent_) - m_radicand_;

        // Update the interval based on the value of the function at the midpoint
        if (fx > 0)
        {
            x_high = x_mid;
        }
        else
        {
            x_low = x_mid;
        }
    }

    // Return the lower bound of the interval as the calculated root
    return Type(x_low);
}

// ---------------------------------------------------------


#endif //CALCULATOR_MODES_H