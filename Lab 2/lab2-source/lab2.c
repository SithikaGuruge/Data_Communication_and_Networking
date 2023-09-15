// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()
#include <math.h>
// user-defined header files
#include "mypcm.h"

// test

// function prototypes
void run(asignal *inputsignal);

int main()
{
    asignal *inputsignal = (asignal *)malloc(sizeof(asignal));
    run(inputsignal);

    // call any other function here

    free(inputsignal);
    return 0;
}

void run(asignal *inputsignal)
{

    int interval, encorder_bits;
    int A, omega, sigma, duration;

    scanf("%d %d %d %d %d %d", &A, &omega, &sigma, &duration, &interval, &encorder_bits);

    inputsignal->A = A;
    inputsignal->omega = omega;
    inputsignal->sigma = sigma;
    inputsignal->duration = duration;

    float *samples = malloc(sizeof(float) * inputsignal->duration / interval);
    int *pcmpulses = malloc(sizeof(int) * inputsignal->duration / interval);
    int *dsignal = malloc(sizeof(int) * inputsignal->duration / interval * inputsignal->duration);

    sampler(samples, interval, *inputsignal);
    quantizer(samples, pcmpulses, pow(2, encorder_bits), inputsignal->A);
    encoder(pcmpulses, dsignal, encorder_bits);

    for (int j = 0; j < inputsignal->duration / interval * encorder_bits + encorder_bits; j++)
    {
        printf("%d", dsignal[j]);
    }
}
