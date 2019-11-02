
/*
 * 			~~~~ main_count_inversion.cpp ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 *	Divide and Counquer, Sorting and Searching and Randomized Algorithms	
 *	Assignment 2: Computing the number of inversions in a list
 *	Main code to test the number of inversions
 * Harold Nikoue
 */

#include "../include/count_inversion.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(){
//	// TEST 1
//	//
//	int num_elts = 6;
//	ull test_array[num_elts] = {1, 3, 5, 2, 4, 6};
//	long num_inversions = count_array(test_array, num_elts);
//	show_results(test_array, num_elts, num_inversions);
//	cout << endl;
//	// TEST 2
//	//
//	num_elts = 7;
//	ull test_array2[num_elts] = {1, 3, 4, 7, 2, 5, 6};
//	num_inversions = count_array(test_array2, num_elts);
//	show_results(test_array2, num_elts, num_inversions);
	// Actual question
	// 1. read file and create an array of numbers
	int num_lines_read = NUM_TOTAL_ELTS;
//	int num_lines_read = 100;
	ull input_array[num_lines_read];
       	read_input_array(INTEGER_ARRAY_FILENAME, input_array, num_lines_read);
//	show_array(input_array, NUM_TOTAL_ELTS);
	// 2. cal count array
	long num_inversions = count_array(&input_array[0], num_lines_read);
	// 3. show the results
	show_results(input_array, num_lines_read, num_inversions);
}
