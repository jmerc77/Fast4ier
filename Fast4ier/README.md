# Fast4ier
An FFT and IFFT Arduino library.

## inclusion

```
#include <complex.h>
#include <fast4ier.h>
#include <polar.h> //Optional. Only if used.
```

## Usage
### Enabling Double precision instead of float

`#define FAST4_DOUBLE`

### Defining arrays

`complex mySamples[bins];`

### FFT

`Fast4::FFT(complex input[], complex output[], int bins);`

in-place:

`Fast4::FFT(complex data[], int bins);`

### IFFT

`Fast4::IFFT(complex input[], complex output[], int bins);`

in-place:

`Fast4::IFFT(complex data[], int bins);`
### Polar conversion
Polar coords stored as a complex number: (Amplidude) + (Phase)i

`Polar::toPolar(complex input[], complex output[], int bins);`

`Polar::fromPolar(complex input[], complex output[], int bins);`

in-place:

`Polar::toPolar(complex data[], int bins);`

`Polar::fromPolar(complex data[], int bins);`
