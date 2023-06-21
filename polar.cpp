//   polar.cpp - impelementation of class
//
//   This code was written by me (jmerc77 on github.com).

//   Include header file
#include "polar.h"

//   All polar coordinates stored in a complex number where the real is the amplitude and the imaginary is the phase of the FFT/IFFT data.
//   Use fromPolar() to convert for input to IFFT. Use toPolar() to convert from FFT.

//   TO POLAR
//     Input  - input data
//     Output - conversion result
//     N      - length of both input data and result
bool toPolar(const complex *const Input, complex *const Output, const unsigned int N)
{
	//   Check input parameters
	if (!Input || !Output || N < 1 || N & (N - 1))
		return false;
	//   Perform conversion
	for(unsigned int Position = 0; Position < N; ++Position)
	{
		Output[Position]=complex(sqrt(pow(Input[Position].re(), 2) + pow(Input[Position].im(), 2)), atan2(Input[Position].im(), Input[Position].re()));
	}
	//   Succeeded
	return true;
}

//   TO POLAR, INPLACE VERSION
//     Data - both input data and output
//     N    - length of input data
bool toPolar(complex *const Data, const unsigned int N)
{
	//   Check input parameters
	if (!Data || N < 1 || N & (N - 1))
		return false;
	//   Perform conversion
	for(unsigned int Position = 0; Position < N; ++Position)
	{
		Data[Position]=complex(sqrt(pow(Data[Position].re(), 2) + pow(Data[Position].im(), 2)), atan2(Data[Position].im(), Data[Position].re()));
	}
	//   Succeeded
	return true;
}

//   FROM POLAR
//     Input  - input data
//     Output - conversion result
//     N      - length of both input data and result
bool fromPolar(const complex *const Input, complex *const Output, const unsigned int N)
{
	//   Check input parameters
	if (!Input || !Output || N < 1 || N & (N - 1))
		return false;
	//   Perform conversion
	for(unsigned int Position = 0; Position < N; ++Position)
	{
		Output[Position]=complex(cos(Input[Position].im())*Input[Position].re(),sin(Input[Position].im())*Input[Position].re());
	}
	//   Succeeded
	return true;	
}

//   FROM POLAR, INPLACE VERSION
//     Data - both input data and output
//     N    - length of input data
bool fromPolar(complex *const Data, const unsigned int N)
{
	//   Check input parameters
	if (!Data || N < 1 || N & (N - 1))
		return false;
	//   Perform conversion
	for(unsigned int Position = 0; Position < N; ++Position)
	{
		Data[Position]=complex(cos(Data[Position].im())*Data[Position].re(),sin(Data[Position].im())*Data[Position].re());
	}
	//   Succeeded
	return true;	
}