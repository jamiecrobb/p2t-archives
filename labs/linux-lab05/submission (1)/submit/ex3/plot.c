#include <stdio.h>
#include <stdlib.h>

#include "turtle.h"

int main(int argc, char *argv[])
{
    // Show error message and return 1 if incorrect arguments given
    if (argc < 2)
    {
        printf("Incorrect arguments.");
        return 1;
    }
    // Convert first CLI from ASCII to int and read into sides
    int sides = atoi(argv[1]);

    // Initialise turtle screen to 256*256 pixels, then put the pen down
    int width = 256;
    int height = 256;
    turtle_init(width, height);
    turtle_pen_down();

    // For each side, move forward 30 pixels and rotate the correct angle
    for (int i = 0; i < sides; i++)
    {
        turtle_forward(30);
        turtle_turn_right(360.0 / sides);
    }

    turtle_save_png("turtle.png");
}