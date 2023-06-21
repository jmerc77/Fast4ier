//   polar.h - declaration of class
//
//   This code was written by me (jmerc77 on github.com).

//   Include complex numbers header
#ifndef polar_h
#define polar_h
//   Include complex numbers header
#include <complex.h>
//   Include math library
#include "math.h"

class Polar
{
	public:
	//   All polar coordinates stored in a complex number where the real is the amplitude and the imaginary is the phase of the FFT/IFFT data.
	//   Use fromPolar() to convert for input to IFFT. Use toPolar() to convert from FFT.
	
	//   TO POLAR
	//     Input  - input data
	//     Output - conversion result
	//     N      - length of both input data and result
	static bool toPolar(const complex *const Input, complex *const Output, const unsigned int N);

	//   TO POLAR, INPLACE VERSION
	//     Data - both input data and output
	//     N    - length of input data
	static bool toPolar(complex *const Data, const unsigned int N);

	//   FROM POLAR
	//     Input  - input data
	//     Output - conversion result
	//     N      - length of both input data and result
	static bool fromPolar(const complex *const Input, complex *const Output, const unsigned int N);

	//   FROM POLAR, INPLACE VERSION
	//     Data - both input data and output
	//     N    - length of input data
	static bool fromPolar(complex *const Data, const unsigned int N);
};
#endif