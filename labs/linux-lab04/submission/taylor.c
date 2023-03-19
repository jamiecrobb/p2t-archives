#include <stdio.h>
#include <math.h>

struct taylor {
    double offset; //the value the series is expanded around
    double max, min; //the max and min x this series works for
    double coeffs[12]; //the coefficients for x^n in order
};

typedef struct taylor taylor_t;

//evaluate the given series @ x, returns NaN if invalid range
double eval_taylor(double x, taylor_t series) {
    if (x < series.min || x > series.max) return NAN; 
    //"not a number" as error if outside range
    x -= series.offset; //rescale our copy of x to the local value for the expansion
    return series.coeffs[0] + x*(series.coeffs[1] + x*(series.coeffs[2] + x*(series.coeffs[3] +x*(series.coeffs[4] + x*(series.coeffs[5] + x*(series.coeffs[6] + x*(series.coeffs[7] + x*(series.coeffs[8] + x*(series.coeffs[9] + x*(series.coeffs[10] + x*series.coeffs[11] ) ) ) ) ) ) ) ) ) );
} 

// Calculate the derivative and integral of a given taylor series
taylor_t taylor_derivative(taylor_t series, taylor_t *integral) {
    
    // Populate integral struct
    integral->offset = series.offset;
    integral->max = series.max;
    integral->min = series.min;

    integral->coeffs[0] = 0;
    for (int i = 1; i <= 12; i++) {
        integral->coeffs[i] = series.coeffs[i-1] / i;
    }

    // create and populate derivative struct
    taylor_t deriv = {};
    deriv.offset = series.offset;
    deriv.max = series.max;
    deriv.min = series.min;
    for (int i = 0; i < 11; i++) {
        deriv.coeffs[i] = (i+1) * series.coeffs[i+1];
    }
    return deriv;
}

int main(){
    // Create the initial taylor struct
    taylor_t taylor = { .offset = 1.0, .min=0.0, .max = 2.0,};
    taylor.coeffs[0] = 0;
    for (int n = 1; n <= 12; n++){
        if (n % 2 == 0) {
            taylor.coeffs[n] = -1.0 / n;
        }
        else {
            taylor.coeffs[n] = 1.0 / n;
        }
    }
    taylor_t integral;

    // get user input
    puts("Enter a y (0 < y < 2):");
    float y;
    scanf("%f", &y);
    
    // calculate and print results
    double result = eval_taylor(y, taylor);
    taylor_t derivative = taylor_derivative(taylor, &integral);
    double deriv_result = eval_taylor(y, derivative);
    double int_result = eval_taylor(y, integral);
    printf("Taylor evaluation: %f\n", result);
    printf("Derivative evaluation: %f\n", deriv_result);
    printf("Integral evaluation: %f\n", int_result);
}