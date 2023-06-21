# Fast4ier

An FFT and IFFT Arduino library. 

**Note: You may need a board with a lot of RAM sometimes. I currently recommend the teensy 4.x for its speed and large amount of RAM (it's very fast with a default of 600MHZ and a max built-in overclock of 1.024GHZ with cooling/heatsink).**

## inclusion

```
#include <complex.h>
#include <fast4ier.h>
```

## Usage

### Enabling Double precision instead of float

The default of float may help reduce RAM on some boards. However, **some do not differenciate between float and double precision (they are treated equal).**

`#define FAST4_DOUBLE`

### Defining arrays

`complex mySamples[bins];`

### FFT

`Fast4::FFT(complex input[], complex output[], int bins);`

in-place:

`Fast4::FFT(complex data[], int bins);`

### IFFT

IFFT is useful for creating [sfx](https://en.wikipedia.org/wiki/Sound_effect).

`Fast4::IFFT(complex input[], complex output[], int bins);`

in-place:

`Fast4::IFFT(complex data[], int bins);`
### Polar conversion

Can be used for spectrographs.

**Polar coords stored as a complex number: (Amplidude) + (Phase)i**

`Polar::toPolar(complex input[], complex output[], int bins);`

`Polar::fromPolar(complex input[], complex output[], int bins);`

in-place:

`Polar::toPolar(complex data[], int bins);`

`Polar::fromPolar(complex data[], int bins);`
