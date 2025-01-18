#include <Fast4ier.h>
#include <complex.h>
//if you have alot of RAM, uncoment the following for extra precision.
//#define DOUBLE
#define ADC_PIN A0
#define MAXADC  1024
#define SAMP_DELAY  5000
#define BINS  32  
#define READ_SAMP ((analogRead(ADC_PIN)-(MAXADC/2))/(MAXADC/2))


complex vals[BINS];
void setup() {
  // put your setup code here, to run once:
Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<BINS;i++)
{
  vals[i]=READ_SAMP;
  delayMicroseconds(SAMP_DELAY);
}
Fast4::FFT(vals,BINS);//IFFT has similar usage. this is the inplace version. for out of place use: Fast4::FFT(input data as complec[], output buffer as complex, the number of bins); //also can be IFFT.
Serial.println(F("##########################################"));
for(int i=0;i<BINS;i++)
{
  Serial.print(vals[i].re());
  Serial.print(F(" + "));
  Serial.print(vals[i].im());
  Serial.println(F("i"));
}
}
