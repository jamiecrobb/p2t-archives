#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("P2 400 400 3\n"); // Header line
    double w = 1.0; 

    for (int iz0 = -200; iz0 < 200; iz0+=1) // Looping over imaginary values
    {
        for (int rz0 = -200; rz0 < 200; rz0+=1) // Looping over real values
        {         
            // Create start point  
            complex double zn = (rz0 / 100.0) + (iz0 / 100.0)*I;
            complex double zn1;
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

            // Print 0, 1, 2 or based on the value of zn1 or count
            if (count >= 20)
            {
                printf("0 ");
            }
            else if (creal(zn1) > 0.5)
            {
                printf("1 ");
            }
            else if (cimag(zn1) > 0)
            {
                printf("2 ");
            }
            else if (cimag(zn1) < 0)
            {
                printf("3 ");
            }
        }
        printf("\n");
    }
}