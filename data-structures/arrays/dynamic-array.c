/**
 * @file    dynamic-array.c
 * @brief   Implementation of a dynamic integer array that prints a desired
 *          amount of fibonacci numbers
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
*/
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define BORDER "/* -------------------------------------------------------------------------- */"
#define TITLE "                               DYNAMIC ARRAYS"

/* -------------------------------------------------------------------------- */

int main(int argc, char **argv) {

    printf("\n%s", BORDER);
    printf("\n%s", TITLE);
    printf("\n%s\n", BORDER);

    /* ----------------------------------------------------------------- */

    int n, limit, use, i, j;
    unsigned int *A;
    
    // Accepting input
    printf("\nEnter amount of Fibonacci numbers desired: ");
    if (scanf("%d", &n) != 1) {
        printf("\n\nERROR: Invalid Input");
        exit(EXIT_FAILURE);
    }

    /* ----------------------------------------------------------------- */
    // ALLOCATING DYNAMIC MEMORY SEGMENTS
    if (n > (limit = 47)) {
        if ((A = (unsigned int *)malloc(limit*sizeof(unsigned int))) == NULL) {
            printf("\n\nERROR: Failed to allocated requested memory size");
            exit(EXIT_FAILURE);
        }
        use = limit;
    } else {
        if ((A = (unsigned int *)malloc(n*sizeof(unsigned int))) == NULL) {
            printf("\n\nERROR: Failed to allocated requested memory size");
            exit(EXIT_FAILURE);
        }
        use = n;
    }
    /* ----------------------------------------------------------------- */

    // Calculating Fibonacci numbers
    for (i = 0; i < use; i++) {
        if (i-2< 0) {
            A[i] = i;
        } else {
            A[i] = A[i-1] + A[i-2];
        }
    }
    
    // Calculating unsigned integer overflow numbers
    if (n > limit) {
        printf("ERROR: unsigned integer overflow detected!\n");

        /* --------------------------------------------------------- */
        // EXPANDING ARRAY SIZE TO ACCOMMODATE OVERFLOW VALUES
        if ((A = realloc(A, n*sizeof(unsigned int))) == NULL) {
            printf("ERROR: Dynamic memory reallocation unsuccessful!");
            exit(EXIT_FAILURE);
        }
        /* --------------------------------------------------------- */

        for (; i < n; i++) {
            A[i] = A[i-1] + A[i-2];
        }
    }

    // Displaying Fibonacci numbers
    printf("\nFibonacci Sequence:");
    for (i = 0; i < use; i++) {
        printf("\nFibonacci(%02d) = %d", i+1, A[i]);
    }

    // Displaying unsigned integer overflower numbers
    if (n > limit) {
        printf("\n\nDYNAMIC MEMORY REALLOCATION SUCCESSFUL!");
        printf("\nOverflow Numbers:");
        for (j = 0; i < n; i++, j++) {
            printf("\nOverflow(%02d) = %d", j+1, A[i]);
        }
    }

    /* ----------------------------------------------------------------- */

    printf("\n\n%s\n\n", BORDER);
    return 0;
}

/* -------------------------------------------------------------------------- */