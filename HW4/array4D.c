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

    FILE *file;
    int sorted[4];
    file = fopen("dimensions.bin", "rb");
    fread(sorted, sizeof(sorted), 1, file);
    fclose(file);

    int i, j, k;

    /*for (i=0; i<4;i++){
        printf("%i ", sorted[i]);
    }*/

    double ****p4d;
    int space1 = sorted[0];
    int space2 = sorted[1];
    int space3 = sorted[2];
    int space4 = sorted[3];
    
    p4d = malloc(space1 * sizeof(p4d[0]));
    for(i = 0; i < space1; i++)
    {
        p4d[i] = malloc(space2 * sizeof(p4d[0][0]));
        for(j = 0; j < space2; j++)
        {
            p4d[i][j] = malloc(space3 * sizeof(p4d[0][0][0]));
            for(k = 0; k < space3; k++)
            {
                p4d[i][j][k] = malloc(space4 * sizeof(p4d[0][0][0][0]));
            }
        }
    }

    for(i = 0; i < space1; i++)
    {
        free(p4d[i]);
        for(j = 0; j < space2; j++)
        {
            free(p4d[i][j]);
            for(k = 0; k < space3; k++)
            {
                free(p4d[i][j][k]);
            }
        }
    }

    return 0;
}