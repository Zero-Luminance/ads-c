/**
 * @file    circular-array.h
 * @brief   A HEADER file for circular array implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
*/
/* -------------------------------------------------------------------------- */

#define GEOMETRIC_FACTOR 2

/* -------------------------------------------------------------------------- */

/**
 * @brief   CIRCULAR ARRAY STRUCTURE
 * @note    Replace 'void' type of *array to desired data type 
*/
typedef struct ca_t {
    void    *array;      
    int     logical_size;    /* The number of recorded items */
    int     physical_size;   /* The size of the circular array */
} ca_t;

/* -------------------------------------------------------------------------- */

/**
 * @brief   CIRCULAR ARRAY OPERATIONS
 * @note    Replace 'void' ca_get_item's function return type & ca_insert_tail
 *          parameter *item with desired data type
*/
ca_t *ca_init(size_t array_size);
void ca_insert_tail(ca_t *ca, void *item);
void ca_get_item(ca_t *ca, int index);

/* -------------------------------------------------------------------------- */