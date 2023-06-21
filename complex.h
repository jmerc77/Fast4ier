//   complex.h - declaration of class
//   of complex number
//
//   The code is property of LIBROW
//   You can use it on your own
//   When utilizing credit LIBROW site

//http://www.librow.com/articles/article-10

//Reworked from original from LIBROW (info above) to Arduino Lib in c++

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include "Arduino.h"

//allow choice of precision
#ifndef FLT
#ifdef FAST4_DOUBLE
#define FLT	double
#else
#define FLT	float
#endif
#endif

class complex
{

public:
	//   Imaginary unity
	static const complex i;
	static const complex j;

	//   Constructors
	complex(): m_re(0.), m_im(0.) {}
	complex(FLT re, FLT im): m_re(re), m_im(im) {}
	complex(FLT val): m_re(val), m_im(0.) {}

	//   Assignment
	complex& operator= (const FLT val)
	{
		m_re = val;
		m_im = 0.;
		return *this;
	}

	//   Basic operations - taking parts
	FLT re() const { return m_re; }
	FLT im() const { return m_im; }

	//   Conjugate number
	complex conjugate() const
	{
		return complex(m_re, -m_im);
	}

	//   Norm   
	FLT norm() const
	{
		return m_re * m_re + m_im * m_im;
	}

	//   Arithmetic operations
	complex operator+ (const complex& other) const
	{
		return complex(m_re + other.m_re, m_im + other.m_im);
	}

	complex operator- (const complex& other) const
	{
		return complex(m_re - other.m_re, m_im - other.m_im);
	}

	complex operator* (const complex& other) const
	{
		return complex(m_re * other.m_re - m_im * other.m_im,
			m_re * other.m_im + m_im * other.m_re);
	}

	complex operator/ (const complex& other) const
	{
		const FLT denominator = other.m_re * other.m_re + other.m_im * other.m_im;
		return complex((m_re * other.m_re + m_im * other.m_im) / denominator,
			(m_im * other.m_re - m_re * other.m_im) / denominator);
	}

	complex& operator+= (const complex& other)
	{
		m_re += other.m_re;
		m_im += other.m_im;
		return *this;
	}

	complex& operator-= (const complex& other)
	{
		m_re -= other.m_re;
		m_im -= other.m_im;
		return *this;
	}

	complex& operator*= (const complex& other)
	{
		const FLT temp = m_re;
		m_re = m_re * other.m_re - m_im * other.m_im;
		m_im = m_im * other.m_re + temp * other.m_im;
		return *this;
	}

	complex& operator/= (const complex& other)
	{
		const FLT denominator = other.m_re * other.m_re + other.m_im * other.m_im;
		const FLT temp = m_re;
		m_re = (m_re * other.m_re + m_im * other.m_im) / denominator;
		m_im = (m_im * other.m_re - temp * other.m_im) / denominator;
		return *this;
	}

	complex& operator++ ()
	{
		++m_re;
		return *this;
	}

	complex operator++ (int)
	{
		complex temp(*this);
		++m_re;
		return temp;
	}

	complex& operator-- ()
	{
		--m_re;
		return *this;
	}

	complex operator-- (int)
	{
		complex temp(*this);
		--m_re;
		return temp;
	}

	complex operator+ (const FLT val) const
	{
		return complex(m_re + val, m_im);
	}

	complex operator- (const FLT val) const
	{
		return complex(m_re - val, m_im);
	}

	complex operator* (const FLT val) const
	{
		return complex(m_re * val, m_im * val);
	}

	complex operator/ (const FLT val) const
	{
		return complex(m_re / val, m_im / val);
	}

	complex& operator+= (const FLT val)
	{
		m_re += val;
		return *this;
	}

	complex& operator-= (const FLT val)
	{
		m_re -= val;
		return *this;
	}

	complex& operator*= (const FLT val)
	{
		m_re *= val;
		m_im *= val;
		return *this;
	}

	complex& operator/= (const FLT val)
	{
		m_re /= val;
		m_im /= val;
		return *this;
	}

	friend complex operator+ (const FLT left, const complex& right)
	{
		return complex(left + right.m_re, right.m_im);
	}

	friend complex operator- (const FLT left, const complex& right)
	{
		return complex(left - right.m_re, -right.m_im);
	}

	friend complex operator* (const FLT left, const complex& right)
	{
		return complex(left * right.m_re, left * right.m_im);
	}

	friend complex operator/ (const FLT left, const complex& right)
	{
		const FLT denominator = right.m_re * right.m_re + right.m_im * right.m_im;
		return complex(left * right.m_re / denominator,
			-left * right.m_im / denominator);
	}

	//   Boolean operators
	bool operator== (const complex &other) const
	{
		return m_re == other.m_re && m_im == other.m_im;
	}

	bool operator!= (const complex &other) const
	{
		return m_re != other.m_re || m_im != other.m_im;
	}

	bool operator== (const FLT val) const
	{
		return m_re == val && m_im == 0.;
	}

	bool operator!= (const FLT val) const
	{
		return m_re != val || m_im != 0.;
	}

	friend bool operator== (const FLT left, const complex& right)
	{
		return left == right.m_re && right.m_im == 0.;
	}

	friend bool operator!= (const FLT left, const complex& right)
	{
		return left != right.m_re || right.m_im != 0.;
	}
	
	private:
	//   Internal presentation - real and imaginary parts
	FLT m_re;
	FLT m_im;

};

#endif