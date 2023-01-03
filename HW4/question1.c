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

    int a[] = {1,2,3,4,5,6,7};
    int i = 2;
    int n = 3;

    a[i++] *= n;
    printf("i:%i a[i]:%i \n", i, a[i]);

    //////////////////////////////////////////////////////////////////////////////////

    int b[] = {1,2,3,4,5,6,7};
    i = 2;
    n = 3;

    b[i++] = b[i++]*n;

    printf("i:%i b[i]:%i \n", i, b[i]);

    //The expressions are different because i++ is only called once in the case of a[i++] *= n so i is only added to once.
    //The case of a[i++] = a[i++]*n is different because i++ is called twice so i is added to twice, instead of once.

    return 0;
}