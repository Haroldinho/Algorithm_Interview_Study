/*
 *		main_quicksort.cpp
 *	Algorithms: Programming Assignment #3
 * Calls the Quicksort algorithms with different pivot selection rules
 * 
 *
 */

#include "../include/quicksort_routine.h"
#include <iostream>
using namespace std;
/*
 * 0. Read the input file
 * 1. Call quicksort on the array with the appopriate size
 * 2. Show the sorted array on screen or the first 100 elements
 * 4. Return the number of comparisons
 */
void main_1(){
	long num_comparisons ;
	ulong array_a[MAX_NUM_LINES];
	read_input_array(INTEGER_INPUT_FILE, array_a, MAX_NUM_LINES);

	num_comparisons = quicksort_1(array_a, MAX_NUM_LINES);
	show_array(array_a, 100);
	cout << endl;

	cout << "Sorted array using Quicksort 1 and first element as a pivot for a total of " << num_comparisons << " comparisons." << endl;

}

void main_2(){
	long num_comparisons ;
	ulong array_a[MAX_NUM_LINES];
	read_input_array(INTEGER_INPUT_FILE, array_a, MAX_NUM_LINES);

	num_comparisons = quicksort_2(array_a, MAX_NUM_LINES);
	
	show_array(array_a, 100);
	cout << endl;

	cout << "Sorted array using Quicksort 2 and last element as a pivot for a total of " << num_comparisons << " comparisons." << endl;

}
void main_3(){
	long num_comparisons ;
	ulong array_a[MAX_NUM_LINES];
	read_input_array(INTEGER_INPUT_FILE, array_a, MAX_NUM_LINES);

	num_comparisons = quicksort_3(array_a, MAX_NUM_LINES);
	
	show_array(array_a, 100);
	cout << endl;

	cout << "Sorted array using Quicksort 3 and median of three elements of the array for a total of " << num_comparisons << " comparisons." << endl;

}

int main(){
	main_1();
	main_2();
	main_3();
}
