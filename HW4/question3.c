/*
    Zack Humphries
    COMP 526 - Fall 2022
    Dr. Miguel Dumett
    Assignment 4
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void){

    double (*(*x())[10])(int);

    double (*y)(int);
    // y is a function that takes an input parameter that's an int and returns a double

    double (*(z)[10])(int);
    // Since y is a function and y=(z)[10], z is the address of the first element of an array of size 10, where the first element is a function.

    double (*(*x())[10])(int);
    // Since z=*x() and z is the address of the first element in the array, x() is the function that is located at the first position in the array
    // With x() being a function that returns type double, x is the pointer to the function


    return 0;
}