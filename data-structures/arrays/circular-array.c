/**
 * @file    circular-array.c
 * @brief   A file for circular array function implementations
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
*/
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circular-array.h"

/* -------------------------------------------------------------------------- */

/**
 * @brief       Initialises the circular array
 * @param[in]   array_size      The maximum number of elements the array 
 *                              can store
 * @return      A 'heap' address to the location of the initlised 
 *              circular array
 * @note        Replace 'void' in malloc's sizeof with desired data type
*/
ca_t* 
ca_init(size_t array_size) {

    // Allocate circular structure in the 'heap'
    ca_t *new_ca;
    new_ca = malloc(sizeof(ca_t));
    assert(new_ca != NULL);

    // Allocate the array according to the number of elements to be stored
    new_ca->array = malloc(sizeof(void)*array_size);
    assert(new_ca->array != NULL);

    // Initialise counters to track array size
    new_ca->logical_size = 0;
    new_ca->physical_size = array_size;
    return new_ca;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       Adds an item at the 'tail' (i.e. END) of the circular array
 * @param[out]  ca      A pointer to the circular array structure
 * @param[in]   item    The new item to be inserted to the array; replace 
 *                      '*void' with desired data type
 * @note        Replace function return type 'void' to desired data type
*/
void 
ca_insert_tail(ca_t *ca, void *item) {

    // EXCEPTION: Need to expand physical array
    if (ca->logical_size == ca->physical_size) {
        ca->physical_size = GEOMETRIC_FACTOR*ca->physical_size;
        ca->array = realloc(ca->array, ca->physical_size);
    }
    ca->array/*[ca->logical_size++]*/ = item;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       Access the elements stored in the circular array
 * @param[in]   ca      A pointer to the circular array structure     
 * @param[in]   index   The desired 'index' to access the circular array
 * @return      The value stored at the 'index' of the circular array
 * @note        Replace function return type 'void' to desired data type
*/
void
ca_get_item(ca_t *ca, int index) {
    return ca->array[index%ca->physical_size];
}

/* -------------------------------------------------------------------------- */