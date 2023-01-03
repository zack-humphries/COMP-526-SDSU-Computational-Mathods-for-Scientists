/*
    Zack Humphries
    COMP 526 - Fall 2022
    Dr. Miguel Dumett
    Assignment 2
*/

#include <stdio.h>
#include <math.h>

// declaration of functions beforehand just in case
double f(double x);
double integral_dp(double t, double x);
double h(double t, double x);
double triangle_area(double t, double x);
double triangle_integral(double t, double x);
double u(double t,double x);

// All functions assume c = 2

double f(double x)
{
    double f_ans = 1.0/(1.0+pow(x,2));          // f(x) declaration
    return f_ans;
}

double h(double t, double x)
{
    double h_ans = pow(t,2) + pow(x,2);         // h(x) declaration
    return h_ans;
}

double integral_dp(double t, double x)
{
    double dp_ans = (-1* cos(t)*sin(t)*sin(x)); // simplified solution of (1/4) * integral[x+2t,x-2t](-sin(p)dp)
    return dp_ans;
}


double triangle_area(double t, double x)
{
    double a = sqrt(5.0) * t;        // length of v1:(x,t) to v2:(x-2t,0)
    double b = sqrt(5.0) * t;        // length of v1:(x,t) to v3:(x+2t,0)
    double c = 4.0 * t;              // length of v2:(x-2t,0) to v3:(x+2t,0)
    
    // using solution to area of triangle with any given lengths provided in class
    double s = (a+b+c)/2.0;  
    double area = sqrt(s*(s-a)*(s-b)*(s-c));

    return area;
}

double triangle_integral(double t, double x)
{
    // (A/3)* [h( (1/2)*(v1+v2) ) + h( (1/2)*(v1+v3) ) + h( (1/2)*(v2+v3) )]
    // v1:(x,t)  ;  v2:(x-2t,0)  ;  v3:(x+2t,0)
    // with (1/2)*(v1+v2) = (x-t,t/2)  ;  (1/2)*(v1+v3) = (x+t,t/2)  ;  (1/2)*(v2+v3) = (x,0)
    double integral = (1.0/3.0) * triangle_area(t,x) * (h(x-t, t/2) + h(x+t,t/2) + h(x,0));
    return integral;
}

double u(double t, double x)
{
    double f1 = f((x - 2.0*t));                     // f(x-2t)
    double f2 = f((x + 2.0*t));                     // f(x+2t)

    double first = (0.5)*(f1 + f2);                 // 1/2 * [f(x-2t) + f(x+2t)]
    double second = integral_dp(t,x);               // (1/4) * integral[x+2t,x-2t] of -sin(p)dp
    double third = (0.25)*triangle_integral(t,x);   // (1/4) * (A/3)* [h( (1/2)*(v1+v2) ) + h( (1/2)*(v1+v3) ) + h( (1/2)*(v2+v3) )]

    double answer = (first + second + third);       // Answer to u(t,x)
    return answer;
}


int main(void)
{
    double x = 0;   // Set x here
    double t = 1;   // Set t here

    printf("x: %f \n", x);
    printf("t: %f \n", t);

    if (t <= 0){
        printf("Error: t is less than or equal to zero");
    } else {
        double u_tx = u(t,x);
        printf("u(t,x) is %f \n", u_tx);
    } 
    return 0;
}