#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

struct color_value 
{
    uint8_t r,g,b;
};

int main()
{
    int results[400][400];

    struct color_value colors[4] = {{0,0,0}, {255,0,0}, {0,255,0}, {0,0,255}};

    printf("P3 400 400 255\n"); // Header line
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
                results[iz0+200][rz0+200] = 0;
            }
            else if (creal(zn1) > 0.5)
            {
                results[iz0+200][rz0+200] = 1;
            }
            else if (cimag(zn1) > 0)
            {
                results[iz0+200][rz0+200] = 2;
            }
            else if (cimag(zn1) < 0)
            {
                results[iz0+200][rz0+200] = 3;
            }
        }
    }

    // Iterate through results and print the rgb value of each element
    for (int iz0 = 0; iz0 < 400; iz0+=1)
    {
        for (int rz0 = 0; rz0 < 400; rz0+=1)
        {   
            uint8_t cur_val = results[iz0][rz0];      
            printf("%u %u %u", colors[cur_val].r, colors[cur_val].g, colors[cur_val].b);
        }
        printf("\n");
    }
}