#include <stdio.h>
#include <stdint.h>

// Define color_value struct here so it is accessible in
// printppm.c and fractal.c without code repetition
struct color_value
{
    uint8_t r, g, b;
};

// Function prototypes
int printPPM(uint8_t results[400][400], struct color_value colors[4]);