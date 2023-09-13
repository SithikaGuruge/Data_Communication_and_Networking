// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <math.h>
//Add any necessary headers here

// user-defined header files
#include "mypcm.h" // do not modify this file
int temp=0;
// put your function prototypes for additional helper functions below:


// implementation
float analog_signal_generator(asignal signal, int t)
{
    return signal.A*(sin(signal.omega*t + signal.sigma));


}
void sampler(float *samples, int interval, asignal signal)
{
    for(int i=0 ; i< signal.duration/interval + interval ; i += interval){
        samples[i] = analog_signal_generator(signal,i);
        temp+=1;
    }

}
void quantizer1(float *samples, int *pcmpulses, int levels)
{
	//TODO


}
void quantizer(float *samples, int *pcmpulses, int levels, float A)
{

    for (int j = 0; j < temp; j++) {
        pcmpulses[j] =(int)((samples[j]+A)/(2*A)*levels);
    }

}
void encoder(int *pcmpulses, int *dsignal, int encoderbits)
{
    for (int i = 0; i <= temp; i++) {
        int number = pcmpulses[i];
        int* encorded = (int*)malloc(encoderbits * sizeof(int));

        for(int j = 0; j < encoderbits; j++){
            encorded[j] = number % 2;
            number = number / 2;
        }

        for(int j = encoderbits - 1; j >= 0; j--){
            *dsignal = encorded[j];
            dsignal++;
        }

        free(encorded);
    }
}