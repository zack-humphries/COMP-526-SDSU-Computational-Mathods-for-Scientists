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

    int* b (double);
    int* (*(*a)[10]) (double);

    // b is a function that takes in a double parameter [int* b (double); is a pointer to the function] so (*(*a)[10]) is a function

    // If *(*a)[10] is a function, then (*a)[10] is an array of size 10 (a pointer to the first element of the array). 
    // *(*a)[10] is the value of the first element in the array, a function.

    // If (*a) is an array of size 10 (more being a pointer to the first element), then a is the value of the first element in the array, which is a function that returns a value of int.

    int (*example)[10] = {40,2,3,4,5,6,7,8,9,10};

    printf("%i\n",example);


    return 0;
}