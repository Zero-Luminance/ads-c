/**
 * @file    cmp-fn-collection.h
 * @brief   A header file for a collection of pointer comparison functions
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
*/
/* -------------------------------------------------------------------------- */

#define LESS_THAN -1
#define EQUAL 0
#define GREATER_THAN 1

/* -------------------------------------------------------------------------- */

int cmp_int(void *int1, void *int2);
int cmp_double(void *double1, void *double2);

/* -------------------------------------------------------------------------- */