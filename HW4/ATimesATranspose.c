/*
    Zack Humphries
    COMP 526 - Fall 2022
    Dr. Miguel Dumett
    Assignment 4
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void aaT(double *a, double *result, int rows, int cols) {

    int i, j, k, l;
    int row,col;
    double sum, first_term, second_term;
    int left_over;
    int col_and_row = rows*cols;


    for (j=0; j<rows; j++){
        for (k=0; k<rows; k++){
            sum = 0;
            for (l=0; l<cols;l++){
                first_term = *(a+(j*cols)+l);
                second_term = *(a+(k*cols)+l);

                sum += first_term * second_term;
            }
            *(result + j+(k*rows))= sum;
        }
        
    }
    return;
}

int main(void){
    double a[2][3] = {1, 2, 0, 4, -3, -2};

    int rows = sizeof(a)/sizeof(a[0]);
    int cols = sizeof(a[0])/sizeof(a[0][0]);

    double result[rows][rows];

    aaT(&a[0][0], &result[0][0], rows, cols);

    
    int rows1 = sizeof(result)/sizeof(result[0]);
    int cols1 = sizeof(result[0])/sizeof(result[0][0]);


    int row, col;
    for (row = 0; row < rows1; row++) {
        for (col = 0; col < cols1; col++){
            printf("%.2f ", result[row][col]);
        }
        printf("\n");
    }
    
    return 0;
}