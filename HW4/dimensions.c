/*
    Zack Humphries
    COMP 526 - Fall 2022
    Dr. Miguel Dumett
    Assignment 4
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {

    char pqrs[4] = "pqrs";
    int sorted[4];

    int i,j, a, number;

    printf("Enter the 4 dimensions:\n");

    for (i=0; i<4; i++){
        printf("%c: ", pqrs[i]);
        scanf("%d", &number);
        if (number <0) {
            printf("Error: Must All Be Positive Integers");
            exit(1);
        }
        sorted[i] = number;
    }


    FILE *fp;

    fp = fopen("dimensions.bin", "wb");
    fwrite(sorted, sizeof(sorted), 1, fp);
    fclose(fp);

    /*FILE *file;
    int sorted1[4];
    file = fopen("dimensions.bin", "rb");
    fread(sorted1, sizeof(sorted1), 1, file);
    fclose(file);

    for (i=0; i<4;i++){
        printf("%i ", sorted1[i]);
    }*/

    return 0;
}