/**
 * @file    fixed-array.c
 * @brief   Implementation of integer fixed arrays
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
*/
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define BORDER "/* -------------------------------------------------------------------------- */"
#define TITLE "                                  FIXED ARRAYS"

#define ARRAY_SIZE 10

/* -------------------------------------------------------------------------- */

int main (int argc, char **argv) {

    printf("\n%s", BORDER);
    printf("\n%s", TITLE);
    printf("\n%s\n", BORDER);

    /* A 1D & 2D FIXED arrays of integers */
    int numbers1[ARRAY_SIZE];
    int numbers2[ARRAY_SIZE][ARRAY_SIZE];       /* 10x10 array */

    /* Assigning the 1D & 2D arrays  */
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers1[i] = i + 1;

        for (int j = 0; j < ARRAY_SIZE; j++) {
            numbers2[i][j] = i + j;
        }
    }

    /* Printing the 1D & 2D Arrays*/
    printf("\n1D Array Values:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("numbers[%d] = %d\n", i, numbers1[i]);
    }
    printf("\n");

    printf("2D Array Values:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE; j++) {
            printf("numbers[%d][%d] = %d\n", i, j, numbers2[i][j]);
        }
    }
    printf("\n%s\n\n", BORDER);
    return 0;
}

/* -------------------------------------------------------------------------- */