#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <math.h>

// Useage "./cuberoots <real> <imaginary>"

int main(int argc, char **argv)
{
    complex double w, zn, zn1;

    // Store command-line arguments into real and imag
    double real = atof(argv[1]);
    double imag = atof(argv[2]);

    // Assign w to zn as a start point
    w = real + imag*I;
    zn = w;

    int count = 0;
    double diff;

    // Update zn1 whilst count is less than 20 and the difference is not tiny
    do
    {
        zn1 = (1.0 / 3) * (2 * zn + w / ( zn * zn) );
        diff = creal(zn1-zn)*creal(zn1-zn) + cimag(zn1-zn)*cimag(zn1-zn);
        zn = zn1;
        count++;
    }
    while (count < 20 && diff > 0.000001);

    printf("Final value: %f + %fi\n", creal(zn1), cimag(zn1));
}