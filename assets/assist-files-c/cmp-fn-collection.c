/**
 * @file    cmp-fn-collection.c
 * @brief   A compilation of pointer comparison functions that MIGHT be used
 *          in conjunction with the 'C' files found in the 'algorithms' &
 *          'data-structures' directories
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @return      -1 if 1st variable is LESS than 2nd variable
 *               0  if 1st & 2nd variable are EQUAL
 *               1  if 1st variable is GREATER than 2nd variable
*/
/* -------------------------------------------------------------------------- */

#include "cmp-fn-collection.h"

/* -------------------------------------------------------------------------- */

int
cmp_int(void *int1, void *int2) {

    // Type casting from 'void' to 'int'
    int *v1 = int1, *v2 = int2;
    if (*v1 < *v2) return LESS_THAN;
    if (*v1 > *v2) return GREATER_THAN;
    return EQUAL;
}

/* -------------------------------------------------------------------------- */

int 
cmp_double(void *double1, void *double2) {
    // Type casting from 'void' to 'int'
    double *v1 = double1, *v2 = double2;
    if (*v1 < *v2) return LESS_THAN;
    if (*v1 > *v2) return GREATER_THAN;
    return EQUAL;
}

/* -------------------------------------------------------------------------- */