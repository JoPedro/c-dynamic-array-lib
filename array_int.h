#include <stddef.h>

/**
 * ANSI C dinamic array of int values library
 *
 * Author:
 * Date:
 *
*/
#ifndef _ARRAY_INT_H_
#define _ARRAY_INT_H_
/**
 * Type: array_int
 * Description: a array_int is a pointer to a type that
 * stores the dynamic array data.
 *
*/
typedef struct array_int array_int;

/**
 * Function: array_int* array_create(size_t capacity);
 *
 * Description: Creates and initializes a dynamic array list of integers passing the capacity as the argument.
 *
 * Return: A pointer to array_int type, the dynamic array implementation
 *
*/
array_int* array_create(size_t capacity);

/**
 * Function: int array_get(array_int *array, int index);
 *
 * Description: Gets the element at index 'index'.
 *
 * Return: The element located at index i.
 * The value is undeterminated if index is not in the range [0..size−1]
 *
*/
int array_get(array_int *array, int index);

/**
 * Function: size_t array_push_back(array_int *array, int i, size_t increase);
 *
 * Description: Add integer value 'i' to the end of the 'array' dynamic array.
 * If the capacity isn't enough, increase it by the parameter 'increase'.
 *
 * Return: The number of elements stored in 'array' AFTER inserting 'i'.
 *
*/
size_t array_push_back(array_int *array, int i, size_t increase);

/**
 * Function: size_t array_pop_back(array_int *array);
 *
 * Description: Removes the last element of the dynamic array
 * referenced (pointed) by 'array'.
 *
 * Return: The number of elements after deletion.
 *
*/
size_t array_pop_back(array_int *array);

/**
 * Function: size_t array_size(array_int *array);
 *
 * Description: Computes the number of int elements stored in 'array'.
 *
 * Return: The number of integer values stored in 'array'.
 *
*/
size_t array_size(array_int *array);

/**
 * Function: int array_find(array_int *array, int element);
 *
 * Description: Gets the index of element 'element'.
 *
 * Return: The index of element 'element' if element is in the range [0..size−1].
 *
*/
int array_find(array_int *array, int element);

/**
 * Function: int array_insert_at(array_int *array, int index, int value);
 *
 * Description: Inserts int value 'value' at index 'index'. 'index' must
 * be a valid index, between 0 and 'array_size'−1.
 *
 * Return: the value index, if insertion ok or −1 if the insertion could
 * not be done.
 *
*/
int array_insert_at(array_int *array, int index, int value);

/**
 * Function: array_remove_from(array_int *array, int index);
 *
 * Description: Removes the value at index 'index'. 'index' must
 * be a valid index, between 0 and 'array_size'−1.
 *
 * Return: The size of the new array_int.
 *
*/
int array_remove_from(array_int *array, int index);

/**
 * Function: size_t array_capacity(array_int *array);
 *
 * Description: Computes the array_int array capacity.
 *
 * Return: The capicity of the 'array' array_int.
 *
*/
size_t array_capacity(array_int *array);

/**
 * Function: size_t array_percent_occuped(array_int *array);
 *
 * Description: Check the array_int 'array' occupation, in percent.
 *
 * Return: A double, from 0 to 1 with the occupation rate of 'array'.
 *
*/
double array_percent_occuped(array_int *array);

/**
 * Function: void array_destroy(array_int *array);
 *
 * Description: Relese memory used by the 'array' reference.
 * Invalidate memory area too.
 *
 */
void array_destroy(array_int *array);

#endif