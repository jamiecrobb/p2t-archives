#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#include "printppm.h"

// Print 0, 1, 2 or based on the value of zn1 or count
uint8_t nrs_domain(complex double zn1, int count)
{
    if (count >= 20)
    {
        return 0;
    }
    else if (creal(zn1) > 0.5)
    {
        return 1;
    }
    else if (cimag(zn1) > 0)
    {
        return 2;
    }
    else if (cimag(zn1) < 0)
    {
        return 3;
    }
    return 200;
}

int main()
{
    uint8_t results[400][400];

    struct color_value colors[] = {{0, 0, 0}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}};

    printf("P3 400 400 255\n"); // Header line
    double w = 1.0;

    for (int iz0 = -200; iz0 < 200; iz0 += 1) // Looping over imaginary values
    {
        for (int rz0 = -200; rz0 < 200; rz0 += 1) // Looping over real values
        {
            // Create start point
            complex double zn = (rz0 / 100.0) + (iz0 / 100.0) * I;
            complex double zn1;
            int count = 0;
            double diff;

            // Update zn1 whilst count is less than 20 and the difference is not tiny
            do
            {
                zn1 = (1.0 / 3) * (2 * zn + w / (zn * zn));
                diff = creal(zn1 - zn) * creal(zn1 - zn) + cimag(zn1 - zn) * cimag(zn1 - zn);
                zn = zn1;
                count++;
            } while (count < 20 && diff > 0.000001);

            results[iz0 + 200][rz0 + 200] = nrs_domain(zn1, count);
        }
        printf("\n");
    }
    printPPM(results, colors);
}