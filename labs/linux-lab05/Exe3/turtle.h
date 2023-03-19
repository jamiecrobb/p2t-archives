#ifndef TURTLE_H
#define TURTLE_H

/*
    turtle.h

    Simple array-based turtle graphics engine in C. Exports to BMP files.

    (header info only; see turtle.c for implementation)

    Author: Mike Lam, James Madison University, August 2015
    Modified: Sam Skipsey, University of Glasgow, Sept 2016

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/*
    Initialize the 2d field that the turtle moves on. This must be called
    before any of the other functions in this library.
*/
void turtle_init(int width, int height);


/*
    Reset the turtle's location, orientation, color, and pen status to the
    default values: center of the field (0,0), facing right (0 degrees), black,
    and down, respectively).
*/
void turtle_reset(void);



/*
    Move the turtle forward, drawing a straight line if the pen is down.
*/
void turtle_forward(int pixels);


/*
    Move the turtle backward, drawing a straight line if the pen is down.
*/
void turtle_backward(int pixels);


/*
    Turn the turtle to the left by the specified number of degrees.
*/
void turtle_turn_left(double angle);


/*
    Turn the turtle to the right by the specified number of degrees.
*/
void turtle_turn_right(double angle);


/*
    Set the pen status to "up" (do not draw).
*/
void turtle_pen_up(void);


/*
    Set the pen status to "down" (draw).
*/
void turtle_pen_down(void);

/* 
    Get the pen status (0 is "up", anything else is down)
*/
int turtle_pen_status(void);



/*
    Rotate the turtle to the given heading (in degrees). 0 degrees means
    facing to the right; 90 degrees means facing straight up.
*/
void turtle_set_heading(double angle);


/*
    Set the current drawing color. Each component (red, green, and blue) may
    be any value between 0 and 255 (inclusive). Black is (0,0,0) and white is
    (255,255,255). Values outside this range are clamped to the limits.
*/
void turtle_set_pen_color(int red, int green, int blue);



/*
    Draw a 1-pixel dot at the current location, regardless of pen status.
*/
void turtle_dot(void);


/*
    Returns the current x-coordinate.
*/
double turtle_get_x(void);


/*
    Returns the current x-coordinate.
*/
double turtle_get_y(void);



/*
    Clean up any memory used by the turtle graphics system. Call this at the
    end of the program to ensure there are no memory leaks.
*/
void turtle_cleanup(void);

/*
	Save the current image as a png image, with name given by the string passed to the function.
*/

void turtle_save_png(const char *file_name);

#endif

