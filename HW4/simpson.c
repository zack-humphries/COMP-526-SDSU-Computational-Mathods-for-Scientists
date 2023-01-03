

/*
    Zack Humphries
    COMP 526 - Fall 2022
    Dr. Miguel Dumett
    Assignment 4
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double simpson(double a, double b, double (*f)(double xi), int n){
    double h = (b-a)/(double)n;

    int x_length = n;
    double x_list[x_length+1];

    int i;
    for (i=0; i<=x_length; i++){
        x_list[i] = a + (h*(double)i);
    }


    int i_avg;
    double x_avg_list[x_length-1];

    for (i_avg=0; i_avg<x_length; i_avg++){
        x_avg_list[i_avg] = ((x_list[i_avg]+x_list[i_avg+1])/2.0);
    }

    double f_xi_list[x_length+1];
    double f_xi_avg_list[x_length];


    for (i=0; i<=x_length; i++){
        f_xi_list[i] = (*f)(x_list[i]);
    }

    for (i=0; i<=x_length-1; i++){
        f_xi_avg_list[i] = (*f)(x_avg_list[i]);
    }


    double sum;

    
    for (i=0; i<=x_length-1; i++){
        sum += (h/3)*(((f_xi_list[i])+(f_xi_list[i+1]))/2) + (2*h/3)*(f_xi_avg_list[i]);
    }

    return sum;

}
