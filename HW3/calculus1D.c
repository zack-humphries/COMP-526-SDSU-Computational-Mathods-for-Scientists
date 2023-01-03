/*
    Zack Humphries
    COMP 526 - Fall 2022
    Dr. Miguel Dumett
    Assignment 3
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Initialize pi, pi/2, and epsilon = (1.0*10^(-16))
#ifndef M_PI
#define M_PI 3.141592653589793238462
#endif
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif
#ifndef epsilon
#define epsilon 0.0000000000000001
#endif

char *all_functions[] = {"Natural logarithm", "Tangent", "Arc sine", "Hyperbolic cosine", "Hyperbolic arc tangent"};

int problem_number;
double a;
double b;
int n;



//-------------------------------------------
// Initializing all functions related to ln(x)

double natural_log(double x){
    double natural_log = log(x);
    return natural_log;
}

double d_natural_log(double x){
    double natural_log = (1.0/x);
    return natural_log;
}

double dd_natural_log(double x){
    double natural_log = -1.0/(x*x);
    return natural_log;
}

double integral_natural_log(double x){
    double natural_log = x*log(x)-x;
    return natural_log;
}

//-------------------------------------------
// Initializing all functions related to tan(x)

double tangent(double x){
    double tangent = tan(x);
    return tangent;
}

double d_tangent(double x){
    double tangent = (1.0/(cos(x)*cos(x)));
    return tangent;
}


double dd_tangent(double x){
    double tangent = 2.0*tan(x)*(1.0/(cos(x)*cos(x)));
    return tangent;
}

double integral_tangent(double x){
    double tangent = -1.0*log(fabs(cos(x)));
    return tangent;
}

//-------------------------------------------
// Initializing all functions related to arcsin(x)

double arcsin(double x){
    double arcsin = asin(x);
    return arcsin;
}

double d_arcsin(double x){
    double arcsin = (1.0/(sqrt(1.0-(x*x))));
    return arcsin;
}


double dd_arcsin(double x){
    double arcsin = x/(sqrt(pow((1.0-(x*x)),3)));
    return arcsin;
}

double integral_arcsin(double x){
    double arcsin = sqrt(1.0-(x*x))+ x*asin(x);
    return arcsin;
}

//-------------------------------------------
// Initializing all functions related to cosh(x)

double hyperbolic_cos(double x){
    double hyperbolic_cos = cosh(x);
    return hyperbolic_cos;
}

double d_hyperbolic_cos(double x){
    double hyperbolic_cos = sinh(x);
    return hyperbolic_cos;
}

double dd_hyperbolic_cos(double x){
    double hyperbolic_cos = cosh(x);
    return hyperbolic_cos;
}

double integral_hyperbolic_cos(double x){
    double hyperbolic_cos = sinh(x);
    return hyperbolic_cos;
}

//-------------------------------------------
// Initializing all functions related to arctanh(x)

double hyperbolic_arctan(double x){
    double hyperbolic_arctan = atanh(x);
    return hyperbolic_arctan;
}

double d_hyperbolic_arctan(double x){
    double hyperbolic_arctan =(1.0/(1.0-(x*x)));
    return hyperbolic_arctan;
}


double dd_hyperbolic_arctan(double x){
    double hyperbolic_arctan = (2.0*x)/(pow((1.0-(x*x)),2));
    return hyperbolic_arctan;
}

double integral_hyperbolic_arctan(double x){
    double hyperbolic_arctan = 0.5 * log(1.0-(x*x)) + x*atanh(x);
    return hyperbolic_arctan;
}

//-------------------------------------------
// Initializing all functions related to the derivative appoximation vs actual comparison

double dh(double fx, double ddfx){
    return 2.0* sqrt(epsilon*fabs(fx/ddfx));
}

double dH(double dh, double interval){
    double half_interval = interval/2.0;
    if (dh <= half_interval){
        return dh;
    } else {
        return half_interval;
    }
}

double compute_approx_derivative(double xj, int problem_number, double a, double b, int n){
    double n1 = (double) n;
    double fxj;
    double ddfxj;

    if (problem_number == 1){
        fxj = natural_log(xj);
        ddfxj = dd_natural_log(xj);
    } else if (problem_number == 2){
        fxj = tangent(xj);
        ddfxj = dd_tangent(xj);
    } else if (problem_number == 3){
        fxj = arcsin(xj);
        ddfxj = dd_arcsin(xj);
    } else if (problem_number == 4){
        fxj = hyperbolic_cos(xj);
        ddfxj = dd_hyperbolic_cos(xj);
    } else if (problem_number == 5){
        fxj = hyperbolic_arctan(xj);
        ddfxj = dd_hyperbolic_arctan(xj);
    } 

    double dhxj = dh(fxj, ddfxj);
    double dHxj = dH(dhxj, ((b-a)/n1));

    double dfxj_approx;

    if (problem_number == 1){
        dfxj_approx = (natural_log(xj+dHxj)-natural_log(xj-dHxj))/(2*dHxj);
    } else if (problem_number == 2){
        dfxj_approx = (tangent(xj+dHxj)-tangent(xj-dHxj))/(2*dHxj);
    } else if (problem_number == 3){
        dfxj_approx = (arcsin(xj+dHxj)-arcsin(xj-dHxj))/(2*dHxj);
    } else if (problem_number == 4){
        dfxj_approx = (hyperbolic_cos(xj+dHxj)-hyperbolic_cos(xj-dHxj))/(2*dHxj);
    } else if (problem_number == 5){
        dfxj_approx = (hyperbolic_arctan(xj+dHxj)-hyperbolic_arctan(xj-dHxj))/(2*dHxj);
    } 

    return dfxj_approx;
}

double compute_actual_derivative(double xj, int problem_number){
    double dfxj;

    if (problem_number == 1){
        dfxj = d_natural_log(xj);
    } else if (problem_number == 2){
        dfxj = d_tangent(xj);
    } else if (problem_number == 3){
        dfxj = d_arcsin(xj);
    } else if (problem_number == 4){
        dfxj = d_hyperbolic_cos(xj);
    } else if (problem_number == 5){
        dfxj = d_hyperbolic_arctan(xj);
    } 

    return dfxj;
}

//---------------------------------------------------------------------------
// Initializing all functions related to the integral appoximation vs actual comparison

double compute_approx_interval(int problem_number, double a, double b, int n){
    double n1 = (double) n;
    double f_a, f_b, f_sum;

    int k;

    if (problem_number == 1){
        f_a = natural_log(a);
        f_b = natural_log(b);
        for (k = 1; k<n; k++){
            f_sum += natural_log(a+(k*(b-a)/n1));
        }
    } else if (problem_number == 2){
        f_a = tangent(a);
        f_b = tangent(b);
        for (k = 1; k<n; k++){
            f_sum += tangent(a+(k*(b-a)/n));
        }
    } else if (problem_number == 3){
        f_a = arcsin(a);
        f_b = arcsin(b);
        for (k = 1; k<n; k++){
            f_sum += arcsin(a+(k*(b-a)/n1));
        }
    } else if (problem_number == 4){
        f_a = hyperbolic_cos(a);
        f_b = hyperbolic_cos(b);
        for (k = 1; k<n; k++){
            f_sum += hyperbolic_cos(a+(k*(b-a)/n1));
        }
    } else if (problem_number == 5){
        f_a = hyperbolic_arctan(a);
        f_b = hyperbolic_arctan(b);
        for (k = 1; k<n; k++){
            f_sum += hyperbolic_arctan(a+(k*(b-a)/n1));
        }
    } else {
        return 0;
    }
    return (((b-a)/n1)*((f_a/2)+f_sum+(f_b/2)));
}

double compute_actual_integral(int problem_number, double a, double b){
    double integral_a, integral_b;
    
    if (problem_number == 1){
        integral_a = integral_natural_log(a);
        integral_b = integral_natural_log(b);
    } else if (problem_number == 2){
        integral_a = integral_tangent(a);
        integral_b = integral_tangent(b);
    } else if (problem_number == 3){
        integral_a = integral_arcsin(a);
        integral_b = integral_arcsin(b);
    } else if (problem_number == 4){
        integral_a = integral_hyperbolic_cos(a);
        integral_b = integral_hyperbolic_cos(b);
    } else if (problem_number == 5){
        integral_a = integral_hyperbolic_arctan(a);
        integral_b = integral_hyperbolic_arctan(b);
    } else {
        return 0;
    }
    return (integral_b-integral_a);
}

//-------------------------------------------
// Initializing all functions related to checking the imputs of the user

int check_number(int i){
    if (i>5 || i<=0){
        return 0;
    } else {
        return 1;
    }
}

int check_interval(int problem_number, double a, double b){
    if(b < a){
        return 0;
    }
    if (problem_number == 1 && a > 0){
        return 1;
    } else if (problem_number == 2  && ((((int)((((b+M_PI_2)/M_PI))-epsilon)) == ((int)(((a+M_PI_2)/M_PI)-epsilon))) && (((int)((((b+M_PI_2)/M_PI))+epsilon)) == ((int)(((a+M_PI_2)/M_PI)+epsilon)) ))){
        return 1; // this is my way of checking that the person didn't put any verticle asymptotes for a nor b. 
        // Since there is a verticle asymptote at every (pi*n)-(pi/2), I can make sure that there is less than a pi difference between a & b.
        // Also, I can make sure that there is no verticle asymptote inbetween a & b by adding by p/2 and dividing by pi and making sure that there is no additional pi in between them.
    } else if (problem_number == 3 && a > -1 && b < 1){
        return 1;
    } else if (problem_number == 4){
        return 1;
    } else if (problem_number == 5 && a > -1 && b < 1){
        return 1;
    } else {
        return 0;
    }
}

int check_n(int n){
    if (n <= 100 && n > 0){
        return 1;
    } else {
        return 0;
    }
}

//-------------------------------------------------------------------------------------------------------------


int main(void){
    printf("Choose a function:\n 1. Natural logarithm\n 2. Tangent\n 3. Arc sine\n 4. Hyperbolic cosine\n 5. Hyperbolic arc tangent\n");
    printf("Enter Problem Number: ");
    scanf("%d", &problem_number);
    printf("You've chosen: %s\n", all_functions[problem_number-1]);
    if((check_number(problem_number)) == 0){
        printf("Must pick a number from 1 to 5\n");
        return 0;
    }

    printf("\nEnter the bounds 'a' and 'b' where b > a:\n");
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);

    if((check_interval(problem_number, a, b)) == 0){
        printf("\nBad Bounds. Try again.\n");
        return 0;
    } else {
        printf("You have chosen:\n a = %f\n b = %f\n", a, b);
    }
    printf("\nEnter a n value (n <= 100) that will subdivide the bounds:\n");
    printf("Enter n: ");
    scanf("%d", &n);

    if((check_n(n)) == 0){
        printf("\nToo large or less than 1. Try again.\n");
        return 0;
    } else {
        printf("You have chosen:\n n = %d\n", n);
    }

    double j_d;
    double xj_array[n-1];
    for (j_d=1.0; j_d < n; j_d++){       // Initializes all xj values starting at j=1 and ending at j=n-1
        xj_array[((int)j_d)-1] = (a + (j_d*((b-a)/((double)(n)))));
    }

    int j;
    double dfxj_approx_array[n-1];
    for (j=0; j < n-1; j++){        // Calculates the appoximate derivate
        dfxj_approx_array[j] = compute_approx_derivative(xj_array[j], problem_number, a, b, n);
    }

    double dfxj_actual_array[n-1];
    for (j=0; j < n-1; j++){        // Calculates the actual derivative
        dfxj_actual_array[j] = compute_actual_derivative(xj_array[j], problem_number);
    }

    double dfxj_error_array[n-1];
    for (j=0; j < n-1; j++){        // Calculates the error of the approximate vs actual 
        dfxj_error_array[j] = fabs(dfxj_approx_array[j]-dfxj_actual_array[j]);
    }

    for (j=0; j < n-1; j++){ 
        printf("\n j = %3.i  ||  xj = %3.3f  ||  Estimated Derivative: %3.5f  ||  Actual Derivative: %3.5f  ||  Error: %3.5f ", (j+1), xj_array[j], dfxj_approx_array[j], dfxj_actual_array[j], dfxj_error_array[j]);
    }


    double integral_approx = compute_approx_interval(problem_number, a, b, n);  // Calculates the approximated integral
    double integral_actual = compute_actual_integral(problem_number, a, b);     // Calculates the actual integral

    printf("\n\nIntegral Estimate %5.5f vs Actual: %5.5f", integral_approx, integral_actual);
    printf("\nIntegral Error: %5.5f", (integral_approx - integral_actual));

    return 0;
}
