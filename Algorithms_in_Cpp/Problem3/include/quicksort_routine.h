/*
 *		quicksort_routine.h
 *	Algorithms: Programming Assignment #3
 * Implement the Quicksort algorithm with different pivot selection rules
 *
 *
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <string>

typedef unsigned long ulong;
const int num_elements = 10000;
const int MAX_NUM_LINES = num_elements;
const std::string INTEGER_INPUT_FILE = "QuickSort.txt";

void show_array(ulong* test_array, int num_elts);
/*
 * Perform the quicksort algorithm in place on the array, print final array and return the number of operations
 */
long quicksort_1(ulong* array, size_t n);
long quicksort_2(ulong* array, size_t n);
long quicksort_3(ulong* array, size_t n);
int partition(ulong* array, int left_index, int right_index);
//Choose pivots methods

void choose_first_element_as_pivot(ulong* array, size_t n);
void choose_last_element_as_pivot(ulong* array, size_t n); 
// Identify the median amongst the first, last and middle ceil(n/2) element of the array.
void choose_median_of_three(ulong* array, size_t n);

void read_input_array(std::string file_name, ulong* array, int max_lines);
#endif
