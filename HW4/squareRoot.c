

/*
    Zack Humphries
    COMP 526 - Fall 2022
    Dr. Miguel Dumett
    Assignment 4
*/

// Note: Call the function sqrt_approx_diff(double b)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int count = 0;

double sqrt_recursive(double b, double x){

    int n = 100;


    if (count<n){
        count++;
        return sqrt_recursive(b, 0.5*(x + (b/x)));
    } else {
        return x;
    }

}

double sqrt_approx_diff(double b){ // CALL THIS FUNCTION
    double x = 1.0;

    return abs(sqrt(b)-sqrt_recursive(b, x));

}

