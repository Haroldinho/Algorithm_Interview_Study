
/*
 * 			~~~~ count_inversion.h ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 *	Divide and Counquer, Sorting and Searching and Randomized Algorithms	
 *	Assignment 2: Computing the number of inversions in a list
 * Harold Nikoue
 */

#ifndef _COUNT_INVERSION_H
#define _COUNT_INVERSION_H

#include <string>
typedef unsigned long ull;
const int NUM_TOTAL_ELTS = 100000;

const std::string INTEGER_ARRAY_FILENAME = "IntegerArray.txt";
void show_array(ull* test_array, int num_elts);
long count_array(ull*, int num_elts);
long count_split_array(ull*, int num_elts);
void read_input_array(std::string, ull* array, int);
void show_results(ull* test_array, int num_elts, long num_inversions);

#endif
