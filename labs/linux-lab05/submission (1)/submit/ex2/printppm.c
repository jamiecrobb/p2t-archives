#include "printppm.h"

int printPPM(uint8_t results[400][400], struct color_value colors[4])
{
    int count = 0;
    // Iterate through results and print the rgb value of each element
    for (int iz0 = 0; iz0 < 400; iz0 += 1)
    {
        for (int rz0 = 0; rz0 < 400; rz0 += 1)
        {
            uint8_t cur_val = results[iz0][rz0];
            printf("%u %u %u", colors[cur_val].r, colors[cur_val].g, colors[cur_val].b);
            count += 3;
        }
        printf("\n");
    }
    return count;
}